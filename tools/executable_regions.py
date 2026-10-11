#!/usr/bin/env python3
"""Walk native ARM and Thumb code, and report every gap and unresolved transfer."""

import argparse
from collections import deque
from pathlib import Path
import struct

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_CC_AL, ARM_CC_INVALID, ARM_INS_B, ARM_INS_BL, ARM_OP_IMM, ARM_OP_MEM, ARM_OP_REG

if __package__:
    from .indirect_calls import CODE_END, CODE_START, TRAMPOLINES, thumb_call_candidates
    from .verify import ARM_CALLS, BASE, REGIONS, read_rom
    from .runtime_trace import load_runtime_seeds
else:
    from indirect_calls import CODE_END, CODE_START, TRAMPOLINES, thumb_call_candidates
    from verify import ARM_CALLS, BASE, REGIONS, read_rom
    from runtime_trace import load_runtime_seeds


def ranges(addresses):
    result = []
    for address in sorted(addresses):
        if result and result[-1][1] == address:
            result[-1] = (result[-1][0], address + 1)
        else:
            result.append((address, address + 1))
    return result


def outside_native_entries(rom, boundary=CODE_END):
    candidates = {}
    for offset in range(0, len(rom) - 3, 4):
        pointer = struct.unpack_from('<I', rom, offset)[0]
        target = pointer & ~1
        if not boundary <= target <= BASE + len(rom) - 4:
            continue
        start = target - BASE
        if pointer & 1:
            first = struct.unpack_from('<H', rom, start)[0]
            executable = first & 0xFF00 == 0xB500 or first == 0x4770
            mode = 'Thumb'
        else:
            if target & 3:
                continue
            first = struct.unpack_from('<I', rom, start)[0]
            executable = first & 0xFFFF4000 == 0xE92D4000 or first in (0xE52DE004, 0xE12FFF1E)
            mode = 'ARM'
        if executable:
            candidates.setdefault((target, mode), set()).add(BASE + offset)
    return candidates


class ExecutableMap:
    def __init__(self, rom, low=BASE + 0xC0, high=CODE_END):
        self.rom, self.low, self.high = rom, low, high
        self.decoders = {mode: Cs(CS_ARCH_ARM, flag) for mode, flag in
                         (('ARM', CS_MODE_ARM), ('Thumb', CS_MODE_THUMB))}
        for decoder in self.decoders.values():
            decoder.detail = True
        self.instructions = {}
        self.literals = set()
        self.tables = set()
        self.edges = set()
        self.unresolved = set()
        self.entries = set()
        self.states = {}
        self.copies = set()
        self.runtime_correspondences = set()
        self.blocked = set()
        self.literal_references = {}
        self.returns = set()
        self.interiors = set()

    def source(self, address):
        for source, destination, length in sorted(self.copies | self.runtime_correspondences):
            if destination <= address < destination + length:
                return source + address - destination
        return address

    def read(self, address, width=4):
        offset = self.source(address) - BASE
        if 0 <= offset <= len(self.rom) - width:
            return int.from_bytes(self.rom[offset:offset + width], 'little')
        return None

    def decode(self, address, mode):
        decoder = self.decoders[mode]
        offset = self.source(address) - BASE
        if not 0 <= offset < len(self.rom):
            return None
        instruction = next(decoder.disasm(self.rom[offset:offset + 4], address, 1), None)
        if instruction is None:
            return None
        if mode == 'Thumb' and (instruction.size == 4 and instruction.mnemonic != 'bl' or
                                instruction.mnemonic in ('blx', 'cbz', 'cbnz', 'it', 'bkpt', 'uxtb', 'uxth', 'rev', 'revsh')):
            return None
        if mode == 'ARM' and instruction.mnemonic in ('blx', 'clz', 'bkpt', 'movw', 'movt', 'udf'):
            return None
        return instruction

    @staticmethod
    def register(instruction, identifier):
        name = instruction.reg_name(identifier)
        aliases = {'sb': 9, 'sl': 10, 'fp': 11, 'ip': 12, 'sp': 13, 'lr': 14, 'pc': 15}
        return aliases[name] if name in aliases else int(name[1:])

    def switch(self, address, mode, entry):
        if mode != 'Thumb':
            return set()
        # GCC places an aligned table pointer immediately before MOV-PC dispatch.
        for previous in range(address - 2, max(entry - 1, address - 24), -2):
            instruction = self.instructions.get((previous, mode))
            if instruction is None or instruction.mnemonic != 'ldr':
                continue
            operands = instruction.operands
            if operands[1].type != ARM_OP_MEM or instruction.reg_name(operands[1].mem.base) != 'pc':
                continue
            literal = ((previous + 4) & ~3) + operands[1].mem.disp
            base = self.read(literal)
            if base is None or base & 3 or not entry <= base < self.high:
                continue
            words = []
            for location in range(base, min(base + 1024, self.high), 4):
                target = self.read(location)
                if target is None or target & 1 or not entry <= target < self.high or not self.decode(target, mode):
                    break
                words.append((location, target))
            if words:
                self.tables.update(byte for location, _ in words for byte in range(location, location + 4))
                return {target for _, target in words}
        return set()

    def halfword_loop_copy(self, branch, registers):
        if branch.mnemonic != 'bne' or branch.operands[0].imm != branch.address - 16:
            return None
        body = [self.decode(address, 'Thumb') for address in range(branch.address - 16, branch.address + 2, 2)]
        if any(instruction is None for instruction in body) or tuple(instruction.mnemonic for instruction in body) != (
                'ldrh', 'strh', 'adds', 'adds', 'subs', 'lsls', 'lsrs', 'cmp', 'bne'):
            return None
        load, store = body[:2]
        if any(instruction.operands[1].type != ARM_OP_MEM or instruction.operands[1].mem.index or
               instruction.operands[1].mem.disp for instruction in (load, store)):
            return None
        data = self.register(load, load.operands[0].reg)
        source = self.register(load, load.operands[1].mem.base)
        target = self.register(store, store.operands[1].mem.base)
        count = self.register(body[6], body[6].operands[0].reg)
        if len({data, source, target, count}) != 4 or self.register(store, store.operands[0].reg) != data:
            return None
        expected = ((source, 2), (target, 2), (data, count, 1),
                    (data, data, 16), (count, data, 16), (count, 0))
        for instruction, operands in zip(body[2:8], expected):
            actual = tuple(self.register(instruction, operand.reg) if operand.type == ARM_OP_REG else
                           operand.imm if operand.type == ARM_OP_IMM else None
                           for operand in instruction.operands)
            if actual != operands:
                return None
        source, target, count = registers[source], registers[target], registers[count]
        if any(value is None for value in (source, target, count)) or not 0 < count <= 65535:
            return None
        length = count * 2
        if source % 2 or target % 2 or not self.low <= source < source + length <= self.high:
            return None
        if not (0x02000000 <= target < target + length <= 0x02040000 or
                0x03000000 <= target < target + length <= 0x03008000):
            return None
        return source, target, length

    def walk(self, entry, mode='Thumb', budget=1000000):
        self.entries.add((entry, mode))
        initial = [None] * 16
        initial[13], initial[14] = 0x10000000, -1
        queue = deque([(entry, mode, tuple(initial), ())])
        steps = 0
        while queue and steps < budget:
            address, current_mode, incoming, incoming_stack = queue.popleft()
            if not self.low <= self.source(address) < self.high:
                self.unresolved.add((address, current_mode, 'target outside native span'))
                continue
            if address % (4 if current_mode == 'ARM' else 2):
                self.unresolved.add((address, current_mode, 'unaligned target'))
                continue
            if self.source(address) in self.blocked:
                continue
            key = address, current_mode
            previous = self.states.get(key)
            registers = tuple(a if a == b else None for a, b in zip(previous[0], incoming)) if previous else incoming
            stack = dict(incoming_stack)
            if previous:
                stack = {location: value if stack.get(location) == value else None
                         for location, value in previous[1] if location in stack}
            state = registers, tuple(sorted(stack.items()))
            if previous == state:
                continue
            self.states[key] = state
            steps += 1
            instruction = self.decode(address, current_mode)
            if instruction is None:
                self.unresolved.add((address, current_mode, 'invalid or unsupported instruction'))
                continue
            self.instructions[key] = instruction
            self.interiors.update(range(self.source(address) + 1, self.source(address) + instruction.size))
            operands = instruction.operands
            registers = list(registers)
            registers[15] = address + (8 if current_mode == 'ARM' else 4)
            next_address = address + instruction.size
            conditional = current_mode == 'ARM' and instruction.cc not in (ARM_CC_AL, ARM_CC_INVALID)

            def value(operand):
                if operand.type == ARM_OP_IMM:
                    return operand.imm
                if operand.type == ARM_OP_REG:
                    result = registers[self.register(instruction, operand.reg)]
                    if result is not None and operand.shift.type:
                        return None
                    return result
                return None

            def destination(target, target_mode, kind):
                self.edges.add((address, current_mode, target, target_mode, kind))
                if self.low <= self.source(target) < self.high:
                    if kind == 'call':
                        callee = list(registers)
                        callee[13], callee[14] = 0x10000000, -1
                        queue.append((target, target_mode, tuple(callee), ()))
                    else:
                        queue.append((target, target_mode, tuple(registers), tuple(sorted(stack.items()))))
                    if kind == 'call':
                        self.entries.add((target, target_mode))
                else:
                    self.unresolved.add((address, current_mode, f'{kind} outside native span: 0x{target:08X}'))

            mnemonic = instruction.mnemonic
            if conditional:
                queue.append((next_address, current_mode, incoming, incoming_stack))
            if instruction.id == ARM_INS_BL:
                if operands[0].imm in (BASE + 0x5D270, BASE + 0x5D26C):
                    source, target, flags = registers[:3]
                    if source is not None and target is not None and flags is not None and not flags & 0x01000000:
                        width = 4 if flags & 0x04000000 or operands[0].imm == BASE + 0x5D26C else 2
                        count = flags & 0x1FFFFF
                        if operands[0].imm == BASE + 0x5D26C:
                            count = (count + 7) & ~7
                        if self.low <= source < self.high and 0x02000000 <= target < 0x03008000:
                            # Original BIOS word copies use ARM7 block transfers, which align both addresses.
                            if width == 4 and count:
                                self.copies.add((source & ~3, target & ~3, count * width))
                            elif source % width or target % width:
                                self.unresolved.add((address, current_mode, 'unaligned halfword BIOS copy'))
                            elif count:
                                self.copies.add((source, target, count * width))
                long_branch = self.source(next_address) in self.blocked
                destination(operands[0].imm, current_mode, 'long branch' if long_branch else 'call')
                if long_branch:
                    continue
                for index in (0, 1, 2, 3, 12, 14):
                    registers[index] = None
                if self.source(next_address) in self.blocked:
                    continue
            elif instruction.id == ARM_INS_B:
                if current_mode == 'Thumb':
                    copy = self.halfword_loop_copy(instruction, registers)
                    if copy is not None:
                        self.copies.add(copy)
                destination(operands[0].imm, current_mode, 'branch')
                if mnemonic != 'b' and current_mode == 'Thumb':
                    queue.append((next_address, current_mode, tuple(registers), tuple(sorted(stack.items()))))
                continue
            elif mnemonic == 'svc':
                for index in (0, 1, 2, 3, 12):
                    registers[index] = None
            elif mnemonic.startswith('bx'):
                selected = self.register(instruction, operands[0].reg)
                target = registers[selected]
                continuation = registers[14]
                call = continuation is not None and continuation & ~1 == next_address
                if target == -1:
                    self.returns.add((address, current_mode))
                elif target is not None and 0x0FFF0000 <= target <= 0x10000000:
                    self.unresolved.add((address, current_mode, 'stack BX'))
                elif target is not None:
                    destination(target & ~1, 'Thumb' if target & 1 else 'ARM', 'call' if call else 'exchange')
                else:
                    self.unresolved.add((address, current_mode, 'register BX'))
                if call:
                    for index in (0, 1, 2, 3, 12, 14):
                        registers[index] = None
                    queue.append((next_address, current_mode, tuple(registers), tuple(sorted(stack.items()))))
                continue
            elif mnemonic.startswith('mov') and operands and self.register(instruction, operands[0].reg) == 15:
                selected = self.register(instruction, operands[1].reg)
                if registers[selected] == -1:
                    self.returns.add((address, current_mode))
                else:
                    labels = self.switch(address, current_mode, entry)
                    for target in labels:
                        destination(target, current_mode, 'switch')
                    if not labels:
                        self.unresolved.add((address, current_mode, 'computed PC'))
                continue
            elif mnemonic.startswith('pop') or (mnemonic.startswith('ldm') and operands[0].type == ARM_OP_REG
                                               and self.register(instruction, operands[0].reg) == 13):
                selected = operands if mnemonic.startswith('pop') else operands[1:]
                pointer = registers[13]
                for index, operand in enumerate(selected):
                    registers[self.register(instruction, operand.reg)] = stack.get(pointer + index * 4) if pointer is not None else None
                if pointer is not None:
                    registers[13] = pointer + len(selected) * 4
                if any(self.register(instruction, op.reg) == 15 for op in selected):
                    if registers[15] == -1:
                        self.returns.add((address, current_mode))
                    elif registers[15] is not None:
                        destination(registers[15] & ~1, current_mode, 'stack PC')
                    else:
                        self.unresolved.add((address, current_mode, 'stack PC'))
                    continue
            elif mnemonic.startswith('push') or (mnemonic.startswith('stmdb') and operands[0].type == ARM_OP_REG
                                                and self.register(instruction, operands[0].reg) == 13):
                selected = operands if mnemonic.startswith('push') else operands[1:]
                pointer = registers[13]
                if pointer is not None:
                    pointer -= len(selected) * 4
                    for index, operand in enumerate(selected):
                        register = self.register(instruction, operand.reg)
                        stack[pointer + index * 4] = address + 12 if register == 15 and current_mode == 'ARM' else registers[register]
                    registers[13] = pointer
            elif mnemonic.startswith('ldm'):
                _, writes = instruction.regs_access()
                for identifier in writes:
                    if instruction.reg_name(identifier) != 'cpsr':
                        registers[self.register(instruction, identifier)] = None
            elif mnemonic.startswith('ldr') and operands[1].type == ARM_OP_MEM:
                memory = operands[1].mem
                base = registers[self.register(instruction, memory.base)]
                if current_mode == 'Thumb' and instruction.reg_name(memory.base) == 'pc':
                    base &= ~3
                index = registers[self.register(instruction, memory.index)] if memory.index else 0
                location = base + index + memory.disp if base is not None and index is not None else None
                width = 1 if mnemonic.startswith(('ldrb', 'ldrsb')) else 2 if mnemonic.startswith(('ldrh', 'ldrsh')) else 4
                number = (stack.get(location) if location in stack else self.read(location, width)) if location is not None else None
                if number is not None and mnemonic.startswith(('ldrsb', 'ldrsh')) and number & (1 << (width * 8 - 1)):
                    number = (number - (1 << (width * 8))) & 0xFFFFFFFF
                selected = self.register(instruction, operands[0].reg)
                registers[selected] = number
                if number is not None and instruction.reg_name(memory.base) == 'pc':
                    location = self.source(location)
                    self.literals.update(range(location, location + width))
                    self.literal_references.setdefault(self.source(address), set()).update(range(location, location + width))
                if selected == 15:
                    if number == -1:
                        self.returns.add((address, current_mode))
                    elif number is not None:
                        destination(number & ~1, current_mode, 'computed PC')
                    else:
                        self.unresolved.add((address, current_mode, 'load PC'))
                    continue
            elif mnemonic.startswith('mov') and operands[1].type in (ARM_OP_REG, ARM_OP_IMM):
                registers[self.register(instruction, operands[0].reg)] = value(operands[1])
            elif mnemonic == 'adr':
                registers[self.register(instruction, operands[0].reg)] = ((address + 4) & ~3) + operands[1].imm
            elif mnemonic in ('lsls', 'lsrs', 'asrs', 'ands', 'orrs', 'eors', 'rsbs'):
                selected = self.register(instruction, operands[0].reg)
                a = value(operands[1]) if len(operands) == 3 else registers[selected]
                b = value(operands[-1])
                if a is not None and b is not None:
                    if mnemonic == 'rsbs':
                        number = b - a
                    elif mnemonic == 'ands':
                        number = a & b
                    elif mnemonic == 'orrs':
                        number = a | b
                    elif mnemonic == 'eors':
                        number = a ^ b
                    else:
                        if operands[-1].type == ARM_OP_REG:
                            b &= 255
                        if mnemonic == 'asrs':
                            a = a - (1 << 32) if a & 0x80000000 else a
                            number = a >> min(b, 32)
                        else:
                            number = 0 if b >= 32 else a << b if mnemonic == 'lsls' else a >> b
                    registers[selected] = number & 0xFFFFFFFF
                else:
                    registers[selected] = None
            elif mnemonic.startswith(('add', 'sub')) and operands[0].type == ARM_OP_REG:
                selected = self.register(instruction, operands[0].reg)
                a = value(operands[1]) if len(operands) == 3 else registers[selected]
                b = value(operands[-1])
                registers[selected] = ((a + b if mnemonic.startswith('add') else a - b) & 0xFFFFFFFF
                                       if a is not None and b is not None else None)
                if selected == 15:
                    if registers[selected] is not None:
                        destination(registers[selected] & ~1, current_mode, 'computed PC')
                    else:
                        self.unresolved.add((address, current_mode, 'arithmetic PC'))
                    continue
            elif mnemonic.startswith('str') and operands[1].type == ARM_OP_MEM:
                memory = operands[1].mem
                base = registers[self.register(instruction, memory.base)]
                index = registers[self.register(instruction, memory.index)] if memory.index else 0
                location = base + index + memory.disp if base is not None and index is not None else None
                if location is not None and (location in stack or self.register(instruction, memory.base) == 13):
                    stack[location] = value(operands[0]) if mnemonic in ('str', 'strne', 'streq') else None
            elif mnemonic.startswith(('cmp', 'tst', 'msr')):
                pass
            else:
                _, writes = instruction.regs_access()
                for identifier in writes:
                    if instruction.reg_name(identifier) != 'cpsr':
                        registers[self.register(instruction, identifier)] = None
            queue.append((next_address, current_mode, tuple(registers), tuple(sorted(stack.items()))))
        if queue:
            self.unresolved.add((entry, mode, 'analysis budget reached'))

    def code_bytes(self):
        return {byte for (address, _), instruction in self.instructions.items()
                for byte in range(self.source(address), self.source(address) + instruction.size)}

    def candidate_entries(self):
        entries = {(BASE + start, 'ARM' if name in ARM_CALLS else 'Thumb') for name, start, _, _ in REGIONS
                   if self.low <= BASE + start < self.high}
        entries.add((BASE + 0xFC, 'ARM'))
        entries.update((entry, 'Thumb') for entry in TRAMPOLINES if self.low <= entry < self.high)
        entries.update((target, 'Thumb') for _, target in thumb_call_candidates(self.rom)
                       if self.low <= target < self.high)
        for address in range(CODE_START, self.high, 2):
            if self.read(address, 2) & 0xFF00 == 0xB500:
                entries.add((address, 'Thumb'))
        for offset in range(0, len(self.rom) - 3, 4):
            pointer = struct.unpack_from('<I', self.rom, offset)[0]
            target = pointer & ~1
            if CODE_START <= target < self.high and pointer & 1:
                entries.add((target, 'Thumb'))
        return entries

    def finish_gaps(self):
        fragments = set()
        padding = set()
        while True:
            gaps = set(range(self.low, self.high)) - self.code_bytes() - self.literals - self.tables - padding
            progress = False
            for low, high in ranges(gaps):
                cursor = low
                if cursor % 4 == 2 and self.read(cursor, 2) in (0, 0x46C0):
                    padding.update(range(cursor, cursor + 2))
                    cursor += 2
                    progress = True
                if cursor >= high:
                    continue
                mode = 'ARM' if cursor < CODE_START else 'Thumb'
                probe = ExecutableMap(self.rom, cursor, high)
                probe.walk(cursor, mode)
                code = probe.code_bytes()
                conflict = code & (self.literals | self.tables | self.blocked)
                conflict |= probe.literals & self.code_bytes()
                known_arm = any(name in ARM_CALLS and BASE + start <= cursor < BASE + end
                                for name, start, end, _ in REGIONS)
                if code and not conflict and (not probe.unresolved or known_arm):
                    self.instructions.update(probe.instructions)
                    self.literals.update(probe.literals)
                    self.tables.update(probe.tables)
                    self.edges.update(probe.edges)
                    self.unresolved.update(probe.unresolved)
                    self.returns.update(probe.returns)
                    self.entries.update(probe.entries)
                    fragments.add((cursor, mode))
                    progress = True
            if not progress:
                return fragments, padding


def scan_native(rom, runtime=None):
    result = ExecutableMap(rom, low=BASE)
    header = set(range(BASE + 4, BASE + 0xC0))
    result.blocked = header
    entries = result.candidate_entries()
    blocks = set()
    if runtime is not None:
        result.runtime_correspondences = runtime.correspondences.copy()
        entries.update(runtime.entries)
        blocks.update(runtime.block_entries)
    for entry, mode in sorted(entries | blocks):
        if result.source(entry) not in result.literals | result.tables | result.interiors:
            result.walk(entry, mode)
    blocked = set(result.tables) | header
    for instruction, locations in sorted(result.literal_references.items()):
        if instruction not in blocked:
            blocked.update(locations)
    clean = ExecutableMap(result.rom, low=BASE)
    clean.blocked = blocked
    clean.copies = result.copies.copy()
    clean.runtime_correspondences = result.runtime_correspondences.copy()
    for entry, mode in sorted(entries | blocks):
        if clean.source(entry) not in blocked | clean.interiors:
            clean.walk(entry, mode)
    result = clean
    fragments, padding = result.finish_gaps()
    result.literals.update(header)
    return result, entries, fragments, padding


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=Path('0259 - Zoids Saga (J)(Independent).gba'))
    parser.add_argument('--trace-db', type=Path, help='Use deduplicated runtime targets as additional roots.')
    parser.add_argument('--minimum-jump', type=int, default=128)
    args = parser.parse_args()
    if args.minimum_jump < 0:
        parser.error('The minimum jump must be nonnegative.')
    rom = read_rom(args.rom)
    runtime = load_runtime_seeds(args.trace_db, rom, args.minimum_jump) if args.trace_db else None
    result, entries, fragments, padding = scan_native(rom, runtime)
    if runtime is not None:
        print(f'Runtime entry candidates: {len(runtime.entries)}; block candidates: {len(runtime.block_entries)}')
        print(f'Runtime RAM byte correspondences: {len(runtime.correspondences)}')
        print(f'Ambiguous RAM targets: {len(runtime.ambiguous_ram)}; unmapped RAM targets: {len(runtime.unmapped_ram)}')
    print(f'ROM-to-RAM copies: {len(result.copies)}')
    for source, destination, length in sorted(result.copies):
        print(f'  0x{source:08X} -> 0x{destination:08X}: {length} bytes; copy destination is not necessarily code')
    code = result.code_bytes()
    data = result.literals | result.tables
    gaps = set(range(result.low, result.high)) - code - data - padding
    print(f'Native span: 0x{result.low:08X}..0x{result.high:08X}')
    print(f'Instruction bytes: {len(code)}; data bytes: {len(data)}; overlap bytes: {len(code & data)}')
    print(f'ARM instructions: {sum(mode == "ARM" for _, mode in result.instructions)}; Thumb instructions: {sum(mode == "Thumb" for _, mode in result.instructions)}')
    print(f'Candidate entries: {len(entries)}; traversed entries: {len(result.entries)}')
    print(f'Additional code fragments: {len(fragments)}; alignment bytes: {len(padding)}')
    print(f'Unclassified bytes: {len(gaps)} in {len(ranges(gaps))} ranges')
    for low, high in ranges(gaps):
        content = result.rom[low - BASE:high - BASE]
        print(f'  0x{low:08X}..0x{high:08X}: {high - low} bytes; {"zero" if not any(content) else "nonzero"}')
    print(f'Unresolved transfers: {len(result.unresolved)}')
    for address, mode, reason in sorted(result.unresolved):
        print(f'  {mode} 0x{address:08X}: {reason}')
    print('Pointer and prologue roots are candidates. Overlaps and gaps prevent a complete executable-map claim.')
    print('The native span excludes ROM assets. Targets outside this span remain unresolved.')
    outside = outside_native_entries(rom)
    print(f'Referenced prologue or return candidates outside the native span: {len(outside)}')
    for (address, mode), references in sorted(outside.items()):
        print(f'  {mode} 0x{address:08X}: {len(references)} aligned ROM pointer references')
    print('The whole-ROM pointer check cannot identify compressed code or code without a recognized entry pattern.')


if __name__ == '__main__':
    main()

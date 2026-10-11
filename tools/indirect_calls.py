#!/usr/bin/env python3
"""Trace Thumb callback loads without treating every ROM pointer as a call."""

# Register trampolines and callback layouts follow jmacato/ZoidsLegacyDecomp.

import argparse
from collections import deque
from dataclasses import dataclass
from math import gcd
from pathlib import Path
import struct

from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from capstone.arm import ARM_OP_IMM, ARM_OP_MEM, ARM_OP_REG

if __package__:
    from .verify import ARM_CALLS, BASE, REGIONS, read_rom
else:
    from verify import ARM_CALLS, BASE, REGIONS, read_rom


MASK = 0xFFFFFFFF
CODE_START = BASE + 0x464
# The current native code boundary does not establish a complete code map.
CODE_END = BASE + 0x5EE80
TRAMPOLINES = {BASE + 0x5D29C + 4 * register: register for register in range(15)}
UNKNOWN = ('unknown',)


@dataclass(frozen=True)
class Span:
    low: int
    high: int
    step: int = 1

    def addresses(self, limit=256):
        count = (self.high - self.low) // self.step + 1
        return range(self.low, self.low + min(count, limit) * self.step, self.step)


def constant(value):
    return ('constant', value & MASK)


def operation(kind, left, right):
    if kind in ('lsl', 'lsr') and right[0] == 'constant' and right[1] >= 32:
        return constant(0)
    if left[0] == right[0] == 'constant':
        a, b = left[1], right[1]
        operations = {'add': lambda: a + b, 'sub': lambda: a - b,
                      'mul': lambda: a * b, 'lsl': lambda: a << b,
                      'lsr': lambda: a >> b, 'and': lambda: a & b,
                      'or': lambda: a | b, 'xor': lambda: a ^ b}
        return constant(operations[kind]())
    if right == constant(0) and kind in ('add', 'sub', 'lsl', 'lsr'):
        return left
    if kind == 'lsl' and right[0] == 'constant':
        return operation('mul', left, constant(1 << right[1]))
    if kind == 'add':
        def factor(value):
            if value[0] == 'mul' and value[2][0] == 'constant':
                return value[1], value[2][1]
            return value, 1
        a, scale_a = factor(left)
        b, scale_b = factor(right)
        if a == b and a != UNKNOWN:
            return operation('mul', a, constant(scale_a + scale_b))
    if kind == 'mul' and left[0] == 'mul' and right[0] == left[2][0] == 'constant':
        return operation('mul', left[1], constant(left[2][1] * right[1]))
    expression = (kind, left, right)
    # Loops can grow expressions indefinitely. Losing precision is safe here.
    if len(repr(expression)) > 700:
        return UNKNOWN
    return expression


def span(expression):
    kind = expression[0]
    if kind == 'constant':
        return Span(expression[1], expression[1])
    if kind == 'load':
        width, signed = expression[2:4]
        return Span(0, MASK if signed else (1 << (width * 8)) - 1)
    if kind == 'limit':
        value = span(expression[1])
        low, high = max(value.low, expression[2]), min(value.high, expression[3])
        low += (value.low - low) % value.step
        high -= (high - value.low) % value.step
        return Span(low, high, value.step) if low <= high else None
    if kind not in ('add', 'sub', 'mul', 'lsl', 'lsr', 'and', 'or', 'xor'):
        return Span(0, MASK)
    a, b = span(expression[1]), span(expression[2])
    if a is None or b is None:
        return None
    if a.low == a.high and b.low == b.high:
        return span(operation(kind, constant(a.low), constant(b.low)))
    if kind == 'add' and a.high + b.high <= MASK:
        step = b.step if a.low == a.high else a.step if b.low == b.high else gcd(a.step, b.step)
        return Span(a.low + b.low, a.high + b.high, step)
    if kind == 'sub' and a.low >= b.high:
        step = a.step if b.low == b.high else gcd(a.step, b.step)
        return Span(a.low - b.high, a.high - b.low, step)
    if kind == 'mul' and b.low == b.high:
        scale = b.low
        if not scale:
            return Span(0, 0)
        if a.high * scale <= MASK:
            return Span(a.low * scale, a.high * scale, a.step * scale)
        step = gcd(a.step * scale, 1 << 32)
        residue = a.low * scale % step
        return Span(residue, MASK - (MASK - residue) % step, step)
    if kind == 'lsr' and b.low == b.high:
        return Span(a.low >> b.low, a.high >> b.low,
                    a.step >> b.low if a.step % (1 << b.low) == 0 else 1)
    if kind == 'and' and b.low == b.high:
        return Span(0, min(a.high, b.low))
    return Span(0, MASK)


def describe(expression):
    if expression[0] == 'limit':
        return describe(expression[1])
    if expression[0] == 'constant':
        return f'0x{expression[1]:08X}'
    if expression[0] == 'load':
        return f"{'signed ' if expression[3] else ''}{expression[2] * 8}-bit load from {describe(expression[1])}"
    value = span(expression)
    if value is None:
        return 'empty selector range'
    if value.low == value.high:
        return f'0x{value.low:08X}'
    return f'0x{value.low:08X}..0x{value.high:08X}, stride {value.step}'


class Analyzer:
    def __init__(self, rom, start=CODE_START, end=CODE_END, trampolines=None):
        self.rom = rom
        self.start, self.end = start, end
        self.trampolines = TRAMPOLINES if trampolines is None else trampolines
        self.decoder = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        self.decoder.detail = True
        self.instructions = {}
        self.calls = {}
        self.direct_targets = set()
        self.switch_labels = set()
        self.stores = set()
        self.incomplete = set()

    def read(self, address, width):
        offset = address - BASE
        if 0 <= offset <= len(self.rom) - width:
            return int.from_bytes(self.rom[offset:offset + width], 'little')
        return None

    def decode(self, address):
        if address not in self.instructions:
            offset = address - BASE
            instruction = next(self.decoder.disasm(self.rom[offset:offset + 4], address, 1), None)
            if instruction and (instruction.size == 4 and instruction.mnemonic != 'bl'
                                or instruction.mnemonic in ('blx', 'cbz', 'cbnz', 'it', 'bkpt', 'uxtb', 'uxth', 'rev', 'revsh')):
                instruction = None
            self.instructions[address] = instruction
        return self.instructions[address]

    def analyze(self, entry, budget=12000):
        initial = tuple(frozenset({('argument', entry, index)}) for index in range(16))
        states = {}
        queue = deque([(entry, initial, None)])
        steps = 0

        def merge(old, new):
            values = old | new
            return frozenset({UNKNOWN}) if len(values) > 4 else values

        while queue and steps < budget:
            address, incoming, comparison = queue.popleft()
            if not entry <= address < self.end or address & 1:
                self.incomplete.add((entry, address, 'branch outside function range'))
                continue
            key = (address, comparison)
            previous = states.get(key)
            registers = tuple(merge(a, b) for a, b in zip(previous, incoming)) if previous else incoming
            if previous == registers:
                continue
            states[key] = registers
            steps += 1
            instruction = self.decode(address)
            if instruction is None:
                self.incomplete.add((entry, address, 'unsupported instruction'))
                continue
            registers = list(registers)
            mnemonic = instruction.mnemonic
            operands = instruction.operands

            def register(number):
                name = instruction.reg_name(number)
                aliases = {'sb': 9, 'sl': 10, 'fp': 11, 'ip': 12, 'sp': 13, 'lr': 14, 'pc': 15}
                return aliases[name] if name in aliases else int(name[1:])

            def value(operand):
                if operand.type == ARM_OP_IMM:
                    return frozenset({constant(operand.imm)})
                return registers[register(operand.reg)]

            def apply(kind, left, right):
                result = frozenset(operation(kind, a, b) for a in left for b in right)
                return result if len(result) <= 4 else frozenset({UNKNOWN})

            def memory(operand):
                base = register(operand.mem.base)
                values = frozenset({constant((address + 4) & ~3)}) if base == 15 else registers[base]
                if operand.mem.index:
                    values = apply('add', values, registers[register(operand.mem.index)])
                return apply('add', values, frozenset({constant(operand.mem.disp)}))

            next_address = address + instruction.size
            if mnemonic == 'bl':
                target = operands[0].imm
                if target in self.trampolines:
                    selected = self.trampolines[target]
                    self.calls.setdefault(address, set()).update(registers[selected])
                elif self.start <= target < self.end:
                    self.direct_targets.add(target)
                for index in (0, 1, 2, 3, 12, 14):
                    registers[index] = frozenset({UNKNOWN})
                comparison = None
            elif mnemonic == 'svc':
                for index in (0, 1, 2, 3, 12):
                    registers[index] = frozenset({UNKNOWN})
                comparison = None
            elif mnemonic in ('bx', 'mov', 'movs') and operands[0].type == ARM_OP_REG and (
                    mnemonic == 'bx' or register(operands[0].reg) == 15):
                if mnemonic != 'bx':
                    for expression in value(operands[1]):
                        labels = self.switch_targets(expression, entry)
                        if not labels:
                            self.incomplete.add((entry, address, 'switch or computed branch'))
                        for label in labels:
                            self.switch_labels.add(label)
                            queue.append((label, tuple(registers), None))
                continue
            elif mnemonic == 'pop':
                if any(register(op.reg) == 15 for op in operands):
                    continue
                for operand in operands:
                    registers[register(operand.reg)] = frozenset({UNKNOWN})
                registers[13] = apply('add', registers[13], frozenset({constant(4 * len(operands))}))
            elif mnemonic == 'push':
                registers[13] = apply('sub', registers[13], frozenset({constant(4 * len(operands))}))
            elif mnemonic.startswith('ldr'):
                width = 1 if mnemonic in ('ldrb', 'ldrsb') else 2 if mnemonic in ('ldrh', 'ldrsh') else 4
                signed = mnemonic in ('ldrsb', 'ldrsh')
                values = set()
                for location in memory(operands[1]):
                    number = self.read(location[1], width) if location[0] == 'constant' else None
                    if number is not None:
                        if signed and number & (1 << (8 * width - 1)):
                            number -= 1 << (8 * width)
                        values.add(constant(number))
                    else:
                        values.add(('load', location, width, signed, address))
                registers[register(operands[0].reg)] = frozenset(values)
            elif mnemonic.startswith('str'):
                width = 1 if mnemonic == 'strb' else 2 if mnemonic == 'strh' else 4
                for location in memory(operands[1]):
                    if location[0] == 'constant' and width == 4:
                        for stored in value(operands[0]):
                            if stored[0] == 'constant':
                                self.stores.add((address, location[1], stored[1]))
            elif mnemonic in ('mov', 'movs'):
                registers[register(operands[0].reg)] = value(operands[1])
            elif mnemonic in ('add', 'adds', 'sub', 'subs', 'mul', 'muls', 'lsl', 'lsls', 'lsr', 'lsrs', 'and', 'ands', 'orrs', 'eors'):
                kind = {'orrs': 'or', 'eors': 'xor'}.get(mnemonic, mnemonic.rstrip('s'))
                destination = register(operands[0].reg)
                left = value(operands[1]) if len(operands) == 3 else registers[destination]
                right = value(operands[-1])
                if kind in ('lsl', 'lsr') and operands[-1].type == ARM_OP_REG:
                    right = apply('and', right, frozenset({constant(255)}))
                registers[destination] = apply(kind, left, right)
                if instruction.update_flags:
                    comparison = None
            elif mnemonic == 'cmp':
                comparison = (value(operands[0]), operands[1].imm) if operands[1].type == ARM_OP_IMM else None
            elif mnemonic == 'b':
                queue.append((operands[0].imm, tuple(registers), comparison))
                continue
            elif mnemonic.startswith('b') and instruction.group(1):
                for taken, destination in ((True, operands[0].imm), (False, next_address)):
                    branch = list(registers)
                    if comparison:
                        compared, bound = comparison
                        limits = {'bhi': ((bound + 1, MASK), (0, bound)),
                                  'bhs': ((bound, MASK), (0, bound - 1)),
                                  'blo': ((0, bound - 1), (bound, MASK)),
                                  'bls': ((0, bound), (bound + 1, MASK)),
                                  'beq': ((bound, bound), (0, MASK)),
                                  'bne': ((0, MASK), (bound, bound))}
                        low, high = limits.get(mnemonic, ((0, MASK), (0, MASK)))[0 if taken else 1]
                        if not any(span(('limit', item, low, high)) is not None for item in compared):
                            continue
                        for index, values in enumerate(branch):
                            branch[index] = frozenset(
                                ('limit', item, low, high) if item in compared and item != UNKNOWN else item
                                for item in values if item not in compared or item == UNKNOWN or
                                span(('limit', item, low, high)) is not None)
                            if not branch[index]:
                                break
                        else:
                            queue.append((destination, tuple(branch), None))
                        continue
                    queue.append((destination, tuple(branch), None))
                continue
            else:
                _, writes = instruction.regs_access()
                for number in writes:
                    name = instruction.reg_name(number)
                    if name != 'cpsr':
                        registers[register(number)] = frozenset({UNKNOWN})
                if instruction.update_flags:
                    comparison = None
            if instruction.update_flags and mnemonic != 'cmp':
                comparison = None
            queue.append((next_address, tuple(registers), comparison))
        if queue:
            self.incomplete.add((entry, entry, 'analysis budget reached'))

    def pointer(self, value):
        address = value & ~1
        if self.start <= address < self.end and (value & 1 or address % 4 == 0):
            return address, 'Thumb' if value & 1 else 'ARM'
        if 0x02000000 <= address < 0x02040000 or 0x03000000 <= address < 0x03008000:
            if value & 1 or address % 4 == 0:
                return address, 'RAM Thumb' if value & 1 else 'RAM ARM'
        return None

    def switch_targets(self, expression, entry):
        while expression[0] == 'limit':
            expression = expression[1]
        if expression[0] != 'load' or expression[2:4] != (4, False):
            return set()
        locations = span(expression[1])
        if locations is None or not entry <= locations.low <= locations.high < self.end:
            return set()
        if (locations.high - locations.low) // locations.step + 1 > 256:
            return set()
        labels = {self.read(address, 4) for address in locations.addresses()}
        if any(label is None or label & 1 or not entry <= label < self.end or not self.decode(label)
               for label in labels):
            return set()
        # MOV-PC preserves Thumb mode. These even addresses are local labels.
        return labels

    def targets(self, expression):
        restriction = span(expression)
        while expression[0] == 'limit':
            expression = expression[1]
        if expression[0] == 'constant':
            return {(None, expression[1])} if self.pointer(expression[1]) else set()
        if expression[0] != 'load' or expression[2:4] != (4, False):
            return set()
        locations = span(expression[1])
        if locations is None:
            return set()
        if BASE <= locations.low <= locations.high < BASE + len(self.rom):
            candidates = {(address, number) for address in locations.addresses()
                          if address % 4 == 0 and (number := self.read(address, 4)) is not None and self.pointer(number)}
        elif (0x02000000 <= locations.low < 0x02040000 or
              0x03000000 <= locations.low < 0x03008000):
            candidates = {(address, number) for _, address, number in self.stores
                          if locations.low <= address <= locations.high and
                          (address - locations.low) % locations.step == 0 and self.pointer(number)
                          and (0x02000000 <= address < 0x02040000 or 0x03000000 <= address < 0x03008000)}
        else:
            return set()
        return {(address, number) for address, number in candidates
                if restriction is not None and restriction.low <= number <= restriction.high}


def thumb_call_candidates(rom, start=CODE_START, end=CODE_END):
    for address in range(start, end - 3, 2):
        first, second = struct.unpack_from('<HH', rom, address - BASE)
        if first & 0xF800 == 0xF000 and second & 0xF800 == 0xF800:
            offset = ((first & 0x7FF) << 12) | ((second & 0x7FF) << 1)
            if offset & 0x400000:
                offset -= 0x800000
            target = address + 4 + offset
            yield address, target


def direct_call_candidates(rom, start=CODE_START, end=CODE_END):
    return {target for _, target in thumb_call_candidates(rom, start, end)
            if start <= target < end and target not in TRAMPOLINES}


def trampoline_call_candidates(rom, start=CODE_START, end=CODE_END):
    return {site for site, target in thumb_call_candidates(rom, start, end) if target in TRAMPOLINES}


def trace_missing_sites(analyzer, sites):
    for site in sorted(sites):
        if site in analyzer.calls:
            continue
        # Validate each nearby PUSH-LR candidate by walking its control flow.
        for entry in range(site - 2, max(analyzer.start - 2, site - 0x4000), -2):
            instruction = analyzer.read(entry, 2)
            if instruction & 0xFF00 == 0xB500:
                analyzer.analyze(entry)
                if site in analyzer.calls:
                    break


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=Path('0259 - Zoids Saga (J)(Independent).gba'))
    parser.add_argument('--entry', type=lambda value: int(value, 0), action='append',
                        help='Analyze only this Thumb entry. Repeat for more entries.')
    args = parser.parse_args()
    rom = read_rom(args.rom)
    analyzer = Analyzer(rom)
    entries = set(args.entry or (direct_call_candidates(rom) |
                                {BASE + start for name, start, _, _ in REGIONS if name not in ARM_CALLS}))
    for entry in entries:
        if not CODE_START <= entry < CODE_END or entry & 1:
            parser.error(f'Invalid Thumb entry: 0x{entry:08X}')
    pending = set(entries)
    analyzed = set()
    while pending:
        entry = min(pending)
        pending.remove(entry)
        analyzer.analyze(entry)
        analyzed.add(entry)
        if not args.entry:
            discovered = analyzer.direct_targets | {
                number & ~1 for expressions in analyzer.calls.values() for expression in expressions
                for _, number in analyzer.targets(expression)
                if number & 1 and CODE_START <= (number & ~1) < CODE_END}
            pending.update(discovered - analyzed)
    if not args.entry:
        sites = trampoline_call_candidates(rom)
        trace_missing_sites(analyzer, sites)
        print(f'Control flow reached {len(sites & analyzer.calls.keys())}/{len(sites)} raw trampoline-call candidates.')
    targets = set()
    resolved = 0
    for site, expressions in sorted(analyzer.calls.items()):
        print(f'Call 0x{site:08X}')
        found = set()
        for expression in sorted(expressions, key=repr):
            candidates = analyzer.targets(expression)
            found.update(number for _, number in candidates)
            print(f'  Source: {describe(expression)}')
            if expression[0] == 'load':
                domain = span(expression[1])
                if domain and BASE <= domain.low <= domain.high < BASE + len(rom):
                    count = (domain.high - domain.low) // domain.step + 1
                    print(f'  Selector domain: {count} addresses; sampled {min(count, 256)}; {len(candidates)} code-pointer candidates')
                    print('  The selector domain does not establish the table length.')
            for location, number in sorted(candidates, key=lambda item: item[1]):
                target, mode = analyzer.pointer(number)
                source = '' if location is None else f' from 0x{location:08X}'
                print(f'    {mode} 0x{target:08X}{source}')
        if found:
            resolved += 1
        targets.update(found)
    print(f'Calls with code-pointer candidates: {resolved}/{len(analyzer.calls)}; unique candidates: {len(targets)}')
    print(f'Incomplete entry paths: {len(analyzer.incomplete)}')
    print(f'Switch labels reached: {len(analyzer.switch_labels)}; these are not function entries.')
    print('RAM targets come from matching constant stores. This does not prove the store executes before the call.')
    print('Pointer-shaped data can remain among table candidates.')
    print('Coverage gaps: ARM paths, BX exits, switch branches, stack reloads, and dynamic callback writers.')
    if not args.entry:
        print('Entries include raw BL candidates. Literal data can resemble calls; this is not a complete function map.')


if __name__ == '__main__':
    main()

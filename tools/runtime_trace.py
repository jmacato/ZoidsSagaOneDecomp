#!/usr/bin/env python3
"""Deduplicate runtime targets and keep function candidates separate from block targets."""

import argparse
from collections import Counter
from dataclasses import dataclass, field
import hashlib
from pathlib import Path
import sqlite3

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_INS_BL

if __package__:
    from .verify import BASE, ROOT, read_rom
else:
    from verify import BASE, ROOT, read_rom


@dataclass
class RuntimeSeeds:
    entries: set = field(default_factory=set)
    block_entries: set = field(default_factory=set)
    correspondences: set = field(default_factory=set)
    evidence: Counter = field(default_factory=Counter)
    rejected_calls: set = field(default_factory=set)
    unmapped_ram: set = field(default_factory=set)
    ambiguous_ram: dict = field(default_factory=dict)
    return_edges: set = field(default_factory=set)


def normalize_rom(address, size):
    if not BASE <= address < 0x0E000000:
        return None
    offset = (address - BASE) % 0x02000000
    return BASE + offset if offset < size else None


def read_memory(rom, images, address, width):
    normalized = normalize_rom(address, len(rom))
    if normalized is not None:
        return rom[normalized - BASE:normalized - BASE + width]
    for base, image in images:
        offset = address - base
        if 0 <= offset <= len(image) - width:
            return image[offset:offset + width]
    return b''


def call_mode(rom, images, source, target):
    for address, mode, flag in ((source - 2, 'Thumb', CS_MODE_THUMB),
                                (source, 'Thumb', CS_MODE_THUMB), (source, 'ARM', CS_MODE_ARM)):
        if address % (4 if mode == 'ARM' else 2):
            continue
        data = read_memory(rom, images, address, 4)
        decoder = Cs(CS_ARCH_ARM, flag)
        decoder.detail = True
        instruction = next(decoder.disasm(data, address, 1), None)
        if instruction and instruction.id == ARM_INS_BL and instruction.operands[0].imm == target:
            return mode
    return None


def return_source(rom, images, source):
    data = read_memory(rom, images, source, 4)
    if len(data) < 4:
        return False
    word = int.from_bytes(data, 'little') & 0x0FFFFFFF
    if source % 4 == 0 and word in (0x012FFF1E, 0x01A0F00E, 0x01B0F00E, 0x025EF004):
        return True
    halfword = int.from_bytes(data[:2], 'little')
    if halfword == 0x4770 or halfword & 0xFF00 == 0xBD00:
        return True
    if halfword & 0xFF87 == 0x4700:
        register = (halfword >> 3) & 15
        previous = read_memory(rom, images, source - 2, 2)
        return register < 8 and int.from_bytes(previous, 'little') == (0xBC00 | (1 << register))
    return False


def ram_correspondence(rom, images, address):
    ambiguous = set()
    for base, image in images:
        offset = address - base
        if not 0 <= offset <= len(image) - 16:
            continue
        window = image[offset:offset + 16]
        candidates = []
        cursor = 0
        while True:
            found = rom.find(window, cursor)
            if found < 0:
                break
            cursor = found + 1
            if not found % 2:
                candidates.append(found)
            if len(candidates) > 16:
                break
        if len(candidates) == 1:
            source = candidates[0]
            left = 0
            while offset - left >= 2 and source - left >= 2 and \
                    image[offset - left - 2:offset - left] == rom[source - left - 2:source - left]:
                left += 2
            right = 16
            while offset + right + 2 <= len(image) and source + right + 2 <= len(rom) and \
                    image[offset + right:offset + right + 2] == rom[source + right:source + right + 2]:
                right += 2
            return (BASE + source - left, address - left, left + right), ()
        if 1 < len(candidates) <= 16:
            ambiguous.update(BASE + candidate for candidate in candidates)
    return None, tuple(sorted(ambiguous))


def load_runtime_seeds(database, rom, minimum_jump=128):
    result = RuntimeSeeds()
    with sqlite3.connect(database.resolve().as_uri() + '?mode=ro', uri=True) as connection:
        identity = connection.execute('SELECT sha1 FROM tracing_rom').fetchall()
        if identity != [(hashlib.sha1(rom).hexdigest(),)]:
            raise ValueError('The runtime trace belongs to a different ROM.')
        images = [(base, bytes(data)) for base, data in connection.execute(
            'SELECT base, bytes FROM tracing_memory ORDER BY run_id DESC, frame DESC')]
        if connection.execute("SELECT 1 FROM sqlite_master WHERE name='tracing_bios'").fetchone():
            images.extend((0, bytes(data)) for data, in connection.execute('SELECT bytes FROM tracing_bios'))
        modes = {}
        for address, mode in connection.execute('SELECT start_addr, mode FROM blocks'):
            modes.setdefault(address, set()).add('Thumb' if mode else 'ARM')
        for source, target, kind, count in connection.execute('SELECT src, dst, kind, count FROM edges'):
            address = normalize_rom(target, len(rom))
            if address is None and not (0x02000000 <= target < 0x02040000 or
                                        0x03000000 <= target < 0x03008000):
                continue
            if kind == 'return':
                continue
            if kind == 'indirect' and return_source(rom, images, source):
                result.return_edges.add((source, target))
                continue
            evidence = kind + '_target'
            if kind == 'call':
                mode = call_mode(rom, images, source, target)
                if mode is None:
                    result.rejected_calls.add((source, target))
                    continue
                target_modes = {mode}
            elif kind in ('indirect', 'irq', 'swi', 'und'):
                target_modes = modes.get(target, set())
            elif kind == 'branch' and abs(target - source) >= minimum_jump:
                target_modes = modes.get(target, set())
            else:
                continue
            if address is None:
                correspondence, ambiguous = ram_correspondence(rom, images, target)
                if correspondence:
                    result.correspondences.add(correspondence)
                    address = target
                elif ambiguous:
                    result.ambiguous_ram[target] = ambiguous
                    continue
                else:
                    result.unmapped_ram.add(target)
                    continue
            for mode in target_modes:
                if address % (4 if mode == 'ARM' else 2):
                    continue
                key = address, mode
                if kind == 'branch':
                    result.block_entries.add(key)
                else:
                    result.entries.add(key)
                result.evidence[(address, mode, evidence)] += count
    return result


def save_seed_candidates(database, seeds, minimum_jump):
    with sqlite3.connect(database) as connection:
        connection.executescript('''
            CREATE TABLE IF NOT EXISTS runtime_seeds(
                address INTEGER, mode TEXT, evidence TEXT, execution_count INTEGER,
                PRIMARY KEY(address, mode, evidence));
            CREATE TABLE IF NOT EXISTS runtime_ram_correspondences(
                rom_source INTEGER, ram_source INTEGER, byte_count INTEGER,
                PRIMARY KEY(rom_source, ram_source, byte_count));
        ''')
        connection.execute('DELETE FROM runtime_seeds')
        connection.execute('DELETE FROM runtime_ram_correspondences')
        connection.executemany('INSERT INTO runtime_seeds VALUES (?, ?, ?, ?)',
                               ((*key, count) for key, count in sorted(seeds.evidence.items())))
        connection.executemany('INSERT INTO runtime_ram_correspondences VALUES (?, ?, ?)',
                               sorted(seeds.correspondences))
        connection.execute('DROP VIEW IF EXISTS large_jumps')
        connection.execute(f'''CREATE VIEW large_jumps AS
            SELECT src, dst, kind, count, ABS(dst-src) AS distance
            FROM edges WHERE ABS(dst-src) >= {int(minimum_jump)}''')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--database', type=Path, default=ROOT / 'ZoidsSaga.trace.sqlite')
    parser.add_argument('--rom', type=Path, default=ROOT / '0259 - Zoids Saga (J)(Independent).gba')
    parser.add_argument('--minimum-jump', type=int, default=128)
    args = parser.parse_args()
    if args.minimum_jump < 0:
        parser.error('The minimum jump must be nonnegative.')
    seeds = load_runtime_seeds(args.database, read_rom(args.rom), args.minimum_jump)
    save_seed_candidates(args.database, seeds, args.minimum_jump)
    print(f'Function entry candidates: {len(seeds.entries)}; long-branch block candidates: {len(seeds.block_entries)}')
    print(f'RAM byte correspondences: {len(seeds.correspondences)}; ambiguous RAM targets: {len(seeds.ambiguous_ram)}')
    print(f'Unmapped RAM targets: {len(seeds.unmapped_ram)}; rejected call edges: {len(seeds.rejected_calls)}')
    print(f'Indirect edges recognized as returns: {len(seeds.return_edges)}')
    print('Runtime targets are seeds. Calls, returns, shared frames, and exits still determine function boundaries.')


if __name__ == '__main__':
    main()

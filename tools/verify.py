#!/usr/bin/env python3
"""Compile native regions at their original addresses and check their ROM bytes."""

# Thumb stub linking adapts tools/linklib.py from jmacato/ZoidsLegacyDecomp.
# Copyright (c) 2026 Jumar Macato
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import argparse
import hashlib
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import c_quality
ROM_SHA1 = "75d8c15ac281ea93c8ac7cc7641c490799557081"
ROM_SIZE = 0x800000
BASE = 0x08000000
COMPILER_REVISION = "da598c1d918402c42c0c0d7128ba14567f3175e9"
ASSEMBLY_MODES = {"asm", "arm"}


def read_regions(path):
    regions = []
    sources = {}
    previous_end = 0
    for raw in path.read_text().splitlines():
        fields = raw.split("#", 1)[0].split()
        if not fields:
            continue
        if len(fields) != 5:
            raise ValueError(f"Invalid region: {raw}")
        name, low, high, source, mode = fields
        start, end = int(low, 16), int(high, 16)
        if name in sources or not previous_end <= start < end <= ROM_SIZE:
            raise ValueError(f"Duplicate, overlapping, or invalid region: {name}")
        if mode not in {"c", "old", "O1", "lib", "gcc", "gcc-apcs", "gcc-apcs-ordered", "gcc-arm", "gcc-arm-ordered", *ASSEMBLY_MODES}:
            raise ValueError(f"Invalid compiler mode: {mode}")
        if mode in {"arm", "gcc-arm", "gcc-arm-ordered"} and (start % 4 or end % 4):
            raise ValueError(f"Invalid ARM alignment: {name}")
        source_path = Path(source)
        if source_path.is_absolute() or ".." in source_path.parts:
            raise ValueError(f"Invalid source path: {source}")
        if source_path.suffix != (".s" if mode in ASSEMBLY_MODES else ".c"):
            raise ValueError(f"Source extension does not match compiler mode: {source}")
        regions.append((name, start, end, mode))
        sources[name] = source
        previous_end = end
    if not regions:
        raise ValueError("The region list is empty.")
    return tuple(regions), sources


REGIONS, SOURCE_FILES = read_regions(ROOT / "regions.txt")
CALLS = {name: BASE + start for name, start, _, _ in REGIONS}
ARM_CALLS = {name for name, _, _, mode in REGIONS if mode in {"arm", "gcc-arm", "gcc-arm-ordered"}}
SYMBOLS = {name: int(address, 16) for name, address in re.findall(
    r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", (ROOT / "symbols.ld").read_text())}
DATA_SYMBOLS = SYMBOLS


def read_rom(path):
    data = path.read_bytes()
    if len(data) != ROM_SIZE or hashlib.sha1(data).hexdigest() != ROM_SHA1:
        raise ValueError("ROM hash does not match Zoids Saga (Japan), revision 0.")
    return data


def run(command):
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError(result.stderr.strip() or result.stdout.strip())


def compile_region(name, start, mode, compiler, work):
    assembly = work / "function.s"
    preprocessed = work / "function.i"
    object_file = work / "function.o"
    if mode in ASSEMBLY_MODES:
        assembly = ROOT / "src" / SOURCE_FILES[name]
    else:
        run(["cc", "-E", "-P", "-I", str(ROOT / "src"),
             str(ROOT / "src" / SOURCE_FILES[name]), "-o", str(preprocessed)])
        if mode in {"gcc", "gcc-apcs", "gcc-apcs-ordered", "gcc-arm", "gcc-arm-ordered"}:
            flags = ["-S", "-mcpu=arm7tdmi", "-marm" if mode in {"gcc-arm", "gcc-arm-ordered"} else "-mthumb", "-mthumb-interwork",
                     "-fomit-frame-pointer"]
            if mode in {"gcc-apcs", "gcc-apcs-ordered", "gcc-arm", "gcc-arm-ordered"}:
                flags.append("-mabi=apcs-gnu")
            if mode in {"gcc-apcs-ordered", "gcc-arm-ordered"}:
                flags.append("-fno-toplevel-reorder")
        elif mode == "lib":
            flags = ["-fno-builtin"]
        else:
            flags = ["-mthumb-interwork", *([] if mode == "old" else ["-fprologue-bugfix"])]
        level = "-O" if mode == "O1" else "-O2"
        run([str(compiler), level, *flags, "-o", str(assembly), str(preprocessed)])
        with assembly.open("a") as output:
            output.write("\n.align 2, 0\n")
    run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-mthumb-interwork",
         "-o", str(object_file), str(assembly)])

    # Stub symbol types preserve the CPU mode of each original call target.
    undefined = subprocess.run(["arm-none-eabi-nm", "-u", str(object_file)],
                               capture_output=True, text=True, check=True).stdout
    relocations = subprocess.run(["arm-none-eabi-objdump", "-r", str(object_file)],
                                 capture_output=True, text=True, check=True).stdout
    arm_call_symbols = {fields[2] for line in relocations.splitlines()
                        if len(fields := line.split()) == 3 and fields[1] in
                        {"R_ARM_CALL", "R_ARM_JUMP24", "R_ARM_PC24"}}
    call_symbols = arm_call_symbols | {
        fields[2] for line in relocations.splitlines()
        if len(fields := line.split()) == 3 and fields[1] == "R_ARM_THM_CALL"}
    calls = {}
    data_symbols = dict(DATA_SYMBOLS)
    for line in undefined.splitlines():
        symbol = line.split()[-1]
        if symbol in SYMBOLS and symbol in call_symbols:
            calls[symbol] = SYMBOLS[symbol] & ~1
        elif symbol in CALLS:
            calls[symbol] = CALLS[symbol]
        elif re.fullmatch(r"func_08[0-9A-F]{6}", symbol):
            calls[symbol] = int(symbol[5:], 16)
        elif re.fullmatch(r"D_0[0-9A-F]{7}", symbol):
            data_symbols[symbol] = int(symbol[2:], 16)
        elif symbol not in DATA_SYMBOLS:
            raise ValueError(f"Unknown external symbol: {symbol}")
    stubs = work / "stubs.s"
    stubs.write_text(".syntax unified\n" + "".join(
        f'.section .stub_{symbol},"ax",%progbits\n'
        f'.global {symbol}\n.type {symbol}, %function\n' +
        (f'.arm\n{symbol}:\n.word 0\n'
         if symbol in ARM_CALLS or symbol in arm_call_symbols and symbol not in CALLS
         else f'.thumb\n.thumb_func\n{symbol}:\n.byte 0, 0\n')
        for symbol in calls))
    stub_object = work / "stubs.o"
    run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-mthumb-interwork",
         "-o", str(stub_object), str(stubs)])
    linker = work / "function.ld"
    linker.write_text("".join(f"{symbol} = 0x{address:08X};\n" for symbol, address in data_symbols.items()
                             if symbol not in calls) +
        "SECTIONS {\n" +
        f'.text 0x{BASE + start:08X} : SUBALIGN(2) {{ "{object_file}"(.text .text.*{"" if mode == "O1" else " .rodata .rodata.*"}) }}\n' +
        "".join(f'.stub_{symbol} 0x{address:08X} : {{ "{stub_object}"(.stub_{symbol}) }}\n'
                for symbol, address in calls.items()) +
        (f'.bss 0x{SYMBOLS["bss_" + name]:08X} (NOLOAD) : {{ "{object_file}"(.bss) }}\n'
         if "bss_" + name in SYMBOLS else "") +
        "/DISCARD/ : { *(*) }\n}\n")
    elf = work / "function.elf"
    binary = work / "function.bin"
    run(["arm-none-eabi-ld", "--entry=0", "-T", str(linker),
         str(object_file), str(stub_object), "-o", str(elf)])
    run(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text", str(elf), str(binary)])
    return binary.read_bytes()


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     epilog=f"Use agbcc commit {COMPILER_REVISION}.")
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--agbcc", type=Path,
                        default=Path(os.environ.get("AGBCC", ROOT.parent / "agbcc/agbcc")))
    parser.add_argument("--old-agbcc", type=Path,
                        default=Path(os.environ.get("OLD_AGBCC", ROOT.parent / "agbcc/old_agbcc")))
    parser.add_argument("--gcc", type=Path,
                        default=Path(os.environ.get("ARM_GCC", shutil.which("arm-none-eabi-gcc")
                                                   or "arm-none-eabi-gcc")))
    parser.add_argument("--region", choices=[r[0] for r in REGIONS])
    parser.add_argument("--require-all-c", action="store_true",
                        help="Require matching C for every discovered native instruction.")
    parser.add_argument("--allow-mixed-c", action="store_true",
                        help="Temporarily allow mixed C sources while keeping byte checks strict.")
    parser.add_argument("--output", type=Path,
                        help="Rebuild the original ROM. Bytes outside selected regions come from the supplied ROM.")
    args = parser.parse_args()
    try:
        if args.allow_mixed_c and args.require_all_c:
            raise ValueError("Mixed C permission cannot be combined with C completion.")
        if args.require_all_c and args.region:
            raise ValueError("C completion requires all regions.")
        rom = read_rom(args.rom)
        if args.output and (args.region or args.output.resolve() == args.rom.resolve()):
            raise ValueError("A rebuild needs all regions and a separate output path.")
        for command in ("cc", "arm-none-eabi-as", "arm-none-eabi-ld", "arm-none-eabi-objcopy",
                        "arm-none-eabi-nm", "arm-none-eabi-objdump"):
            if shutil.which(command) is None:
                raise ValueError(f"Required command is unavailable: {command}")
        selected = [r for r in REGIONS if args.region is None or r[0] == args.region]
        source_classes, source_results = c_quality.classify_regions(
            ROOT, {name: [SOURCE_FILES[name]] for name, _, _, _ in selected})
        source_failures = [path for path, (state, _) in source_results.items()
                           if path.endswith(".c") and state != "c"]
        for path in sorted(source_failures):
            label = "WARN" if args.allow_mixed_c else "FAIL"
            print(f"{label} C source quality: src/{path}: {source_results[path][0]}")
        source_gate_failed = bool(source_failures) and not args.allow_mixed_c
        completion_failed = False
        if args.require_all_c:
            from executable_regions import scan_native
            from runtime_trace import load_runtime_seeds
            database = ROOT / "ZoidsSaga.trace.sqlite"
            runtime = load_runtime_seeds(database, rom) if database.is_file() else None
            native, _, _, _ = scan_native(rom, runtime)
            spans = []
            for (address, _), instruction in native.instructions.items():
                address = native.source(address)
                spans.append((f"0x{address:08X}", address - BASE, address - BASE + instruction.size))
            try:
                c_quality.require_c_coverage([(name, start, end) for name, start, end, _ in selected],
                                             source_classes, spans)
            except ValueError as error:
                completion_failed = True
                print(f"FAIL C completion: {error}")
        compilers = {"old": args.old_agbcc, "lib": args.old_agbcc,
                     "gcc": args.gcc, "gcc-apcs": args.gcc, "gcc-apcs-ordered": args.gcc,
                     "gcc-arm": args.gcc, "gcc-arm-ordered": args.gcc}
        for compiler in {compilers.get(mode, args.agbcc)
                         for _, _, _, mode in selected if mode not in ASSEMBLY_MODES}:
            if not compiler.is_file():
                raise ValueError(f"Compiler is unavailable: {compiler}")
        failures = 0
        functions = []
        rebuilt = bytearray(rom)
        with tempfile.TemporaryDirectory(prefix="zoids-saga-verify-") as temporary:
            for name, start, end, mode in selected:
                work = Path(temporary) / name
                work.mkdir()
                try:
                    compiler = compilers.get(mode, args.agbcc)
                    data = compile_region(name, start, mode, compiler, work)
                    if args.require_all_c and not completion_failed and source_classes[name] == "c":
                        functions.extend((f"{name}:{symbol}", low, high) for symbol, low, high in
                                         c_quality.compiled_functions(work / "function.elf"))
                    expected = rom[start:end]
                    if data != expected:
                        difference = next((i for i, (a, b) in enumerate(zip(data, expected)) if a != b),
                                          min(len(data), len(expected)))
                        raise ValueError(f"bytes differ at +0x{difference:X}, size {len(data)}/{len(expected)}")
                    print(f"PASS {name}: {len(data)} bytes ({source_classes[name]})")
                    rebuilt[start:end] = data
                except (ValueError, RuntimeError) as error:
                    failures += 1
                    print(f"FAIL {name}: {error}")
        print(f"Selected regions: {len(selected) - failures}/{len(selected)} matched.")
        if not failures:
            for state in ("c", "mixed", "assembly"):
                members = [r for r in selected if source_classes[r[0]] == state]
                print(f"{state}: {len(members)} regions, {sum(end - start for _, start, end, _ in members)} bytes.")
        if args.require_all_c and not failures and not completion_failed:
            try:
                c_quality.require_c_coverage(functions, {name: "c" for name, _, _ in functions},
                                             spans)
            except ValueError as error:
                completion_failed = True
                print(f"FAIL compiled C coverage: {error}")
        if args.output and not failures and not source_gate_failed and not completion_failed:
            if rebuilt != rom:
                raise ValueError("The rebuilt ROM differs from the original.")
            args.output.write_bytes(rebuilt)
            print(f"Rebuilt original ROM: SHA-1 {hashlib.sha1(rebuilt).hexdigest()}")
        print("Bytes outside the selected regions still come from the original ROM.")
        return 1 if failures or source_gate_failed or completion_failed else 0
    except (OSError, ValueError, RuntimeError) as error:
        print(f"Verification failed: {error}")
        return 2


if __name__ == "__main__":
    raise SystemExit(main())

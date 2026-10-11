# Zoids Saga (Japan) decompilation

This repository contains 1,897 byte-exact code regions from the game.
The source includes C, inline assembly, assembler macros, and assembly files.
It does not contain a ROM, game data, generated ROMs, saves, or binary probes.

> HEAD'S UP: The decomped functions looks jank right now due to the use of both permutators, function/argument/register macros, and typical AI slop. I'll try to clean it up when i get more free time :P

## Requirements

Install Python 3, Capstone, a C preprocessor, ARM binutils, ARM GCC, and agbcc.
Build agbcc from commit `da598c1d918402c42c0c0d7128ba14567f3175e9` of [pret/agbcc](https://github.com/pret/agbcc).
Build its normal compiler with GCC 14. Apple's Clang build fails on one source file.
From the agbcc checkout, run these commands:

    make -C gcc clean
    make -C gcc old
    cp gcc/old_agbcc old_agbcc
    make -C gcc clean
    make -C gcc CC=gcc-14
    cp gcc/agbcc agbcc

Run these builds serially; the makefile has dependencies that fail with parallel builds.

Set `AGBCC` and `OLD_AGBCC` when the compiler executables are outside `../agbcc/`.

## Verify

Provide your own clean Zoids Saga (Japan) ROM.
The verifier checks its SHA-1 before it compiles any code.

    make verify ROM=/path/to/original.gba

The verifier compiles each listed region at its original address.
It compares each generated region with the local ROM.
It creates temporary files only and never writes a ROM.
The strict C source check currently reports unfinished routines.

Use `python3 tools/verify.py --rom /path/to/rom --region NAME` to verify one region.

## Build the ROM

    make native ROM=/path/to/original.gba NATIVE_OUTPUT=/path/to/rebuilt.gba

This target permits the current mixed C sources and reports source quality warnings.
Every listed region must match the original bytes.
Bytes outside those regions come from your ROM.
The complete output must equal the original ROM.

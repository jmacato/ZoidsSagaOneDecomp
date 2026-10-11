import contextlib
import hashlib
import importlib.util
import io
from pathlib import Path
import struct
import shutil
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock


spec = importlib.util.spec_from_file_location(
    "verify", Path(__file__).resolve().parents[1] / "tools/verify.py")
verify = importlib.util.module_from_spec(spec)
spec.loader.exec_module(verify)


class VerifyTests(unittest.TestCase):
    def read_regions(self, text):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "regions.txt"
            path.write_text(text)
            return verify.read_regions(path)

    def test_region_list_keeps_subsystem_source_paths(self):
        regions, sources = self.read_regions("selection 0x10 0x20 ui/selection.c old\n")
        self.assertEqual(regions, (("selection", 0x10, 0x20, "old"),))
        self.assertEqual(sources, {"selection": "ui/selection.c"})

    def test_arm_regions_keep_assembly_sources(self):
        regions, sources = self.read_regions("entry 0xC0 0x240 engine/entry.s arm\n")
        self.assertEqual(regions, (("entry", 0xC0, 0x240, "arm"),))
        self.assertEqual(sources, {"entry": "engine/entry.s"})

    def test_gcc_regions_keep_c_sources(self):
        for mode in ("gcc", "gcc-apcs", "gcc-apcs-ordered", "gcc-arm", "gcc-arm-ordered"):
            with self.subTest(mode=mode):
                regions, sources = self.read_regions(f"pan 0x10 0x40 audio/pan.c {mode}\n")
                self.assertEqual(regions, (("pan", 0x10, 0x40, mode),))
                self.assertEqual(sources, {"pan": "audio/pan.c"})

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_gcc_apcs_keeps_four_byte_stack_alignment_for_original_callers(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                'extern unsigned target(unsigned);\n'
                'unsigned entry(unsigned value) {\n'
                '    asm volatile("" : : : "r4", "r5");\n'
                '    return target(value);\n'
                '}\n')
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}), \
                 mock.patch.object(verify, "CALLS", {"target": 0x08002000}):
                actual = verify.compile_region("entry", 0x1000, "gcc-apcs",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            self.assertEqual(struct.unpack_from("<H", actual)[0], 0xB530)

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_gcc_ordered_keeps_inline_data_before_shared_entry(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                '#pragma GCC optimize("align-functions=2")\n'
                'unsigned entry(unsigned value) { return value + 7; }\n'
                'static const unsigned short padding\n'
                '    __attribute__((used, section(".text"), aligned(2))) = 0;\n'
                'unsigned next(unsigned value) { return value + 3; }\n')
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                actual = verify.compile_region("entry", 0x1000, "gcc-apcs-ordered",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            self.assertEqual(actual, struct.pack("<6H", 0x3007, 0x4770, 0, 0x3003, 0x4770, 0))

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_gcc_compiles_thumb_code_for_arm7tdmi(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                "unsigned entry(unsigned value) { return value + 7; }\n")
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                actual = verify.compile_region("entry", 0x1000, "gcc",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            self.assertEqual(actual, struct.pack("<HH", 0x3007, 0x4770))

    def test_rejects_unaligned_arm_regions(self):
        for mode in ("arm", "gcc-arm", "gcc-arm-ordered"):
            for start, end in ((0xC2, 0x240), (0xC0, 0x242)):
                source = "entry.s" if mode == "arm" else "entry.c"
                with self.subTest(mode=mode, start=start, end=end), self.assertRaisesRegex(ValueError, "ARM alignment"):
                    self.read_regions(f"entry {start:#x} {end:#x} {source} {mode}\n")

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_gcc_arm_compiles_arm_code_for_arm7tdmi(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                "unsigned entry(unsigned value) { return value + 7; }\n")
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                actual = verify.compile_region("entry", 0x1000, "gcc-arm",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            self.assertEqual(actual, struct.pack("<II", 0xE2800007, 0xE12FFF1E))

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_gcc_arm_ordered_keeps_stack_literal_before_irq_entry(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                'unsigned entry(unsigned value) { return value + 7; }\n'
                'static const unsigned stack\n'
                '    __attribute__((used, section(".text"), aligned(4))) = 0x03007AA0;\n'
                'unsigned next(unsigned value) { return value + 3; }\n')
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                actual = verify.compile_region("entry", 0x1000, "gcc-arm-ordered",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            self.assertEqual(actual, struct.pack("<5I",
                0xE2800007, 0xE12FFF1E, 0x03007AA0, 0xE2800003, 0xE12FFF1E))

    def test_arm_links_keep_arm_branches_and_thumb_pointer_bits(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.s").write_text(""".syntax unified
.cpu arm7tdmi
.arm
.text
.global entry
.type entry, %function
entry:
    b arm_target
    .word arm_target
    .word thumb_target
""")
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.s"}), \
                 mock.patch.object(verify, "CALLS", {"arm_target": 0x08002000, "thumb_target": 0x08004000}), \
                 mock.patch.object(verify, "ARM_CALLS", {"arm_target"}):
                actual = verify.compile_region("entry", 0x1000, "arm", None, work)
            self.assertEqual(actual, struct.pack("<III", 0xEA0003FE, 0x08002000, 0x08004001))

    def test_rejects_overlapping_regions(self):
        with self.assertRaisesRegex(ValueError, "overlapping"):
            self.read_regions("one 0x10 0x30 one.c c\ntwo 0x20 0x40 two.c c\n")

    def test_rejects_duplicate_regions(self):
        with self.assertRaisesRegex(ValueError, "Duplicate"):
            self.read_regions("one 0x10 0x20 one.c c\none 0x20 0x30 one.c c\n")

    def test_rejects_region_outside_rom(self):
        with self.assertRaisesRegex(ValueError, "invalid region"):
            self.read_regions("one 0x800000 0x800010 one.c c\n")

    def test_rejects_source_outside_src(self):
        with self.assertRaisesRegex(ValueError, "Invalid source path"):
            self.read_regions("one 0x10 0x20 ../one.c c\n")

    def test_rejects_source_mode_mismatch(self):
        with self.assertRaisesRegex(ValueError, "Source extension"):
            self.read_regions("one 0x10 0x20 one.s c\n")

    def test_rejects_wrong_rom_size(self):
        with tempfile.TemporaryDirectory() as temporary:
            rom = Path(temporary) / "rom.gba"
            rom.write_bytes(b"wrong game")
            with self.assertRaisesRegex(ValueError, "ROM hash does not match"):
                verify.read_rom(rom)

    def test_rejects_wrong_rom_hash(self):
        with tempfile.TemporaryDirectory() as temporary:
            rom = Path(temporary) / "rom.gba"
            rom.write_bytes(bytes(verify.ROM_SIZE))
            with self.assertRaisesRegex(ValueError, "ROM hash does not match"):
                verify.read_rom(rom)

    def test_reads_rom_without_changes(self):
        with tempfile.TemporaryDirectory() as temporary:
            rom = Path(temporary) / "rom.gba"
            data = bytes(verify.ROM_SIZE)
            rom.write_bytes(data)
            with mock.patch.object(verify, "ROM_SHA1", hashlib.sha1(data).hexdigest()):
                self.assertEqual(verify.read_rom(rom), data)
            self.assertEqual(rom.read_bytes(), data)

    def check_compiled_failure(self, compiled):
        with tempfile.TemporaryDirectory() as temporary:
            compiler = Path(temporary) / "agbcc"
            compiler.touch()
            output = io.StringIO()
            with mock.patch("sys.argv", ["verify.py", "--rom", "rom.gba", "--agbcc", str(compiler),
                                         "--region", "font_find_range"]), \
                 mock.patch.object(verify, "read_rom", return_value=bytes(verify.ROM_SIZE)), \
                 mock.patch.object(verify.shutil, "which", return_value="tool"), \
                 mock.patch.object(verify, "compile_region", return_value=compiled), \
                 contextlib.redirect_stdout(output):
                self.assertEqual(verify.main(), 1)
            self.assertIn("FAIL font_find_range", output.getvalue())
            self.assertIn("0/1 matched", output.getvalue())

    def test_rejects_changed_compiled_byte(self):
        self.check_compiled_failure(bytes(55) + b"\x01")

    def test_rejects_truncated_compiled_region(self):
        self.check_compiled_failure(bytes(55))

    def test_rejects_extra_compiled_padding(self):
        self.check_compiled_failure(bytes(57))

    def test_checks_rom_before_compiler(self):
        with tempfile.TemporaryDirectory() as temporary:
            rom = Path(temporary) / "rom.gba"
            rom.write_bytes(b"wrong game")
            with mock.patch("sys.argv", ["verify.py", "--rom", str(rom)]), \
                 mock.patch.object(verify, "compile_region") as compile_region, \
                 contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(verify.main(), 2)
            compile_region.assert_not_called()

    def test_failed_rebuild_preserves_existing_output_with_mixed_c_permission(self):
        with tempfile.TemporaryDirectory() as temporary:
            compiler = Path(temporary) / "agbcc"
            compiler.touch()
            output = Path(temporary) / "native.gba"
            output.write_bytes(b"previous output")
            with mock.patch("sys.argv", ["verify.py", "--rom", "rom.gba", "--agbcc", str(compiler),
                                         "--allow-mixed-c", "--output", str(output)]), \
                 mock.patch.object(verify, "REGIONS", (("font_find_range", 0x417D0, 0x41808, "c"),)), \
                 mock.patch.object(verify, "read_rom", return_value=bytes(verify.ROM_SIZE)), \
                 mock.patch.object(verify.shutil, "which", return_value="tool"), \
                 mock.patch.object(verify, "compile_region", return_value=bytes(55)), \
                 contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(verify.main(), 1)
            self.assertEqual(output.read_bytes(), b"previous output")

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_mixed_c_permission_changes_only_source_gate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                '__attribute__((naked)) void entry(void) { asm("bx r0\\n\\tnop"); }\n')
            rom = bytearray(verify.ROM_SIZE)
            rom[0x1000:0x1004] = struct.pack("<HH", 0x4700, 0x46C0)
            rom_path = root / "rom.gba"
            rom_path.write_bytes(rom)
            output_path = root / "native.gba"
            output_path.write_bytes(b"previous output")
            for allowed in (False, True):
                with self.subTest(allow_mixed_c=allowed):
                    output_path.write_bytes(b"previous output")
                    output = io.StringIO()
                    arguments = ["verify.py", "--rom", str(rom_path), "--output", str(output_path)]
                    if allowed:
                        arguments.append("--allow-mixed-c")
                    with mock.patch.object(verify, "ROOT", root), \
                         mock.patch.object(verify, "REGIONS", (("entry", 0x1000, 0x1004, "gcc"),)), \
                         mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}), \
                         mock.patch.object(verify, "ROM_SHA1", hashlib.sha1(rom).hexdigest()), \
                         mock.patch("sys.argv", arguments), \
                         contextlib.redirect_stdout(output):
                        self.assertEqual(verify.main(), 0 if allowed else 1)
                    self.assertIn("1/1 matched", output.getvalue())
                    self.assertIn(("WARN" if allowed else "FAIL") + " C source quality", output.getvalue())
                    self.assertIn("assembly: 1 regions", output.getvalue())
                    self.assertEqual(output_path.read_bytes(), rom if allowed else b"previous output")

    def test_mixed_c_permission_cannot_weaken_completion(self):
        with mock.patch("sys.argv", ["verify", "--rom", "rom.gba",
                                    "--allow-mixed-c", "--require-all-c"]), \
             mock.patch.object(verify, "read_rom") as read_rom, \
             contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(verify.main(), 2)
        read_rom.assert_not_called()

    @unittest.skipUnless(shutil.which("arm-none-eabi-gcc"), "ARM GCC is required.")
    def test_completion_checks_copied_code_at_its_rom_source(self):
        import executable_regions
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text(
                "const unsigned short hidden_code[] = {0x4770, 0x46C0};\n"
                "unsigned entry(unsigned value) { return value; }\n")
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                data = verify.compile_region("entry", 0x1000, "gcc",
                    Path(shutil.which("arm-none-eabi-gcc")), work)
            rom = bytearray(verify.ROM_SIZE)
            rom[0x1000:0x1000 + len(data)] = data
            rom_path = root / "original.gba"
            rom_path.write_bytes(rom)
            for missing in (False, True, "hidden"):
                with self.subTest(missing=missing):
                    native = SimpleNamespace(
                        instructions={(0x03000000, "Thumb"): SimpleNamespace(size=2)},
                        source=lambda address: 0x08001000 if address == 0x03000000 else address)
                    if missing is True:
                        native.instructions[(0x08002000, "ARM")] = SimpleNamespace(size=4)
                    elif missing == "hidden":
                        native.instructions[(0x08001000 + len(data) - 4, "Thumb")] = SimpleNamespace(size=2)
                    output_path = root / "rebuilt.gba"
                    output_path.write_bytes(b"previous output")
                    with mock.patch.object(verify, "ROOT", root), \
                         mock.patch.object(verify, "REGIONS",
                            (("entry", 0x1000, 0x1000 + len(data), "gcc"),)), \
                         mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}), \
                         mock.patch.object(verify, "ROM_SHA1", hashlib.sha1(rom).hexdigest()), \
                         mock.patch.object(executable_regions, "scan_native",
                            return_value=(native, set(), set(), set())), \
                         mock.patch("sys.argv", ["verify", "--rom", str(rom_path),
                            "--require-all-c", "--output", str(output_path)]), \
                         contextlib.redirect_stdout(io.StringIO()) as output:
                        self.assertEqual(verify.main(), int(bool(missing)))
                    self.assertIn("1/1 matched", output.getvalue())
                    if missing is True:
                        self.assertIn("FAIL C completion", output.getvalue())
                        self.assertIn("0x08002000", output.getvalue())
                        self.assertEqual(output_path.read_bytes(), b"previous output")
                    elif missing == "hidden":
                        self.assertIn("FAIL compiled C coverage", output.getvalue())
                        self.assertEqual(output_path.read_bytes(), b"previous output")
                    else:
                        self.assertEqual(output_path.read_bytes(), rom)

    def test_rebuild_cannot_replace_original_rom(self):
        with mock.patch("sys.argv", ["verify.py", "--rom", "rom.gba", "--output", "rom.gba"]), \
             mock.patch.object(verify, "read_rom", return_value=bytes(verify.ROM_SIZE)), \
             mock.patch.object(verify, "compile_region") as compile_region, \
             contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(verify.main(), 2)
        compile_region.assert_not_called()


if __name__ == "__main__":
    unittest.main()

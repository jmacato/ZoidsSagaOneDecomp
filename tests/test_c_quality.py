import importlib.util
from pathlib import Path
import tempfile
import unittest


spec = importlib.util.spec_from_file_location("c_quality", Path(__file__).resolve().parents[1] / "tools/c_quality.py")
quality = importlib.util.module_from_spec(spec)
spec.loader.exec_module(quality)


class SourceQualityTests(unittest.TestCase):
    def test_register_peek_cannot_supply_a_computed_jump(self):
        for target in ("target", "(target)", "(void *)target", "(char *)target + 4"):
            with self.subTest(target=target):
                state, issues = quality.inspect_text(
                    '__attribute__((naked)) void entry(void) { '
                    'register void *target asm("lr"); asm("" : "=r"(target)); '
                    'goto *' + target + '; }')
                self.assertNotEqual(state, "c")
                self.assertIn("Computed jump uses an unbound assembly output", issues)

    def test_initialized_register_needs_a_tied_input_after_an_output(self):
        self.assertNotEqual(quality.inspect_text('''
            void entry(void *input) {
                register void *target asm("r0") = input;
                asm("" : "=r"(target));
                goto *target;
            }
        ''')[0], "c")

    def test_tied_inputs_supply_c_jump_targets(self):
        for operands in ('"=r"(target) : "0"(input)',
                         '[destination] "=r"(target) : "[destination]"(input)',
                         '"=r"(target) : "0"((void *)((unsigned)input + 4))'):
            with self.subTest(operands=operands):
                self.assertEqual(quality.inspect_text(
                    'void entry(void *input) { register void *target asm("r0"); '
                    'asm("" : ' + operands + '); goto *target; }')[0], "c")

    def test_output_numbers_include_memory_and_field_operands(self):
        self.assertEqual(quality.inspect_text('''
            void entry(void *input) {
                struct { int value; } scratch;
                register void *target asm("r0");
                asm("" : "=m"(scratch.value), "=r"(target) : "1"(input));
                goto *target;
            }
        ''')[0], "c")

    def test_read_write_constraint_preserves_c_jump_target(self):
        self.assertEqual(quality.inspect_text('''
            void entry(void *input) {
                register void *target asm("r0") = input;
                asm("" : "+r"(target));
                goto *target;
            }
        ''')[0], "c")

    def test_c_assignment_replaces_an_unused_assembly_output(self):
        self.assertEqual(quality.inspect_text('''
            void entry(void *input) {
                register void *target asm("r0");
                asm("" : "=r"(target));
                target = input;
                goto *target;
            }
        ''')[0], "c")

    def test_conditional_assignment_cannot_prove_a_c_jump_target(self):
        for statement in ("if (flag) target = input;", "while (flag) target = input;",
                          "flag && (target = input);", "flag ? (target = input) : 0;"):
            with self.subTest(statement=statement):
                self.assertNotEqual(quality.inspect_text(
                    'void entry(void *input, int flag) { '
                    'register void *target asm("lr"); asm("" : "=r"(target)); '
                    + statement + ' goto *target; }')[0], "c")

    def test_unbound_output_cannot_supply_a_c_value(self):
        for statement in ("return value;", "return value + 1;", "consume(value);",
                          "if (value) consume(1);", "value = value + 1;"):
            with self.subTest(statement=statement):
                self.assertNotEqual(quality.inspect_text(
                    'int entry(void) { register int value asm("r2"); '
                    'asm("" : "=r"(value)); ' + statement + ' }')[0], "c")

    def test_register_reservations_can_feed_other_empty_constraints(self):
        self.assertEqual(quality.inspect_text('''
            int entry(void) {
                register int scratch asm("r3");
                asm("" : "=r"(scratch));
                asm("" : : "r"(scratch));
                scratch = 7;
                return scratch;
            }
        ''')[0], "c")

    def test_cast_assignment_replaces_an_unused_output(self):
        self.assertEqual(quality.inspect_text('''
            int entry(int input) {
                register int value asm("r0");
                asm("" : "=r"(value));
                ((volatile int)value) = input;
                return value;
            }
        ''')[0], "c")

    def test_unconditional_assignment_after_control_flow_is_c(self):
        for statement in ("if (flag) { consume(1); }", "if (flag) consume(1);",
                          "goto assigned; assigned:", "while (flag) { consume(1); }"):
            with self.subTest(statement=statement):
                self.assertEqual(quality.inspect_text(
                    'int entry(int input, int flag) { register int value asm("r0"); '
                    'asm("" : "=r"(value)); ' + statement +
                    ' value = input; return value; }')[0], "c")

    def test_conditional_assignment_cannot_supply_a_c_value(self):
        for statement in ("if (flag) value = input;", "if (flag) { value = input; }",
                          "for (; flag; ) value = input;", "flag && (value = input);"):
            with self.subTest(statement=statement):
                self.assertNotEqual(quality.inspect_text(
                    'int entry(int input, int flag) { register int value asm("r0"); '
                    'asm("" : "=r"(value)); ' + statement + ' return value; }')[0], "c")

    def test_type_queries_do_not_read_an_unbound_output(self):
        for query in ("sizeof(value)", "sizeof value", "__typeof__(value)"):
            with self.subTest(query=query):
                text = ('int entry(int input) { register int value asm("r0"); '
                        'asm("" : "=r"(value)); ')
                text += query + ' copy = input;' if query == "__typeof__(value)" else 'int size = ' + query + ';'
                text += ' value = input; return value; }'
                self.assertEqual(quality.inspect_text(text)[0], "c")

    def test_later_tied_input_replaces_an_unused_output(self):
        self.assertEqual(quality.inspect_text('''
            int entry(int input) {
                register int value asm("r0");
                asm("" : "=r"(value));
                asm("" : "=r"(value) : "0"(input));
                return value;
            }
        ''')[0], "c")

    def test_nested_c_assignment_supplies_a_function_argument(self):
        self.assertEqual(quality.inspect_text('''
            int entry(void) {
                register int value asm("r0");
                asm("" : "=r"(value));
                value = consume(({ value = 7; value; }));
                return value;
            }
        ''')[0], "c")

    def test_c_assignment_is_valid_inside_its_conditional_scope(self):
        self.assertEqual(quality.inspect_text('''
            int entry(int input, int flag) {
                register int value asm("r0");
                asm("" : "=r"(value));
                switch (flag) {
                case 1:
                    value = input;
                    consume(value);
                    return value;
                }
                return 0;
            }
        ''')[0], "c")

    def test_type_cast_does_not_read_the_assignment_target(self):
        self.assertEqual(quality.inspect_text('''
            int entry(int input) {
                register int value asm("r0");
                asm("" : "=r"(value));
                value = (__typeof__(value))input;
                return value;
            }
        ''')[0], "c")

    def test_forward_jump_does_not_read_another_switch_case(self):
        self.assertEqual(quality.inspect_text('''
            int entry(int flag, int input) {
                register int value asm("r0") = input;
                switch (flag) {
                case 1:
                    asm("" : "=r"(value));
                    goto done;
                case 2:
                    consume(value);
                }
            done:
                return 0;
            }
        ''')[0], "c")

    def test_forward_jump_reaches_an_unbound_value_read(self):
        self.assertNotEqual(quality.inspect_text('''
            int entry(void) {
                register int value asm("r0");
                asm("" : "=r"(value));
                goto done;
                value = 7;
            done:
                return value;
            }
        ''')[0], "c")

    def test_unused_register_reservation_is_not_a_jump_target(self):
        self.assertEqual(quality.inspect_text('''
            int entry(void) {
                register int scratch asm("r3");
                asm("" : "=r"(scratch));
                return 1;
            }
        ''')[0], "c")

    def test_c_with_register_bindings_and_empty_barriers(self):
        state, issues = quality.inspect_text('''
            extern int target(int) asm("original_target");
            int update(int input) {
                register int value asm("r0") = input;
                asm volatile("" : "+r"(value) : : "memory");
                return value + 1;
            }
        ''')
        self.assertEqual((state, issues), ("c", ()))

    def test_quoted_symbol_alias_is_c(self):
        self.assertEqual(quality.inspect_text(
            'void alias(void) asm("\\\"original_target\\\""); void update(void) {}')[0], "c")

    def test_array_symbol_alias_is_c(self):
        self.assertEqual(quality.inspect_text(
            'extern int values[] asm("original_values"); int update(void) { return values[0]; }')[0], "c")

    def test_comment_and_string_do_not_count_as_assembly(self):
        self.assertEqual(quality.inspect_text(
            '/* asm("bx r0"); */ const char *name = "asm(\\\"nop\\\")"; '
            'int update(void) { return 1; }')[0], "c")

    def test_assembly_comment_emits_no_instruction(self):
        self.assertEqual(quality.inspect_text(
            'int update(void) { asm("@ compiler note"); return 1; }')[0], "c")

    def test_data_only_file_cannot_count_as_c_code(self):
        self.assertNotEqual(quality.inspect_text(
            'const unsigned short code[] = {0x4770};')[0], "c")

    def test_packed_struct_does_not_supply_a_function_body(self):
        self.assertNotEqual(quality.inspect_text(
            'struct __attribute__((packed)) Data { int value; }; '
            'const unsigned short code[] = {0x4770};')[0], "c")

    def test_complete_assembly_wrapper_is_not_c(self):
        state, issues = quality.inspect_text(
            '__attribute__((naked)) void call(void) { asm("bx r4\\n" "nop"); }')
        self.assertEqual(state, "assembly")
        self.assertTrue(issues)

    def test_register_jump_with_declaration_is_not_c(self):
        self.assertEqual(quality.inspect_text('''
            void entry(void) {
                register void *target asm("r2");
                asm volatile("adr %0, . + 4\\n\\tbx %0" : "=r"(target));
                __builtin_unreachable();
            }
        ''')[0], "assembly")

    def test_one_instruction_makes_a_mixed_body(self):
        self.assertEqual(quality.inspect_text('''
            int update(int value) {
                asm("add %0, %0, #1" : "+r"(value));
                return value;
            }
        ''')[0], "mixed")

    def test_top_level_instruction_is_not_a_symbol_alias(self):
        self.assertNotEqual(quality.inspect_text(
            'asm("nop"); int update(void) { return 1; }')[0], "c")

    def test_opcode_and_instruction_override_fail(self):
        for template in (".word 0xE12FFF1E", ".short 0x4770", ".incbin \\\"code.bin\\\"",
                         ".include \\\"fix.inc\\\"", ".macro mov dst, src\\n.endm"):
            with self.subTest(template=template):
                self.assertNotEqual(quality.inspect_text(
                    'asm("' + template + '"); int update(void) { return 1; }')[0], "c")

    def test_instruction_array_in_text_fails(self):
        self.assertNotEqual(quality.inspect_text('''
            const unsigned short code[] __attribute__((section(".text"))) = {0x4770};
        ''')[0], "c")

    def test_nonliteral_template_fails_closed(self):
        with self.assertRaisesRegex(ValueError, "literal strings"):
            quality.inspect_text('void update(void) { asm(template); }')

    def test_header_macros_are_checked_after_expansion(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/patch.h").write_text('#define PATCH asm(".short 0x4770")\n')
            source = root / "src/entry.c"
            source.write_text('#include "patch.h"\nvoid entry(void) { PATCH; }\n')
            self.assertEqual(quality.inspect_source(source, root, "src")[0], "assembly")

    def test_missing_include_fails_closed(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "entry.c"
            source.write_text('#include "not_found.h"\n')
            with self.assertRaisesRegex(ValueError, "Cannot preprocess"):
                quality.inspect_source(source, root, "src")

    def test_regions_with_c_and_assembly_do_not_count_as_c(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/entry.c").write_text('int entry(void) { return 1; }\n')
            (root / "src/bridge.s").write_text('bx r0\n')
            classes, _ = quality.classify_regions(root, {
                "one": ["entry.c"], "two": ["bridge.s"], "both": ["entry.c", "bridge.s"]})
            self.assertEqual(classes, {"one": "c", "two": "assembly", "both": "mixed"})

    def test_c_completion_rejects_missing_code_and_assembly_tails(self):
        regions = [("head", 0x100, 0x104), ("tail", 0x104, 0x120)]
        spans = [("function", 0x100, 0x120)]
        for classes in ({"head": "c", "tail": "assembly"},
                        {"head": "c", "tail": "mixed"}):
            with self.subTest(classes=classes), self.assertRaisesRegex(ValueError, "function"):
                quality.require_c_coverage(regions, classes, spans)
        with self.assertRaisesRegex(ValueError, "function"):
            quality.require_c_coverage(regions[:1], {"head": "c"}, spans)

    def test_c_completion_accepts_adjacent_c_regions_and_external_data(self):
        quality.require_c_coverage(
            [("head", 0x100, 0x104), ("tail", 0x104, 0x120), ("data", 0x200, 0x300)],
            {"head": "c", "tail": "c", "data": "assembly"}, [("function", 0x100, 0x120)])

    def test_empty_native_inventory_cannot_pass_completion(self):
        with self.assertRaisesRegex(ValueError, "inventory is empty"):
            quality.require_c_coverage([], {}, [])

    def test_compiled_coverage_excludes_data_stubs_and_zero_size_symbols(self):
        from types import SimpleNamespace
        from unittest import mock
        symbols = (
            "08000100 g F .text 00000004 update\n"
            "08000104 g O .text 00000004 hidden_code\n"
            "08000200 g F .stub_200 00000002 target\n"
            "08000300 g F .text 00000000 alias\n")
        with mock.patch.object(quality.subprocess, "run",
                return_value=SimpleNamespace(returncode=0, stdout=symbols)):
            self.assertEqual(quality.compiled_functions("region.elf"), [("update", 0x100, 0x104)])

    def test_unreadable_function_symbols_fail_closed(self):
        from types import SimpleNamespace
        from unittest import mock
        with mock.patch.object(quality.subprocess, "run",
                return_value=SimpleNamespace(returncode=1, stderr="invalid ELF")):
            with self.assertRaisesRegex(ValueError, "Cannot read compiled functions"):
                quality.compiled_functions("region.elf")

    def test_source_gate_rejects_duplicate_region_names_and_empty_inventory(self):
        import contextlib
        import io
        from unittest import mock
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            for text, reason in (
                ("entry 0x100 0x104 hidden.c\nentry 0x200 0x204 clean.c\n", "Duplicate region"),
                ("", "region list is empty")):
                with self.subTest(text=text):
                    (root / "regions.txt").write_text(text)
                    with mock.patch.object(quality, "__file__", str(root / "tools/c_quality.py")), \
                         mock.patch("sys.argv", ["c_quality"]), \
                         contextlib.redirect_stdout(io.StringIO()) as output:
                        self.assertEqual(quality.main(), 2)
                    self.assertIn(reason, output.getvalue())


if __name__ == "__main__":
    unittest.main()

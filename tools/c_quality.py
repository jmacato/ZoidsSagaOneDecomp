"""Check C source bodies before reporting C decompilation progress."""

import argparse
import ast
from bisect import bisect_right
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess


TOKENS = re.compile(
    r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|'
    r'[A-Za-z_]\w*|0[xX][0-9a-fA-F]+|\d+|[^\s]', re.S)
ASM = {"asm", "__asm", "__asm__"}
QUALIFIERS = {"volatile", "__volatile__", "goto", "inline", "__inline__"}
REGISTER = re.compile(r"(?:r(?:[0-9]|1[0-5])|ip|lr|sp|fp|sl|sb)")
SYMBOL = re.compile(r'"?[A-Za-z_][A-Za-z_0-9.]*"?')


def closing(tokens, start, left, right):
    depth = 0
    for end in range(start, len(tokens)):
        if tokens[end] == left:
            depth += 1
        elif tokens[end] == right:
            depth -= 1
            if depth == 0:
                return end
    raise ValueError(f"Unclosed {left} in preprocessed C.")


def inspect_text(text):
    tokens = [m.group() for m in TOKENS.finditer(text)
              if not m.group().startswith(("//", "/*"))]
    bodies = []
    prefix = []
    index = 0
    while index < len(tokens):
        token = tokens[index]
        if token == "{":
            end = closing(tokens, index, "{", "}")
            depth = 0
            function = False
            for position, value in enumerate(prefix[:-1]):
                if depth == 0 and prefix[position + 1] == "(" and \
                        re.fullmatch(r"[A-Za-z_]\w*", value) and value not in \
                        {"__attribute__", "__attribute", *ASM, "typeof", "__typeof__"}:
                    function = True
                if value == "(":
                    depth += 1
                elif value == ")":
                    depth -= 1
            if function and "=" not in prefix:
                bodies.append((index + 1, end))
            prefix = []
            index = end + 1
            continue
        if token == ";":
            prefix = []
        else:
            prefix.append(token)
        index += 1

    removed = set()
    issues = []
    unbound_outputs = []
    bound_outputs = []
    index = 0
    while index < len(tokens):
        if tokens[index] not in ASM:
            index += 1
            continue
        start = index
        index += 1
        while index < len(tokens) and tokens[index] in QUALIFIERS:
            index += 1
        if index == len(tokens) or tokens[index] != "(":
            raise ValueError("Cannot parse an assembly declaration.")
        end = closing(tokens, index, "(", ")")
        strings = []
        argument = index + 1
        while argument < end and tokens[argument].startswith('"'):
            strings.append(ast.literal_eval(tokens[argument]))
            argument += 1
        if not strings or (argument != end and tokens[argument] != ":"):
            raise ValueError("The assembly template must contain literal strings.")
        template = "".join(strings)
        in_body = any(low <= start < high for low, high in bodies)
        declarator = start > 0 and (tokens[start - 1] in {")", "]"} or
            re.fullmatch(r"[A-Za-z_]\w*", tokens[start - 1]))
        binding = declarator and argument == end and (
            REGISTER.fullmatch(template) or (not in_body and SYMBOL.fullmatch(template)))
        if not binding:
            removed.update(range(start, end + 1))
            if any(line.split("@", 1)[0].strip() for line in template.splitlines()):
                issues.append(template.splitlines()[0].strip())
            elif not template.strip() and in_body and argument < end:
                sections = [[]]
                depth = 0
                for value in tokens[argument + 1:end]:
                    if value == ":" and depth == 0:
                        sections.append([])
                    else:
                        sections[-1].append(value)
                    if value in {"(", "[", "{"}:
                        depth += 1
                    elif value in {")", "]", "}"}:
                        depth -= 1
                output_text = " ".join(sections[0])
                outputs = list(re.finditer(
                    r'(?:\[ (\w+) \] )?"([^"]+)" \(', output_text))
                inputs = {}
                if len(sections) > 1:
                    for k, value in enumerate(sections[1][:-1]):
                        if value.startswith('"') and sections[1][k + 1] == "(":
                            stop = closing(sections[1], k + 1, "(", ")")
                            inputs[ast.literal_eval(value)] = sections[1][k + 2:stop]
                high = next(high for low, high in bodies if low <= start < high)
                for position, output in enumerate(outputs):
                    name, constraint = output.groups()
                    operand = re.match(r"\s*(\w+)", output_text[output.end():])
                    if operand is None:
                        continue
                    variable = operand.group(1)
                    if not constraint.startswith("=") or not any(letter in constraint for letter in "rlhg"):
                        continue
                    key = str(position) if str(position) in inputs else "[" + name + "]" if name else None
                    if key in inputs:
                        if variable not in inputs[key]:
                            bound_outputs.append((end, variable))
                        continue
                    unbound_outputs.append((end, high, variable))
        index = end + 1

    for end, high, variable in unbound_outputs:
        body = [(k, tokens[k]) for k in range(end + 1, high) if k not in removed]
        values = [value for _, value in body]
        definitions = [at for at, name in bound_outputs if name == variable and end < at < high]
        braces = parentheses = 0
        conditional_scopes = set()
        pending_condition = None
        conditional_expression = False
        initialized_scope = None
        statement_start = 0
        cursor = 0
        while cursor < len(body):
            position = cursor
            at, value = body[position]
            cursor += 1
            if value == "goto" and not conditional_scopes and pending_condition is None and (
                    position + 1 < len(values) and re.fullmatch(r"[A-Za-z_]\w*", values[position + 1])):
                label = values[position + 1]
                target = next((k for k in range(position + 2, len(values) - 1)
                               if values[k:k + 2] == [label, ":"]), None)
                if target is not None:
                    definitions = [k for k in definitions if k >= body[target][0]]
                    cursor = target + 2
                    statement_start = cursor
                    continue
            if value == "?" or values[position:position + 2] in (["&", "&"], ["|", "|"]):
                conditional_expression = True
            if value in {"case", "default"} and initialized_scope in conditional_scopes:
                initialized_scope = None
            if value in {"if", "else", "for", "while", "switch", "?"} or values[position:position + 2] in (
                    ["&", "&"], ["|", "|"]):
                pending_condition = parentheses
            if value == "{":
                braces += 1
                if pending_condition == parentheses:
                    conditional_scopes.add(braces)
                    pending_condition = None
            elif value == "}":
                conditional_scopes.discard(braces)
                braces = max(0, braces - 1)
                if initialized_scope is not None and initialized_scope > braces:
                    initialized_scope = None
            elif value == "(":
                parentheses += 1
            elif value == ")":
                parentheses = max(0, parentheses - 1)
            if definitions and definitions[0] < at:
                scope = max(conditional_scopes, default=0)
                if conditional_expression or pending_condition == parentheses:
                    scope = -1
                if scope == 0:
                    break
                initialized_scope = scope
                definitions.pop(0)
            if value == ";" and parentheses == 0:
                pending_condition = None
                conditional_expression = False
                if initialized_scope == -1:
                    initialized_scope = None
                statement_start = position + 1
            if value != variable or initialized_scope is not None:
                continue
            if position and values[position - 1] in {".", "goto", "sizeof"}:
                continue
            if position > 1 and values[position - 1] == "(" and values[position - 2] in {
                    "sizeof", "typeof", "__typeof", "__typeof__"}:
                continue
            after = position + 1
            while after < len(values) and values[after] == ")":
                after += 1
            if after < len(values) and values[after] == "=" and (
                    after + 1 == len(values) or values[after + 1] != "="):
                stop = next((k for k in range(after + 1, len(values)) if values[k] == ";"), len(values))
                reads_variable = any(values[k] == variable and not (
                    (k and values[k - 1] == "sizeof") or
                    (k > 1 and values[k - 1] == "(" and values[k - 2] in {
                        "sizeof", "typeof", "__typeof", "__typeof__"}))
                    for k in range(after + 1, stop))
                if not reads_variable:
                    scope = max(conditional_scopes, default=0)
                    if conditional_expression or pending_condition == parentheses:
                        scope = -1
                    if scope == 0:
                        break
                    initialized_scope = scope
                continue
            if any(values[k:k + 2] == ["goto", "*"] for k in range(statement_start, position)):
                issues.append("Computed jump uses an unbound assembly output")
            issues.append("C value comes from an unbound assembly output: " + variable)
            break

    # Data in an executable section can hide instruction bytes in a C initializer.
    for index, token in enumerate(tokens):
        if token in {"section", "__section__"} and index + 2 < len(tokens):
            value = tokens[index + 2]
            if value.startswith('"') and ast.literal_eval(value).startswith(".text"):
                issues.append("C data in an executable section")

    if not bodies:
        issues.append("No C function body")
    if not issues:
        return "c", ()
    only_assembly = bool(bodies)
    for low, high in bodies:
        residual = " ".join(tokens[i] for i in range(low, high) if i not in removed)
        residual = re.sub(r"__builtin_unreachable\s*\(\s*\)\s*;", "", residual)
        residual = re.sub(r"\bregister\s+[^;=]+;", "", residual)
        if residual.strip(" ;{}"):
            only_assembly = False
    return "assembly" if only_assembly else "mixed", tuple(dict.fromkeys(issues))


def inspect_source(source, root, include):
    source = Path(source)
    if not source.is_file():
        raise ValueError(f"Source is unavailable: {source}")
    if source.suffix == ".s":
        return "assembly", ()
    if source.suffix != ".c":
        raise ValueError(f"Unsupported source extension: {source}")
    result = subprocess.run(
        ["cc", "-E", "-P", "-I", str(root / include), str(source)],
        cwd=root, capture_output=True, text=True)
    if result.returncode:
        raise ValueError(f"Cannot preprocess {source}: {result.stderr.strip()}")
    return inspect_text(result.stdout)


def classify_regions(root, regions, include="src"):
    paths = {path for sources in regions.values() for path in sources}
    with ThreadPoolExecutor(max_workers=8) as pool:
        results = dict(zip(sorted(paths), pool.map(
            lambda path: inspect_source(root / "src" / path, root, include), sorted(paths))))
    classes = {}
    for name, sources in regions.items():
        states = {results[path][0] for path in sources}
        classes[name] = next(iter(states)) if len(states) == 1 else "mixed"
    return classes, results


def compiled_functions(elf, base=0x08000000):
    result = subprocess.run(
        ["arm-none-eabi-objdump", "-t", str(elf)], capture_output=True, text=True)
    if result.returncode:
        raise ValueError(f"Cannot read compiled functions: {result.stderr.strip()}")
    spans = []
    for line in result.stdout.splitlines():
        fields = line.split()
        if len(fields) == 6 and fields[2:4] == ["F", ".text"]:
            start, size = int(fields[0], 16), int(fields[4], 16)
            if size:
                spans.append((fields[5], start - base, start - base + size))
    return spans


def require_c_coverage(regions, classes, spans):
    if not spans:
        raise ValueError("The native code inventory is empty.")
    covered = []
    for name, low, high in sorted(regions, key=lambda region: region[1]):
        if classes[name] != "c":
            continue
        if covered and low <= covered[-1][1]:
            covered[-1] = (covered[-1][0], max(high, covered[-1][1]))
        else:
            covered.append((low, high))
    starts = [low for low, _ in covered]
    missing = []
    for label, low, high in spans:
        index = bisect_right(starts, low) - 1
        if index < 0 or not low < high <= covered[index][1]:
            missing.append(label)
    if missing:
        raise ValueError(f"C completion omits {len(missing)} native spans; first: {missing[0]}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--include", default="src")
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    regions = {}
    try:
        for raw in (root / "regions.txt").read_text().splitlines():
            fields = raw.split("#", 1)[0].split()
            if not fields:
                continue
            if len(fields) not in {4, 5}:
                raise ValueError(f"Invalid region: {raw}")
            name = fields[0]
            if name in regions:
                raise ValueError(f"Duplicate region: {name}")
            sources = fields[3].split(",")
            for source in sources:
                path = Path(source)
                if path.is_absolute() or ".." in path.parts:
                    raise ValueError(f"Invalid source path: {source}")
            regions[name] = sources
        if not regions:
            raise ValueError("The region list is empty.")
        classes, results = classify_regions(root, regions, args.include)
        failed = 0
        for path, (state, issues) in sorted(results.items()):
            if path.endswith(".c") and state != "c":
                failed += 1
                print(f"FAIL src/{path}: {state}; {issues[0]}")
        for state in ("c", "mixed", "assembly"):
            print(f"{state}: {sum(value == state for value in classes.values())} regions")
        return int(bool(failed))
    except (OSError, ValueError) as error:
        print(f"Source quality failed: {error}")
        return 2


if __name__ == "__main__":
    raise SystemExit(main())

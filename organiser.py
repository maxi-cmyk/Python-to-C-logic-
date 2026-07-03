import os
import re
import shutil
from pathlib import Path

TAG_MAPPING = {
    "linked_list": "Data-Structures/Linked-Lists",
    "tree": "Data-Structures/Trees",
    "binary_search": "Algorithms/Binary-Search",
    "two_pointers": "Algorithms/Two-Pointers",
    "bit_manipulation": "Algorithms/Bit-Manipulation",
    "arrays": "Data-Structures/Arrays",
    "greedy": "Algorithms/Greedy",
    "sliding_window": "Algorithms/Sliding-Window",
    "math": "Algorithms/Math",
    "backtracking": "Algorithms/Backtracking",
    "stack": "Data-Structures/Stack",
    "matrix_manipulation": "Data-Structures/Matrix-Manipulation",
    "hashing": "Data-Structures/Hashing",
    "dp": "Algorithms/Dynamic-Programming",
    "bfs": "Algorithms/Breath-First-Search",
}

IGNORE_NAMES = {
    "organiser.py",
    "organizer.py",
    "README.md",
    ".gitignore",
    "template.py",
    ".vscode",
}
BASE_GOAL = 150
GOAL_STEP = 50
PROBLEM_FILE_PATTERN = re.compile(r"^(?P<num>\d+)[_-](?P<slug>.+)\.py$")

#reformat some names
NAME_REPLACEMENTS = {
    "Bst": "BST",
    "Ii": "II",
    "Iii": "III",
    "Iv": "IV",
    "Vi": "VI",
    "Vii": "VII",
    "Viii": "VIII",
    "Ix": "IX",
    "Ip": "IP",
    "Myatoi": "My Atoi",
    "Reversebits": "Reverse Bits",
}

README_HEADER = """# leetcode stuffs

This repository tracks my journey in Data Structures and Algorithms.
I solve problems in Python to understand the logic, then translate them to C to do memory management and pointers.

"""


def get_tag_from_file(filepath):
    """Scan for hashtags like #linked_list or #greedy."""
    try:
        with open(filepath, "r", encoding="utf-8") as file:
            content = file.read(1000)
            matches = re.findall(r"#(\w+)", content.lower())
            for tag in matches:
                if tag in TAG_MAPPING:
                    return tag
    except Exception as error:
        print(f"Error reading {filepath}: {error}")
    return "other"


def is_problem_file(filename):
    return filename not in IGNORE_NAMES and PROBLEM_FILE_PATTERN.match(filename) is not None


def format_problem_name(slug):
    name = slug.replace("_", " ").replace("-", " ").title()
    for source, target in NAME_REPLACEMENTS.items():
        name = re.sub(rf"\b{re.escape(source)}\b", target, name)
    return name


def get_problem_info(filename):
    match = PROBLEM_FILE_PATTERN.match(filename)
    if not match:
        raise ValueError(f"Unsupported problem filename: {filename}")

    number = match.group("num")
    name = format_problem_name(match.group("slug"))
    return number, name


def get_goal(total):
    if total <= BASE_GOAL:
        return BASE_GOAL

    milestones_hit = (total - BASE_GOAL + GOAL_STEP - 1) // GOAL_STEP
    return BASE_GOAL + (milestones_hit * GOAL_STEP)


def write_c_template(c_path, source_name):
    with open(c_path, "w", encoding="utf-8") as file:
        file.write(
            f"// Practice for: {source_name}\n"
            "// Bridge logic from Python to C pointers here.\n\n"
            "#include <stdio.h>\n"
            "#include <stdlib.h>\n\n"
            "int main() {\n"
            "    return 0;\n"
            "}\n"
        )


def organize():
    # --- PHASE 1: SCAN AND MOVE ---
    for source_dir in (Path("."), Path("Other")):
        if not source_dir.exists():
            continue

        for source_path in source_dir.iterdir():
            if not source_path.is_file() or not is_problem_file(source_path.name):
                continue

            tag = get_tag_from_file(source_path)
            target_dir = Path(TAG_MAPPING.get(tag, "Other"))
            target_dir.mkdir(parents=True, exist_ok=True)

            destination = target_dir / source_path.name
            if source_path.resolve() != destination.resolve():
                shutil.move(str(source_path), str(destination))
                source_path = destination
                print(f"Categorized: {source_path.name} -> {target_dir.as_posix()}")

            c_path = target_dir / source_path.with_suffix(".c").name
            if not c_path.exists():
                write_c_template(c_path, source_path.name)

    # --- PHASE 2: GENERATE README ---
    table_rows = []
    for root, dirs, files in os.walk("."):
        dirs[:] = [directory for directory in dirs if directory not in {".git", "__pycache__", "Other"}]
        if "Other" in Path(root).parts:
            continue

        for file in files:
            if not is_problem_file(file):
                continue

            python_path = Path(root, file)
            c_path = python_path.with_suffix(".c")
            if not c_path.exists():
                write_c_template(c_path, file)

            number, name = get_problem_info(file)
            rel_path = python_path.as_posix().removeprefix("./")
            c_rel_path = rel_path.removesuffix(".py") + ".c"
            category = Path(root).as_posix().removeprefix("./")
            if category == ".":
                category = "Root"

            row = f"| {number} | {name} | {category} | [Python]({rel_path}) | [C]({c_rel_path}) |"
            table_rows.append((int(number), name, row))

    table_rows.sort(key=lambda item: (item[0], item[1]))

    total = len(table_rows)
    goal = get_goal(total)
    percent = min(100, (total / goal) * 100)
    bar = "█" * int(20 * percent // 100) + "░" * (20 - int(20 * percent // 100))

    with open("README.md", "w", encoding="utf-8") as file:
        file.write(README_HEADER)
        file.write(f"### 📈 Progress: {total}/{goal}\n`{bar}` {percent:.1f}%\n\n")
        file.write("## 📚 Problem Library\n\n| # | Name | Category | Logic | C Practice |\n|---|------|----------|-------|------------|\n")
        for _, _, row in table_rows:
            file.write(row + "\n")

    print(f"README updated with {total} problems. Progress: {percent:.1f}%")
    print("remember to update obsidian if necessary!!!!")


if __name__ == "__main__":
    organize()

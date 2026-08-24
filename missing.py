#!/usr/bin/env python3
"""List Python questions whose C practice has not been attempted yet."""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


PROBLEM_FILE_PATTERN = re.compile(r"^\d+[_-].+\.py$")
SKIPPED_DIRECTORIES = {".git", "__pycache__", ".venv", "venv"}


@dataclass(frozen=True)
class MissingAttempt:
    python_path: Path
    c_path: Path
    reason: str


def c_template(source_name: str) -> str:
    """Return the untouched template written by organiser.py."""
    return (
        f"// Practice for: {source_name}\n"
        "// Bridge logic from Python to C pointers here.\n\n"
        "#include <stdio.h>\n"
        "#include <stdlib.h>\n\n"
        "int main() {\n"
        "    return 0;\n"
        "}\n"
    )


def find_unattempted(root: Path) -> list[MissingAttempt]:
    """Find problem files with an absent or untouched C counterpart."""
    root = root.resolve()
    missing: list[MissingAttempt] = []

    for python_path in root.rglob("*.py"):
        relative_path = python_path.relative_to(root)
        if any(part in SKIPPED_DIRECTORIES for part in relative_path.parts):
            continue
        if not PROBLEM_FILE_PATTERN.match(python_path.name):
            continue

        c_path = python_path.with_suffix(".c")
        if not c_path.exists():
            missing.append(MissingAttempt(python_path, c_path, "missing"))
        elif c_path.read_text(encoding="utf-8") == c_template(python_path.name):
            missing.append(MissingAttempt(python_path, c_path, "template"))

    return sorted(
        missing,
        key=lambda item: item.python_path.relative_to(root).as_posix().lower(),
    )


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="List Python questions that still need a C attempt."
    )
    parser.add_argument(
        "root",
        nargs="?",
        type=Path,
        default=Path(__file__).resolve().parent,
        help="repository to scan (default: the directory containing missing.py)",
    )
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    root = args.root.resolve()

    if not root.is_dir():
        print(f"error: not a directory: {root}")
        return 2

    missing = find_unattempted(root)
    if not missing:
        print("All Python questions have a C attempt.")
        return 0

    print(f"C questions left to attempt: {len(missing)}\n")
    for item in missing:
        relative_c_path = item.c_path.relative_to(root)
        label = "file absent" if item.reason == "missing" else "untouched template"
        print(f"- {relative_c_path.as_posix()} ({label})")

    return 1


if __name__ == "__main__":
    raise SystemExit(main())

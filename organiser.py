import os
import shutil

# 1. Configuration
MAPPING = {
    "linked_list": "Data-Structures/Linked-Lists",
    "tree": "Data-Structures/Trees",
    "search": "Algorithms/Binary-Search",
    "zero": "Algorithms/Two-Pointers",
    "element": "Algorithms/Two-Pointers",
    "binary": "Algorithms/Bit-Manipulation",
    "merge": "Algorithms/Two-Pointers",
    "sqrt": "Algorithms/Binary-Search"
}

README_HEADER = """Leetcode stuffs

This repository tracks my journey into learning Data Structures and Algorithms. I solve problems in Python to master the logic, then translate them to C to master memory management.

## Problem Tracker

| # | Name | Category | Code | Practice |
|---|------|----------|------|----------|
"""

def get_problem_info(filename):
    """Extracts number and name from '0001_two_sum.py'"""
    parts = filename.split('_')
    num = parts[0]
    # Rejoin the rest and remove .py, then capitalize
    name = " ".join(parts[1:]).replace(".py", "").title()
    return num, name

def organize_and_update_readme():
    # --- PHASE 1: ORGANIZE NEW FILES ---
    for filename in os.listdir('.'):
        if filename.endswith(".py") and filename != "organizer.py":
            target_folder = "Other"
            for keyword, folder in MAPPING.items():
                if keyword in filename.lower():
                    target_folder = folder
                    break
            
            if not os.path.exists(target_folder):
                os.makedirs(target_folder)
            
            # Create scaffold C file
            c_filename = filename.replace(".py", ".c")
            c_path = os.path.join(target_folder, c_filename)
            if not os.path.exists(c_path):
                with open(c_path, 'w') as f:
                    f.write("// TODO: Translate the Python logic into C\n#include <stdio.h>\n")
            
            # Move the Python file
            shutil.move(filename, os.path.join(target_folder, filename))
            print(f"Organized: {filename}")

    # --- PHASE 2: GENERATE README ---
    table_rows = []
    
    # Walk through folders to find all solutions
    for root, dirs, files in os.walk("."):
        for file in files:
            if file.endswith(".py") and "_" in file and file != "organizer.py":
                num, name = get_problem_info(file)
                # Get the relative path for the links
                rel_path = os.path.join(root, file).replace("./", "")
                c_rel_path = rel_path.replace(".py", ".c")
                category = root.split(os.sep)[-1]
                
                row = f"| {num} | {name} | {category} | [Python]({rel_path}) | [C]({c_rel_path}) |"
                table_rows.append((num, row))

    # Sort by problem number
    table_rows.sort()
    
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(README_HEADER)
        for _, row in table_rows:
            f.write(row + "\n")
    
    print("README.md has been updated")

if __name__ == "__main__":
    organize_and_update_readme()

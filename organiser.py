import os
import shutil
import re

# 1. Configuration: Hashtags mapped to folder paths
TAG_MAPPING = {
    "linked_list": "Data-Structures/Linked-Lists",
    "tree": "Data-Structures/Trees",
    "binary_search": "Algorithms/Binary-Search",
    "two_pointers": "Algorithms/Two-Pointers",
    "bit_manipulation": "Algorithms/Bit-Manipulation",
    "arrays": "Data-Structures/Arrays",
    "greedy": "Algorithms/Greedy",
    "sliding_window": "Algorithms/Sliding-Window",
    "math":"Algorithms/Math",
    "backtracking":"Algorithms/Backtracking",
    "stack":"Data-Structures/Stack",
    "matrix_manipulation": "Data-Structures/Matrix-Manipulation",
    "hashing":"Data-Structures/Hashing"
}

# Files to ignore
IGNORE_LIST = ["organizer.py", "README.md", ".gitignore", "template.py"]
GOAL = 50  

README_HEADER = """# leetcode stuffs

This repository tracks my journey in Data Structures and Algorithms. 
I solve problems in Python to understand the logic, then translate them to C to do memory management and pointers.

"""

def get_tag_from_file(filepath):
    """Scans for hashtags like #linked_list or #greedy"""
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read(1000) 
            # check for matching
            matches = re.findall(r'#(\w+)', content.lower())
            for tag in matches:
                if tag in TAG_MAPPING:
                    return tag
    except Exception as e:
        print(f"Error reading {filepath}: {e}")
    return "other"

def get_problem_info(filename):
    parts = filename.split('_')
    num = parts[0]
    name = " ".join(parts[1:]).replace(".py", "").title()
    return num, name

def organize():
    # --- PHASE 1: SCAN AND MOVE ---
    # Scans root and 'Other' for re-categorization
    for s_dir in ['.', 'Other']:
        if not os.path.exists(s_dir): continue
        for filename in os.listdir(s_dir):
            if filename.endswith(".py") and "_" in filename and filename not in IGNORE_LIST:
                filepath = os.path.join(s_dir, filename)
                tag = get_tag_from_file(filepath)
                target_path = TAG_MAPPING.get(tag, "Other")
                
                if not os.path.exists(target_path):
                    os.makedirs(target_path)
                
                # Move if in wrong place
                new_path = os.path.join(target_path, filename)
                shutil.move(filepath, new_path)
                
                # Create C practice file
                c_filename = filename.replace(".py", ".c")
                c_path = os.path.join(target_path, c_filename)
                if not os.path.exists(c_path):
                    with open(c_path, 'w') as f:
                        f.write(f"// Practice for: {filename}\n// Bridge logic from Python to C pointers here.\n\n#include <stdio.h>\n#include <stdlib.h>\n\nint main() {{\n    return 0;\n}}\n")
                
                print(f"✅ Categorized: {filename} -> {target_path}")

    # --- PHASE 2: GENERATE README ---
    table_rows = []
    for root, dirs, files in os.walk("."):
        if ".git" in root or "Other" in root: continue
        for file in files:
            if file.endswith(".py") and "_" in file and file not in IGNORE_LIST:
                num, name = get_problem_info(file)
                rel_path = os.path.join(root, file).replace("./", "").replace("\\", "/")
                c_rel_path = rel_path.replace(".py", ".c")
                category = root.replace("./", "").replace("\\", "/")
                
                row = f"| {num} | {name} | {category} | [Python]({rel_path}) | [C]({c_rel_path}) |"
                table_rows.append((num, row))

    table_rows.sort()
    
    # Progress Bar Logic
    total = len(table_rows)
    percent = min(100, (total / GOAL) * 100)
    bar = '█' * int(20 * percent // 100) + '░' * (20 - int(20 * percent // 100))
    
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(README_HEADER)
        f.write(f"### 📈 Progress: {total}/{GOAL}\n`{bar}` {percent:.1f}%\n\n")
        f.write("## 📚 Problem Library\n\n| # | Name | Category | Logic | C Practice |\n|---|------|----------|-------|------------|\n")
        for _, row in table_rows:
            f.write(row + "\n")
            
    print(f" README updated with {total} problems. Progress: {percent:.1f}%")

if __name__ == "__main__":
    organize()
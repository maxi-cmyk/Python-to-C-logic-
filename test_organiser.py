import os
import tempfile
import unittest
from pathlib import Path

import organiser


class OrganiserTests(unittest.TestCase):
    def test_creates_c_template_for_problem_already_in_category(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            previous_dir = Path.cwd()
            os.chdir(temp_dir)
            try:
                python_path = Path("Data-Structures/Stack/0232_implement_queue_stack.py")
                python_path.parent.mkdir(parents=True)
                python_path.write_text("#stack\n", encoding="utf-8")

                organiser.organize()

                self.assertTrue(python_path.with_suffix(".c").exists())
            finally:
                os.chdir(previous_dir)


if __name__ == "__main__":
    unittest.main()

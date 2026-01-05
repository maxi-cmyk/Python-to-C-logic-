#matrix_manipulation

from collections import defaultdict
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        #hashing, store rols and cols, make sure no dupes (1-9)
        #[rows][cols]
        #use tuples

        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set) # 3x3 

        for r in range(9): 
            for c in range(9):
                if board[r][c] == ".":
                    continue
                # r//3 and c//3 is to access sub boxes 
                if board[r][c] in rows[r] or board[r][c] in cols[c] or board[r][c] in boxes[(r // 3, c // 3)]:
                    return False
                
                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                boxes[(r // 3, c // 3)].add(board[r][c])
        return True



        
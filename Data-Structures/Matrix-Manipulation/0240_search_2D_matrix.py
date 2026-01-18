#matrix_manipulation
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #staircase comparison, binary search 
        #start top right, if smaller move left 
        #if bigger move down

        r = 0
        c = len(matrix[0]) - 1
        while r < len(matrix) and c >= 0:
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] < target:
                c -= 1
            else:
                r += 1
        return False



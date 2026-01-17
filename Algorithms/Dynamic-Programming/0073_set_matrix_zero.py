#dynamic_programming

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        first_row_zero = False #if any of them have a zero, all must be zero 
        first_col_zero = False

        #check first row and col 
        for i in range(cols):
            if matrix[0][i] == 0:
                first_row_zero = True
                break

        for j in range(rows):
            if matrix[j][0] == 0:
                first_col_zero = True
                break

        #check matrix excluding first row and col
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(1, rows): 
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
                    
        if first_row_zero:
            for i in range(cols):
                matrix[0][i] = 0
        if first_col_zero:
            for j in range(rows):
                matrix[j][0] = 0

            

        
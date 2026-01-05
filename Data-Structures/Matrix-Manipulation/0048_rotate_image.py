#matrix_manipulation
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #reverse first, then transpose 
        #reverse by swapping rows
        #transpose, swap upper right triangle with lower left 
        length = len(matrix)
        top = 0
        bottom = length - 1

        while top < bottom:
            for col in range(length): #swapping rows
                temp = matrix[top][col]
                matrix[top][col] = matrix[bottom][col]
                matrix [bottom][col] = temp
            top += 1
            bottom -= 1
        
        for row in range(length): #transpose
            for col in range(row+1, length):
                temp = matrix[row][col]
                matrix[row][col] = matrix[col][row]
                matrix[col][row] = temp
        return matrix


        
#matrix_manipulation

class Solution:
    def spiralOrder(self, matrix):
     #dx, dy = -dy, dx, change when out of bounds 
        rows, cols = len(matrix), len(matrix[0])
        r, c, dr, dc = 0, 0, 0, 1
        res = []

        for _ in range(rows*cols):
            res.append(matrix[r][c])
            matrix[r][c] = "." #seen 
            if not (0 <= r + dr < rows and 0 <= c + dc < cols and matrix[r+dr][c+dc] != "."):
                dr, dc = dc, -dr #change when out of bounds 
            r += dr
            c += dc
        return res



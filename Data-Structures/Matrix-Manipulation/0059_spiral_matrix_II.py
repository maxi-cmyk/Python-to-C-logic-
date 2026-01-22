#matrix_manipulation

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        r, c, dr, dc = 0, 0, 0, 1 #change right FIRST!
        #make matrix 
        res = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n*n):
            res[r][c] = i + 1
            #check if out of range or if it has a number
            if not (0 <= r + dr < n and 0 <= c + dc < n and res[r+dr][c+dc] == 0):
                dr, dc = dc, -dr #change when out of bounds 
            r += dr
            c += dc
        return res

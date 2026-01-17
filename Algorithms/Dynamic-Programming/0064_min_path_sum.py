#dynamic_programming
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        #fill first row 
        for c in range(1, cols):
            grid[0][c] += grid[0][c-1]
        #fill first col  
        for r in range(1, rows):
            grid[r][0] += grid[r-1][0]
        
        #fill the rest, take min of left and up
        for r in range(1, rows):
            for c in range(1, cols):
                grid[r][c] += min(grid[r-1][c], grid[r][c-1])

        return grid[rows-1][cols-1] #final sum 


        


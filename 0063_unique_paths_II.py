class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        #if grid[m][n] == 1, cannot
        #in-place trick, rewrite all possible paths to sum of [top] + [left]
        #rewrite such that 1 means 1 possible path, 0 means not possible 

        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[rows-1][cols-1] == 1:
            return 0

        obstacleGrid[0][0] = 1
        #fill first row
        for i in range(1, cols):
            if obstacleGrid[0][i] == 0 and obstacleGrid[0][i-1] == 1: #current path is clear, previous path clear
                obstacleGrid[0][i] = 1 #reachable
            else: 
                obstacleGrid[0][i] = 0 #rock
        #fill first col 
        for j in range(1, rows):
            if obstacleGrid[j][0] == 0 and obstacleGrid[j-1][0] == 1:
                obstacleGrid[j][0] = 1 #reachable
            else: 
                obstacleGrid[j][0] = 0 #rock
        #fill rest
        for i in range(1, rows):
            for j in range(1, cols):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] += obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else: #obstacle
                    obstacleGrid[i][j] = 0

        return obstacleGrid[rows-1][cols-1]


        
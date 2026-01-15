#backtracking

from functools import cache #makes a hash map in the background
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #DP[r][c] = DP[r-1][c] + DP[r][c-1]
        @cache
        def dfs(r, c): 
            if r >= m or c >= n:
                return 0
            if r == m-1 or c == n-1: #reached the end 
                return 1
            return dfs(r+1, c) + dfs(r, c+1)
        return dfs(0,0)

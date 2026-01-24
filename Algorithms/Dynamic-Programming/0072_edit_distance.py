#dynamic_programming

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #if first word length < second, delete 
        #vice versa, insert 
        #else modify letter
        cache = {}
        #i is number of deletions
        #j is number of insertions
        def dp(i,j):
            if(i,j) in cache:
                return cache[(i,j)]
            if i == 0:
                return j
            if j == 0:
                return i
            if word1[i-1] == word2[j-1]:
                res = dp(i-1, j-1)
            else:
                res = 1 + min(
                    dp(i-1, j), #delete 
                    dp(i, j-1), #insert 
                    dp(i-1, j-1) #replace
                )
            cache[(i,j)] = res
            return res
        return dp(len(word1), len(word2))


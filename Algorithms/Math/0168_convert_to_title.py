#math
#time complexity -> O(log N), space compelxity -> 0(log N)
#rhink of crushing 1 million to 0, only take 5 steps. 

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ""
        #right to left

        while columnNumber > 0:
            columnNumber -= 1
            #convert to char, add to res
            res = chr((columnNumber % 26) + ord("A")) + res
            #cycle to next 
            columnNumber //= 26
        return res
#dynamic_programming

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        #iCj
        res = [1] * (rowIndex+1)
        up = rowIndex 
        down = 1
        for i in range(1, rowIndex):
            #multiply numerator and demoniator by next term 
            res[i] = res[i-1] * up//down
            up = up - 1
            down = down + 1
        return res
#sliding_window

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        #move down then up, go back up when max rows is hit 
        if numRows == 1 or numRows >= len(s):
            return s
        idx, d = 0, 1
        #empty 2d array 
        rows = [[] for _ in range(numRows)]
        for char in s:
            rows[idx].append(char)
            if idx == 0:
                d = 1
            elif idx == numRows - 1:
                d = -1 
            idx += d
        
        for i in range (numRows):
            rows[i] = ''.join(rows[i])

        return ''.join(rows)
        
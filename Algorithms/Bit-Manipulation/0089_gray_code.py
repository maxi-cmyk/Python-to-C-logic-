#bit_manipulation

class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        #diff by one bit, 2 represents bit length
        #XOR?, bitshift 
        res = []
        total_num = 1 << n 
        for i in range(total_num):
            res.append(i ^ (i >> 1))
        return res
#greedy
#since making a choice today does not impact choices made the next day, use greedy 
# o(1) space, o(n) time

#when to use greedy? -> keywords like maximum, moinimum, any optimisation problem
#if we can sort the data and make a single obvious pass in o(n) time, its greedy algo

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        #start at index 1
        for i in range(1, len(prices)):
            #greedy algo trick, find immediate profit 
            #telescoping sum (terms cancel e/o out)
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        return profit
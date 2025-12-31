#greedy

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return zero
            
        buy_price = prices[0] 
        profit = 0
        #start from index 1
        for p in prices [1:]:
            if buy_price > p:
                buy_price = p #lowest price to buy 
            profit = max(profit, p - buy_price)
        return profit



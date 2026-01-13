#greedy
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        total = 0
        for i in nums:
            if total < 0:
                total = 0
            total += i 
            res = max(res, total)
        return res

        
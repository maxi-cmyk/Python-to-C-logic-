 #two_pointers
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # i + j = 0 - k 
        res = []
        nums.sort() 

        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]: #have to skip duplicates!
                continue
            j = i + 1
            k = len(nums) - 1 #let k start at the end 
            while j < k:
                total = nums[i] + nums[j] + nums[k]
            
                if total < 0:
                    j += 1
                elif total > 0:
                    k -= 1
                else: 
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1 
                    while j < k and nums[j] == nums[j-1]: #have to skip duplicates!
                        j += 1
        return res


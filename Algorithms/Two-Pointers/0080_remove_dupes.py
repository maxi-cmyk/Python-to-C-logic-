#two_pointers
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #each element appears at most twice, return k, num elements
        #O(n), and need to modify in place for O(1)
        #start from third element
        k = 2
        for i in range(2, len(nums)):
            #if it is not the same, change third repeated to new value
            if nums[i] != nums[k-2]:
                nums[k] = nums[i]
                k += 1
        return k


#two_pointers
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        while i > 0 and nums[i-1] >= nums[i]: #find first decreasing element(pivot)
            i-=1
        if i == 0: #edge case, no pivot, just return list 
            nums.reverse()
            return

        j = len(nums) - 1 #find smallest element from right og pivot that is larger than pivot
        while j >= 1 and nums[j] <= nums[i-1]:
            j-=1

        nums[i-1], nums[j] = nums[j], nums[i-1] #swap pivot and other 
        nums[i:] = reversed(nums[i:]) #reverse after pivot 

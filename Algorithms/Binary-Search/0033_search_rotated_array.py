#binary_search

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #Olog(n) -> binary search variant? 
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] >= nums[left]: #left side is sorted 
                if nums[left] <= target <= nums[mid]: #target is somewhere here 
                    right = mid - 1
                else: 
                    left = mid + 1
            else: #right side is sorted
                if nums[mid] <= target <= nums[right]: #target is somewhere here 
                    left = mid + 1
                else: 
                    right = mid - 1
        return -1
                    






        
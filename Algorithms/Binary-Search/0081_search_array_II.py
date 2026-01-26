#binary_search 

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        #binary search again 
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                return True

            #skip dupe
            if nums[left] == nums[mid]:
                left += 1
                continue

            #sorted left
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else: 
                    left = mid + 1
            #sorted right 
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else: 
                    right = mid - 1
        return False


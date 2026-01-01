class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        #two_pointers 
        # -4, -1, 1, 2  target: 1, output = 
        nums.sort()
        result = nums[0] + nums[1] + nums[2] #guess
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
                
            left = i + 1
            right = len(nums) - 1

            while left < right:
                curr_sum = nums[i] + nums[left] + nums[right]

                if abs(target - curr_sum) < abs(target - result): #check how close 
                    result = curr_sum
                
                if curr_sum == target:
                    return target
                elif curr_sum < target:
                    left += 1 
                else: 
                    right -= 1 
        return result

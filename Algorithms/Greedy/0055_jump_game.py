#greedy
class Solution:
    def canJump(self, nums) -> bool:
        goal = len(nums) - 1
        #iterate from back 
        for i in range(len(nums) - 2, -1, -1):
            if i + nums[i] >= goal:
                goal = i
        #return true if reached first index
        return goal == 0 


        


        
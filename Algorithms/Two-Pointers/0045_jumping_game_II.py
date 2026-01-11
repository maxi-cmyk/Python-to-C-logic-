#two_pointers

class Solution:
    def jump(self, nums) -> int:
        near = far = jumps = 0
        while far < len(nums) - 1:
            max_dist = 0  
            for i in range(near, far + 1): #(curr, furthest distance possible)
                max_dist = max(max_dist, i + nums[i]) #max dist

            near = far + 1 #take minimum step 
            far = max_dist #maximum step
            jumps+= 1

        return jumps


        
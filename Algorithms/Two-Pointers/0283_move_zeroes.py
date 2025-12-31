#two_pointers

class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        #swapping values 
        left = 0
        for right in range(len(nums)):
            if nums[right] != 0:
                nums[right], nums[left] = nums[left], nums[right] #swap values 
                #need to use a temp variable for the swap
                left += 1
                #move left pointer 
        return nums
    
# Test Block
sol = Solution()

test_cases = [
    [0, 1, 0, 3, 12],
    [0, 0, 0],
    [1, 2, 3, 4],
    [0],
    [1, 2, 0, 0]
]

for case in test_cases:
    # We pass a copy [:] so the original test_case isn't changed between prints
    original = case[:]
    sol.moveZeroes(case)
    print(f"Original: {original} -> Result: {case}")


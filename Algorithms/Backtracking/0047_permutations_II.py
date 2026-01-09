#backtracking 
# The Universal Backtracking Loop Template
# for i in range(start, end):
#     if condition_to_skip:
#         continue
    
    # 1. Choose
    # 2. Recurse
    # 3. Un-choose (Backtrack)

class Solution:
    def permuteUnique(self, nums):
        #all will have the same length
        nums.sort()
        res = []
        used = [False] * len(nums)

        def dfs(path):
            if len(path) == len(nums):
                res.append(path[:])
                return
            
            for i in range(len(nums)):
                if used[i]:
                    continue
                #check used[i-1] is false to prevent dupe answer
                if i > 0 and nums[i-1] == nums[i] and not used[i-1]:
                    continue
                    #choose this path 
                used[i] = True
                path.append(nums[i])
                    
                dfs(path) #call function

                path.pop() #undo, remove first element
                used[i] = False

        dfs([]) #pass in a list, not index 
        return res
    
if __name__ == "__main__":
    sol = Solution()
    
    test_cases = [
        # (Input, Expected Output Length, Expected Contents)
        ([1, 1, 2], 3, [[1,1,2], [1,2,1], [2,1,1]]),
        ([1, 2, 3], 6, [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]),
        ([2, 2, 1, 1], 6, [
            [1,1,2,2], [1,2,1,2], [1,2,2,1],
            [2,1,1,2], [2,1,2,1], [2,2,1,1]
        ])
    ]

    print("--- Testing #47 Permutations II ---")
    for nums, exp_len, exp_content in test_cases:
        actual = sol.permuteUnique(nums)
        
        # Sort for comparison
        actual_sorted = sorted([sorted(x) for x in actual])
        expected_sorted = sorted([sorted(x) for x in exp_content])
        
        status = "✅ PASS" if len(actual) == exp_len and actual_sorted == expected_sorted else "❌ FAIL"
        
        print(f"{status} | Input: {nums}")
        print(f"   Expected Length: {exp_len}, Got: {len(actual)}")
        if status == "❌ FAIL":
            print(f"   Actual output: {actual}")
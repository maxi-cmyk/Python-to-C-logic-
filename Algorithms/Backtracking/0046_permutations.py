#backtracking

class Solution:
    def permute(self, nums):
        #all will have the same length
        res = []
        used = [False] * len(nums)

        def dfs(path):
            if len(path) == len(nums):
                res.append(path[:])
                return

            for i in range(len(nums)):
                if not used[i]:
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
        ([1, 2, 3], [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]),
        ([0, 1], [[0,1],[1,0]]),
        ([1], [[1]])
    ]

    print("--- Testing #46 Permutations ---")
    for nums, exp in test_cases:
        actual = sol.permute(nums)
        # Sort results for easier comparison
        actual_sorted = sorted(actual)
        expected_sorted = sorted(exp)
        
        status = "✅ PASS" if actual_sorted == expected_sorted else "❌ FAIL"
        print(f"{status} | Input: {nums}\n   Got: {actual_sorted}")


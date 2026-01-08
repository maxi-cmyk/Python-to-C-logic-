#backtracking 

class Solution:
    def subsetsWithDup(self, nums):
        #return powerset, [], [all], [some combination in between]
        #dfs
        nums.sort()
        res = []

        def dfs (start, path):
            res.append(path[:])
            for i in range(start, len(nums)):
                #compare with prev
                if i > start and nums[i] == nums[i-1]:
                    continue
                path.append(nums[i])
                dfs(i+1, path)
                path.pop() #backtrack 
        dfs(0, [])
        return res

if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([1, 2, 2], [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]),
        ([0], [[], [0]])
    ]

    print("--- Testing #90 Subsets II ---")
    for nums, exp in test_cases:
        actual = sol.subsetsWithDup(nums)
        actual_sorted = sorted([sorted(x) for x in actual])
        expected_sorted = sorted([sorted(x) for x in exp])
        status = "✅ PASS" if actual_sorted == expected_sorted else "❌ FAIL"
        print(f"{status} | Input: {nums}\n   Got: {actual_sorted}")

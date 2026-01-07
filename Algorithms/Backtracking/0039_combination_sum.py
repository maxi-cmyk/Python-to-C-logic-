class Solution(object):
    def combinationSum(self, candidates, target):
        #backtracking, dfs
        res = []
        self.dfs(candidates, target, [], res)
        return res

    def dfs(self, nums, target, curr, res): #recursion part 
        if target < 0:
            return 
        if target == 0:
            res.append(curr)
            return
        for i in range(len(nums)):
            self.dfs(nums[i:], target - nums[i], curr+[nums[i]], res)

if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([2, 3, 6, 7], 7, [[2, 2, 3], [7]]),
        ([2, 3, 5], 8, [[2, 2, 2, 2], [2, 3, 3], [3, 5]]),
        ([2], 1, [])
    ]

    print("--- Testing #39 Combination Sum ---")
    for candidates, tar, exp in test_cases:
        actual = sol.combinationSum(candidates, tar)
        # Sort internal lists and the outer list for easy comparison
        actual_sorted = sorted([sorted(x) for x in actual])
        expected_sorted = sorted([sorted(x) for x in exp])
        status = "✅ PASS" if actual_sorted == expected_sorted else "❌ FAIL"
        print(f"{status} | Input: {candidates}, Target: {tar}\n   Got: {actual_sorted}")
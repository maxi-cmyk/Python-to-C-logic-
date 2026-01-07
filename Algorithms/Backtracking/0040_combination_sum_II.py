#backtracking
class Solution:
    def combinationSum2(self, candidates, target):
        #dfs
        candidates.sort() #output is sorted anyway so sort first to handle dupes 
        res = []

        def dfs(target, start, curr): 
            if target < 0: #no valid sequence 
                return 
            if target == 0: 
                res.append(curr)
                return
            for i in range(start, len(candidates)): 
                #skip dupes
                if i > start and candidates[i] == candidates[i-1]:
                    continue
                if candidates[i] > target: #skip > target
                    break
                dfs(target-candidates[i], i+1, curr + [candidates[i]])

        dfs(target, 0, [])
        return res 

if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([10, 1, 2, 7, 6, 1, 5], 8, [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]),
        ([2, 5, 2, 1, 2], 5, [[1, 2, 2], [5]])
    ]

    print("\n--- Testing #40 Combination Sum II ---")
    for candidates, tar, exp in test_cases:
        actual = sol.combinationSum2(candidates, tar)
        actual_sorted = sorted([sorted(x) for x in actual])
        expected_sorted = sorted([sorted(x) for x in exp])
        status = "✅ PASS" if actual_sorted == expected_sorted else "❌ FAIL"
        print(f"{status} | Input: {candidates}, Target: {tar}\n   Got: {actual_sorted}")


        
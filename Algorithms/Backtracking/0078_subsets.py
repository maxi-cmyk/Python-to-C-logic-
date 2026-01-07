#backtracking

class Solution:
    def subsets(self, nums):
        #return powerset, [], [all], [some combination in between]
        #dfs
        res = []
        subset = []

        def make_subset(i):
            if i == len(nums): #3 -> 1,2,3
                res.append(subset[:])
                return
            
            subset.append(nums[i]) #1
            make_subset(i+1) #2,...

            subset.pop() #remove last element, 1,2
            make_subset(i+1) #next set without nums[i]

        make_subset(0)
        return res

if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([1, 2, 3], [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]),
        ([0], [[], [0]])
    ]

    print("\n--- Testing #78 Subsets ---")
    for nums, exp in test_cases:
        actual = sol.subsets(nums)
        actual_sorted = sorted([sorted(x) for x in actual])
        expected_sorted = sorted([sorted(x) for x in exp])
        status = "✅ PASS" if actual_sorted == expected_sorted else "❌ FAIL"
        print(f"{status} | Input: {nums}\n   Got: {actual_sorted}")
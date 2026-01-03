#two_pointers
class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        results = []
        
        def findNSum(l, r, target, N, result):
            # edge cases: not enough elements or target out of possible range
            if r - l + 1 < N or N < 2 or target < nums[l] * N or target > nums[r] * N:
                return
            
            # Base Case: 2Sum
            if N == 2:
                while l < r:
                    curr = nums[l] + nums[r]
                    if curr == target:
                        results.append(result + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l-1]: 
                            l += 1
                    elif curr < target:
                        l += 1
                    else:
                        r -= 1
            else:
                # reduce N-Sum to (N-1)-Sum
                for i in range(l, r + 1):
                    if i == l or (i > l and nums[i] != nums[i-1]):
                        findNSum(i + 1, r, target - nums[i], N - 1, result + [nums[i]])

        findNSum(0, len(nums) - 1, target, 4, [])
        return results

def test_4sum():
    sol = Solution()
    
    # Case 1: Standard case with zero target
    assert sol.fourSum([1, 0, -1, 0, -2, 2], 0) == [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]
    
    # Case 2: All same numbers
    assert sol.fourSum([2, 2, 2, 2, 2], 8) == [[2, 2, 2, 2]]
    
    # Case 3: Large Target (Testing your sum logic)
    assert sol.fourSum([1000000000, 1000000000, 1000000000, 1000000000], 4000000000) == [[1000000000]*4]
    
    # Case 4: Not enough elements
    assert sol.fourSum([1, 2, 3], 0) == []

    print("✅ Python 4Sum tests passed!")
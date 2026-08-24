class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        #duplicate with a distance of k from i 
        #j = i - k - 1

        seen = set()
        for i, val in enumerate(nums): 
            #check if i > k, if so, remove last element in queue
            if i > k: 
                seen.remove(nums[i-k-1])
            if val in seen: 
                return True
            seen.add(val)
        return False
        
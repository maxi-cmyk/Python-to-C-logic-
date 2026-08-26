class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        if not nums: 
            return res
        start = nums[0]
        end = nums[0]

        for n in nums[1:]:
            #consecutive 
            if n == end + 1:
                end = n
            else: 
                if start == end: 
                    res.append(str(start))
                else: 
                    res.append(str(start) + "->" + str(end))
                start = n
                end = n
                #at the end 
        if start == end: 
            res.append(str(start))
        else: 
            res.append(str(start) + "->" + str(end))
        return res

        
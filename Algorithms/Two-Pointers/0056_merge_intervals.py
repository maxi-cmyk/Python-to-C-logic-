#two_pointers

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #match overlapping intervals -> if curr start < prev end, merge 
        #sort first 
        merged = []
        intervals.sort(key=lambda x: x[0])

        prev = intervals[0]

        for interval in intervals[1:]:
            if interval[0] <= prev[1]: #overlap
                prev[1] = max(prev[1], interval[1])
            else:
                merged.append(prev)
                prev = interval
        merged.append(prev)
        return merged

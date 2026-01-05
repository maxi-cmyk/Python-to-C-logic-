from typing import Optional
from collections import defaultdict
#hashing
# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         #sort by lexicons, see which match and group 
#         res = defaultdict(list) #if a key does not exist in dict, create empty list 
#         for s in strs:
#             key = "".join(sorted(s)) #sort each string alphabetically
#             res[key].append(s)
#         return list(res.values())

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #frequency_map 
        res = defaultdict(list)
        for s in strs:
            freq = [0]*26 #make new array 
            for c in s:
                freq[ord(c) - ord("a")] += 1
            res[tuple(freq)].append(s)
        return list(res.values())

        

        
        
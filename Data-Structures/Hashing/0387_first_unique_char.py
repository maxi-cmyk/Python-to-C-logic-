#hashing

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        #hash table, return first repeated char index
        freq = [0] * 26
        for c in s: 
            freq[ord(c)- ord("a")] += 1
        
        for i, c in enumerate(s): 
            if freq [ord(c)- ord("a")] == 1: 
                return i 

        return -1
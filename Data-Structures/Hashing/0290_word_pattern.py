#hashing

class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        #bijection, every letter maps to exactly 1 unique word
        #every word maps to exactly 1 unique letter 
        #one hash map(key, value)

        words = s.split(" ")
        if len(pattern) != len(words):
            return False 
        seen = {}
        for p, w in zip(pattern, words): 
            key_p = ("p", p)
            key_w = ("w", w)
            #check against each set
            if key_p in seen and seen[key_p] != w:
                return False
            if key_w in seen and seen[key_w] != p: 
                return False
            seen[key_p] = w
            seen[key_w] = p
        return True
         
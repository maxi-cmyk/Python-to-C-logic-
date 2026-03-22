#hashing

#time complexity is o(n) 
#space complexity is o(1) because ASCII characters are finite (256)

class Solution(object):
    def isIsomorphic(self, s, t):
        #bijection 
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        #store all found chars in a hashmap 
        #chars in s are keys, chars in t are values 
        #check if keys/values exists, no 2 keys can have the same value 

        char_map = {}
        #another hashmap for tc
        seen = set()

        #use zip to iterate multiple lists at once
        for sc, tc in zip(s, t): 
            #check if it exists in char_map
            if sc in char_map: 
                #same key mapping twice, cannot
                if char_map[sc] != tc: 
                    return False
            #check if tc exists already
            elif tc in seen: 
                return False
            
            char_map[sc] = tc 
            seen.add(tc);
            
        return True 



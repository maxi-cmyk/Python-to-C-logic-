#bit_manipulation
from collections import defaultdict

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        masks = defaultdict(int)

        for word in words:
            mask = 0
            for char in word:
                #use OR operator 
                mask |= (1 << (ord(char) - ord('a')))
            #keep longest length of word if we see it again
            masks[mask] = max(masks[mask], len(word))
        max_prod = 0

        #use list to skip over anagrams
        mask_list = list(masks.items())
        for i in range(len(mask_list)):
            m1, len1 = mask_list[i]
            for j in range(i + 1, len(mask_list)):
                m2, len2 = mask_list[j]
                if not (m1 & m2):
                    max_prod = max(max_prod, len1 * len2)
                    
        return max_prod

        
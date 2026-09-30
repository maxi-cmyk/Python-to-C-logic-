#hashing

class Solution:
    def findWords(self, words: list[str]) -> list[str]:
        # only 1 row of american keyboard 
        # check if word is a subset of line 
        line1, line2, line3 = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')
        res = []
        for word in words: 
            w = set(word.lower())
            # <= is subset operator
            if w <= line1 or w <= line2 or w <= line3: 
                res.append(word)
        return res
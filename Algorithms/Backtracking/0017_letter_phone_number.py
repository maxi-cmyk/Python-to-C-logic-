char#backtracking
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        #hashtable
        if not digits:
            return []
            #dict 
        digit_to_letters = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }

        def convert(idx, comb):
            if idx == len(digits):
                res.append(comb[:])
                return
            for letter in digit_to_letters[digits[idx]]:
                convert(idx + 1, comb + letter)
        res = []
        convert(0, "")
        return res
                
            
        

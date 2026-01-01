#math 

class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        i = 0
        while i < len(s) and s[i] == ' ': #traverse whitespaces 
            i+=1

        if i == len(s): #all whitespaces
            return 0

        sign = 1
        if s[i] == '-': 
            sign = -1
            i+=1 #traverse sign
        elif s[i] == '+': 
            sign = 1
            i+=1 #traverse sign

        res = 0
        while i < len(s) and s[i].isdigit():
            digit = int(s[i])
            res = res * 10 + digit

            #constraints 
            if sign*res <= INT_MIN:
                return INT_MIN
            if sign*res >= INT_MAX:
                return INT_MAX

            i+=1 #traverse 
        
        return res * sign

def test_atoi():
    sol = Solution()
    
    # 1. Standard Case
    assert sol.myAtoi("42") == 42
    
    # 2. Leading Whitespace & Negative Sign
    assert sol.myAtoi("   -42") == -42
    
    # 3. Reading Digits with Non-Digit Suffix
    assert sol.myAtoi("4193 with words") == 4193
    
    # 4. Words First (Should return 0)
    assert sol.myAtoi("words and 987") == 0
    
    # 5. Out of Range (Positive Overflow)
    assert sol.myAtoi("91283472332") == 2147483647 # INT_MAX
    
    # 6. Out of Range (Negative Overflow)
    assert sol.myAtoi("-91283472332") == -2147483648 # INT_MIN

    # 7. Edge Case: Just a sign
    assert sol.myAtoi("-") == 0

    print("✅ All Python test cases passed!")

if __name__ == "__main__":
    test_atoi()

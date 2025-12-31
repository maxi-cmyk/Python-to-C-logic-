#sliding_window

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s: 
            return ""

        def expand_around_center(left: int, right: int):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1 #subtract 1 to compensate 
            
        start = 0
        end = 0

        for i in range(len(s)):
            odd_length = expand_around_center(i, i)
            even_length = expand_around_center(i, i + 1)
            curr_max = max(odd_length, even_length)

            if curr_max > (end - start):
                start = i - (curr_max - 1) // 2 #divide by 2 as it is a palindrome 
                end = i + curr_max // 2

        return s[start : end + 1]

def test_palindrome():
    sol = Solution()
    
    # Case 1: Standard odd-length
    assert sol.longestPalindrome("babad") in ["bab", "aba"]
    
    # Case 2: Standard even-length
    assert sol.longestPalindrome("cbbd") == "bb"
    
    # Case 3: Single character
    assert sol.longestPalindrome("a") == "a"
    
    # Case 4: All same characters
    assert sol.longestPalindrome("aaaaa") == "aaaaa"
    
    # Case 5: No palindrome longer than 1
    assert len(sol.longestPalindrome("ac")) == 1

    print("✅ All Python test cases passed!")

if __name__ == "__main__":
    test_palindrome()
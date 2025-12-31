#math
class Solution:
    def reverse(self, x: int) -> int:
        negative = False
        if x < 0:
            negative = True
            x *= -1
        total = 0
        while x > 0:
            total = total * 10 + x % 10
            x //= 10
            
        if total > 2**31 -1:
            return 0

        if negative:
            return total *-1
        else: 
            return total
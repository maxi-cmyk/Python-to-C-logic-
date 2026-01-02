#math
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # handle overflow
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        
        # Determine the sign
        negative = (dividend < 0) != (divisor < 0)
        
        a = abs(dividend)
        b = abs(divisor)
        res = 0
        
        while a >= b:
            temp_divisor = b
            multiple = 1
            # shifting bits to the left to stimulate multiply by 2 
            while a >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            
            # Subtract the largest chunk we found
            a -= temp_divisor
            res += multiple
            
        return -res if negative else res


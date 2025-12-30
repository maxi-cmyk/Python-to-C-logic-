class Solution:
    def mySqrt(self, x: int) -> int:
        #brute force 
        #if x < 2:
            #return x
        #i = 2
        #while i * i <= x:
            #i+= 1
        #return i - 1
        
        #binary search 
        if x < 2:
            return x
        left = 1
        right = x // 2 #integer division! 

        while left <= right:
            mid = (left + right) // 2 #left + (right-left) // 2 in C to prevent overflow 
            square = mid * mid #rmb to use long in C 

            if square == x:
                return mid 
            elif square < x:
                left = mid + 1
            else:
                right = mid -1

        return right
        
sol = Solution()

test_cases = [
    (0, 0),
    (1, 1),
    (2, 1),
    (4, 2),
    (8, 2),
    (15, 3),
    (16, 4),
    (2147395599, 46339)
]

print("--- Sqrt(x) Test Results ---")
for x, expected in test_cases:
    result = sol.mySqrt(x)
    status = "PASS" if result == expected else f"FAIL (Expected {expected}, got {result})"
    print(f"sqrt({x}): {result} {status}")       
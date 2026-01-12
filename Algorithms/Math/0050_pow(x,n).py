#math
class Solution:
    def myPow(self, x: float, n: int) -> float:
        #x^n = x^n(1/2) * x^n(1/2) for Olog(n)
        #res = x ^ n(1/2)
        #if n is even, res = res * res, if n is odd, res = res * res * x
        #if n is < 1, return 1/ans
        #recursive loop 
        if n == 0: 
            return 1
        if x == 0: 
            return 0

        def calc(base, exp):
            if exp == 0:
                return 1
            res = calc(base, exp // 2)
            res = res * res 
            if exp % 2 == 1:
                res = res * base
            return res

        ans = calc(x,abs(n))
        if n < 0:
            return 1/ans 
        return ans
#math
# class Solution:
#     def multiply(self, num1: str, num2: str) -> str:
#        a = int(num1)
#        b = int(num2)
#        return str(a*b)

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        #loop through and multiply each
        #return result array 
        n = len(num1)
        m = len(num2)
        result = [0] * (n+m) #num digits in result array
        if (n == 0 or m == 0):
            return "0"
        
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                pdt = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                sum = pdt + result[i+j+1]
                result[i+j+1] = sum % 10 #last digit 
                result[i+j] += sum//10 #carry

        #use lstrip to remove left trailing zeroes
        product = ''.join(map(str, result)).lstrip('0')
        return product if product else "0"
    

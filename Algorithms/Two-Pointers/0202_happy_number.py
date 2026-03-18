#two_pointers

class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # positive, replace num with sum of square of digits until = 1

        def next_num(n):
            output = 0

            while n: 
                digit = n % 10 
                output += digit ** 2
                n = n // 10

            return output
        
        slow = next_num(n)
        #move fast ptr twice as fast 
        fast = next_num(next_num(n))

        while slow != fast: 
            if fast == 1: return True 
            slow = next_num(slow)
            fast = next_num(next_num(fast))
        
        return slow == 1
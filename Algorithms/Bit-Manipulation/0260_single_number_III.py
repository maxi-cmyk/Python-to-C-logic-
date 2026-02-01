#bit_manipulation

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for num in nums:
            xor ^= num
        #(-xor) flips the bits and adds 1, twos compliment
        diff_bit = xor & (-xor)

        a = b = 0
        for num in nums: 
            if diff_bit & num:
                a ^= num
            else:
                b ^= num 

        return [a,b]            


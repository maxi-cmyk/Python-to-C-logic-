#bit_manipulation
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ones = 0
        twos = 0

        for num in nums:
            #XOR
            ones ^= (num & ~twos)
            twos ^= (num & ~ones)
            
        return ones

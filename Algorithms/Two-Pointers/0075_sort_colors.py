#two_pointers
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #red is 0, white is 1, blue is 2 
        red = 0
        white = 0
        blue = len(nums) - 1

        while white <= blue:
            if nums[white] == 0:
                #swap to shift red in front 
                nums[white], nums[red] = nums[red], nums[white]
                red += 1
                white += 1
            elif nums[white] == 1:
                white += 1
            else:
                #shift to back 
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1

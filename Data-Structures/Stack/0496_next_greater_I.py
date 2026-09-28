class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        # first greater element to the right of x 
        # if no greater, return -1
        # find idx j such that nums1[i] == nums2[j], determine next greater element in nums2

        stack = []
        next_greater = {}

        for num in nums2: 
            while stack and num > stack[-1]:
                smaller = stack.pop()
                # this maps num > smaller 
                next_greater[smaller] = num
            # add to top stack new greatest
            stack.append(num)
        # according to nums1, target references smaller
        return [next_greater.get(target, -1) for target in nums1]

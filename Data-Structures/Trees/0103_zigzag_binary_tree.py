#trees
#fifo
#time complexity -> o(n), space complexity -> o(n) 
#use deque here to stop extra memory work -> if use list, popping lement results in empty slot and all elemnts have to shift
#deque is a doubly-linked list, so when pop elemnt, only that element is affected -> every single popleft is o(1) time

from typing import Optional 
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # root, left to right, right to left, ... 
        if not root: 
            return []
        result = []
        queue = deque([root])
        left_to_right = True 

        while queue: 
            level_size = len(queue)
            current_level = [0] * level_size

            for i in range (level_size): 
                node = queue.popleft()
                #check if left or right, if right take the first right
                index = i if left_to_right else level_size - 1 - i 
                current_level[index] = node.val 
                if node.left: 
                    queue.append(node.left)
                if node.right: 
                    queue.append(node.right)
            
            result.append(current_level)
            left_to_right = not left_to_right

        return result

        
#backtracking 

from typing import Optional 

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        first = None
        second = None
        prev = None
        
        def inorder(node):
            nonlocal first, second, prev
            if not node:
                return

            inorder(node.left)
            
            if prev and prev.val > node.val:
                #first drop
                if not first:
                    first = prev
                    second = node 
                #second drop
                else:
                    second = node 
            
            #update prev
            prev = node
            
            inorder(node.right)
            
        inorder(root)
        
        #swap vals
        if first and second:
            first.val, second.val = second.val, first.val
        
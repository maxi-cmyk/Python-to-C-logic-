#trees

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        #LIFO, process left child first always
        res= []

        if not root: 
            return res
        
        #initalise stack 
        st = [root]

        #pop current element, then add it to res
        while st:
            node = st.pop()
            res.append(node.val)

            if node.right:
                st.append(node.right)
            
            if node.left:
                st.append(node.left)
        return res
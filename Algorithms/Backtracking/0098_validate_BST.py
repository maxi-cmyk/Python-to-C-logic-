#backtracking

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def valid(node, minimum, maximum):
            if not node: 
                return True
            
            if not (node.val > minimum and node.val < maximum):
                return False
            #left must be smaller, right must be bigger 
            return valid(node.left, minimum, node.val) and valid(node.right, node.val, maximum)
            
        return valid (root, float("-inf"), float("inf"))
        
#backtracking 

from typing import Optional

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
         
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        def dfs(node, path, currSum):
            if not node: 
                return
            currSum += node.val
            path.append(node.val)
            
            #reach end, meet target
            if not node.left and not node.right and currSum == targetSum:
                res.append(path[:])
            dfs(node.left, path, currSum)
            dfs(node.right, path, currSum)
            
            #dont match, pop
            path.pop()
        dfs(root, [], 0)
        return res


        
#tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root: # if(root == NULL)
            return   # return NULL
        
        temp = root.left 
        root.left = root.right 
        root.right = temp

        #struct TreeNode *temp = root->left;
        #root->left = root->right;
        #root->right = temp;

        self.invertTree(root.left) #for the left child and their children
        self.invertTree(root.right) #for the right child and their children
        
        #invertTree(root->left)
        #invertTree(root->right)
        
        return root

        
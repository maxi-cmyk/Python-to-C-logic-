// Practice for: 0094-binary_tree_inorder.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode* root, int* res, int* idx){
    //use *idx to get a count of how many values 
    if (root == NULL){
        return;
    }
    //go left
    traverse(root->left, res, idx);
    //go root
    res[(*idx)++] = root->val;
    //go right
    traverse(root->right, res, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    traverse(root, res, returnSize);
    
    return res;
}
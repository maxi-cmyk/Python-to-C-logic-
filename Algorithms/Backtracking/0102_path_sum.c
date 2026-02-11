// Practice for: 0102_path_sum.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum){
    if (root == NULL){
        return false;
    }
    if (root->left == NULL && root->right == NULL){
        return (targetSum - root->val) == 0;
    }
    targetSum -= root-> val;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
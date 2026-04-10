// Practice for: 0098_validate_BST.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

struct TreeNode {
    int val; 
    struct TreeNode *left;
    struct TreeNode *right;
}; 

bool validate(struct TreeNode* node, long long min_val, long long max_val) {
    if (node == NULL){
        return true;
    }

    //fail condition
    if (node->val <= min_val || node->val >= max_val){
        return false;
    }

    return validate(node->left, min_val, node->val) && validate(node->right, node->val, max_val);

}

bool isValidBST(struct TreeNode *root){
    return validate(root, LLONG_MIN, LLONG_MAX);
}


// Practice for: 0110_balanced_tree.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfsHeight(struct TreeNode* node){
    if (node == NULL){
        return 0;
    }

    int leftHeight = dfsHeight(node->left);
    if (leftHeight == -1){
        return -1;
    }

    int rightHeight = dfsHeight(node->right);
    if (rightHeight == -1){
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1){
        return -1;
    }
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode *root){
    return dfsHeight(root) != -1;
}

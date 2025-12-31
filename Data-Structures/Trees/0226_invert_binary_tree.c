// Practice for: 0226_invert_binary_tree.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    // 1. Base Case
    if (root == NULL) {
        return NULL;
    }

    // 2. The Swap (Standard C swap logic)
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 3. The Recursive Calls
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

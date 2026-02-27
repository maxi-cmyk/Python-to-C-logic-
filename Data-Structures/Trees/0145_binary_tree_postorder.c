// Practice for: 0145_binary_tree_postoder.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void dfs(struct TreeNode *node, int* res, int *returnSize){
    if (node == NULL){
        return;
    }

    dfs(node ->left, res, returnSize);
    dfs(node -> right, res, returnSize);
    res[(*returnSize)++] = node->val;
}

int* postorderTraversal(struct TreeNode *root, int* returnSize){
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    dfs(root, res, returnSize);
    return res;

}
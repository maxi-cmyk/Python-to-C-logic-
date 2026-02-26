// Practice for: 0144_binary_tree_preorder.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode *root, int *returnSize){
    //LIFO, always look at left child first 
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL){
        return res;
    }
    
    struct TreeNode *stack[100];
    int top = 0;

    stack[top++] = root;

    while (top > 0){
        //pop top element 
        struct TreeNode *node = stack[--top];
        res[(*returnSize)++] = node -> val;

        if (node->right){
            stack[top++] = node->right;
        }

         if (node->left){
            stack[top++] = node->right;
        }
    }
    return res;
}



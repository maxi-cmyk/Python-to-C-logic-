// Practice for: 0103_zigzag_binary_tree.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct TreeNode {
    int val; 
    struct TreeNode* left; 
    struct TreeNode* right;
};

int* zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL){
        *returnSize = 0; 
        *returnColumnSizes = 0; 
        return NULL;
    }

    int** res = (int**)malloc(2000 * sizeof(int*)); 
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int)); 
    *returnSize = 0; 

    struct TreeNode* queue[2000];
    int head = 0; 
    int tail = 0; 

    //place root here first
    queue[tail++] = root;
    int left_to_right = 1;

    while (head < tail){ 
        int levelSize = tail - head; 
        int* currentLevel = (int*)malloc(levelSize * sizeof(int)); 
        //col is top to bottom, row is left to right
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++){
            struct TreeNode* node = queue[head++];
            int index = left_to_right ? i : (levelSize - 1 - i);
            currentLevel[index] = node->val;

            if(node->left != NULL) queue[tail++] = node->left;
            if(node->right != NULL) queue[tail++] = node->right;
        }
        res[*returnSize] = currentLevel; 
        (*returnSize)++;
        left_to_right = !left_to_right;
    }
    return res;
}

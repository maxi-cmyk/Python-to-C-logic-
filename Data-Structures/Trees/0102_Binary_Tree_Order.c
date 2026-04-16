// Practice for: 0102_Binary_Tree_Order.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

//bfs, fifo (queue)
struct TreeNode {
    int val; 
    struct TreeNode *left; 
    struct TreeNode *right; 
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    //empty tree
    if (root == NULL) {
        *returnSize = 0; 
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** res = (int**)malloc(2000 * sizeof(int*)); 
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int)); 
    *returnSize = 0; 

    struct TreeNode* queue[2000]; 
    int head = 0; 
    int tail = 0;

    //place root in queue
    queue[tail++] = root; 

    //go level by level 
    while (head < tail){
        //num of elements inside this level 
        int levelSize = tail - head; 

        //allocate an array just for this specific level
        int* currentLevel = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        //just this level
        for (int i = 0; i < levelSize; i++){
            struct TreeNode* node = queue[head++];

            //record this value for this level 
            currentLevel[i] = node->val;

            if (node->left != NULL){
                queue[tail++] = node->left;
            }
            if (node->right != NULL){
                queue[tail++] = node->right;
            }
        }
        res[*returnSize] = currentLevel; 
        (*returnSize)++;
    }
    return res;
}


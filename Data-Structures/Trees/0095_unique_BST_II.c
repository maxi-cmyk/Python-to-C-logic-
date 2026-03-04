// Practice for: 0095_unique_BST_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val; 
    struct TreeNode *left; 
    struct TreeNode *right;
};

struct TreeNode* createNode(int val, struct TreeNode* left, struct TreeNode* right) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

struct TreeNode** generate_trees(int start, int end, int* returnSize){
    if (start > end){
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[0] = NULL;
        *returnSize = 1;
        return res;
    }

    int max_trees = 10000;
    struct TreeNode** all_trees = (struct TreeNode**)malloc(max_trees * sizeof(struct TreeNode*));
    int total_trees = 0;

    for (int i = start; i <= end; i++){
        int leftSize;
        //pass &leftSize so we know exactly how many trees in left_trees
        struct TreeNode** left_trees = generate_trees(start, i-1, &leftSize);
        int rightSize;
        //pass &rightSize so we know exactly how many trees in right_trees
        struct TreeNode** right_trees = generate_trees(i+1, end, &rightSize);

        for (int left = 0; left < leftSize; left++){
            for (int right = 0; right < rightSize; right++){
                struct TreeNode* root = createNode(i, left_trees[left], right_trees[right]);
                all_trees[total_trees] = root;
                total_trees++;
            }
        }
        free(left_trees);
        free(right_trees);
    }
    *returnSize = total_trees;
    return all_trees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generate_trees(1, n, returnSize);
}
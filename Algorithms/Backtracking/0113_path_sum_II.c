// Practice for: 0113_path_sum_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void dfs(struct TreeNode* node, int targetSum, int currentSum, int* currentPath, int depth, int** result, int* returnSize, int** returnColumnSizes){
    if (node == NULL){
        return;
    }
    currentSum += node->val;
    currentPath[depth] = node->val;

    //valid 
    if (node->left == NULL && node->right == NULL && currentSum == targetSum){
        int* newPath = (int*)malloc((depth + 1) * sizeof(int));

        //copy from buffer to mem, overwrite on next 
        for (int i = 0; i <= depth; i++){
            newPath[i] = currentPath[i];
        }
        result[*returnSize] = newPath;
        (*returnColumnSizes)[*returnSize] = depth + 1;
        (*returnSize)++;
        return;
    }

    dfs(node->left, targetSum, currentSum, currentPath, depth + 1, result, returnSize, returnColumnSizes);
    dfs(node->right, targetSum, currentSum, currentPath, depth + 1, result, returnSize, returnColumnSizes);
}

int** pathSum(struct TreeNode *root, int targetSum, int* returnSize, int** returnColSize){
    *returnSize = 0;
    *returnColSize = (int*)malloc(1000 * sizeof(int));
    int** result = (int**)malloc(1000 *sizeof(int*));
    int* currentPath = (int*)malloc(1000 *sizeof(int));
    dfs(root, targetSum, 0, currentPath, 0, result, returnSize, returnColSize);

    free(currentPath);
    return result;
}

void printResult(int** result, int resultSize, int* colSizes) {
    printf("[");
    for (int i = 0; i < resultSize; i++) {
        printf("[");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < colSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < resultSize - 1) printf(",");
    }
    printf("]\n");
}

// --- Helper: recursively free the tree nodes ---
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root); // Free the node itself
}

// --- Helper: standardized cleanup for the complex result ---
void freeResult(int** result, int resultSize, int* colSizes) {
    for (int i = 0; i < resultSize; i++) {
        free(result[i]); // Free each individual path array
    }
    free(result);        // Free the array of pointers
    free(colSizes);      // Free the column sizes array
}

int main() {
    // --- Test Case 1 ---
    printf("Test Case 1 (Standard): ");
    struct TreeNode* root1 = newNode(5);
    // ... [Building Tree 1] ...
    root1->left = newNode(4);
    root1->right = newNode(8);
    root1->left->left = newNode(11);
    root1->left->left->left = newNode(7);
    root1->left->left->right = newNode(2);
    root1->right->left = newNode(13);
    root1->right->right = newNode(4);
    root1->right->right->left = newNode(5);
    root1->right->right->right = newNode(1);

    int returnSize1;
    int* returnColSizes1;
    int** result1 = pathSum(root1, 22, &returnSize1, &returnColSizes1);
    printResult(result1, returnSize1, returnColSizes1);

    // CLEANUP 1: Results AND Tree
    freeResult(result1, returnSize1, returnColSizes1);
    freeTree(root1); // <--- Fix: Free the tree nodes

    // --- Test Case 2 ---
    printf("Test Case 2 (Negatives): ");
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(-2);
    root2->left->left = newNode(3);
    root2->left->right = newNode(2);

    int returnSize2;
    int* returnColSizes2;
    int** result2 = pathSum(root2, 1, &returnSize2, &returnColSizes2);
    printResult(result2, returnSize2, returnColSizes2);

    // CLEANUP 2: Free result2 (which was missing) AND root2
    freeResult(result2, returnSize2, returnColSizes2);
    freeTree(root2);

    // --- Test Case 3 ---
    printf("Test Case 3 (Empty): ");
    int returnSize3;
    int* returnColSizes3;
    int** result3 = pathSum(NULL, 0, &returnSize3, &returnColSizes3);
    printResult(result3, returnSize3, returnColSizes3);

    // CLEANUP 3: Even empty results need freeing!
    // pathSum still malloc'd the 'result' and 'colSizes' arrays.
    freeResult(result3, returnSize3, returnColSizes3);
    
    return 0;
}
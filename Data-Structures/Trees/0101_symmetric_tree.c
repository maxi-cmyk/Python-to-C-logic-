// Practice for: 0101_symmetric_tree.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_mirrored(struct TreeNode *n1, struct TreeNode *n2){
    //cannot do n1->val == NULL, seg fault
    //we are checking the address (NULL is a pointer state, not an int)

    if (n1 == NULL && n2 == NULL){
        return true;
    }

    if (n1 == NULL || n2 == NULL){
        return false;
    }

    return (n1->val == n2->val) && is_mirrored(n1->left, n2->right) && is_mirrored(n1->right, n2->left);
}

bool isSymmetric(struct TreeNode *root){
    if (root == NULL){
        return true;
    }
    
    return is_mirrored(root->left, root->right);
}


// Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    printf("--- Test Case 1: Symmetric Tree [1,2,2,3,4,4,3] ---\n");
    //      1
    //    /   \
    //   2     2
    //  / \   / \
    // 3   4 4   3
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);

    if (isSymmetric(root1)) printf("✅ Passed (Result: True)\n");
    else printf("❌ Failed (Result: False)\n");

    printf("\n--- Test Case 2: Asymmetric Tree [1,2,2,null,3,null,3] ---\n");
    //      1
    //    /   \
    //   2     2
    //    \     \
    //     3     3  (Both on the right side -> NOT mirrored)
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);

    if (!isSymmetric(root2)) printf("✅ Passed (Result: False)\n");
    else printf("❌ Failed (Result: True)\n");

    return 0;
}


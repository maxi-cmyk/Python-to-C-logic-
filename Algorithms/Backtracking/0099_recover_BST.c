// Practice for: 0099_recover_BST.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val; 
    struct TreeNode* left; 
    struct TreeNode* right;
}; 

//need double pointer, pointer to a treeNode
void inorder(struct TreeNode* node, struct TreeNode** first, struct TreeNode** second, struct TreeNode** prev){
    if (node == NULL){
        return;
    }
    //use normal pointer to traverse 
    inorder(node->left, first, second, prev);
    //condition: prev val is bigger than the next (there are either 1 or 2 instants)
    if ((*prev) != NULL && (*prev)->val > node-> val){

        //first instance
        if((*first) == NULL){
            *first = *prev; 
            *second = node;
        } else {

            //second instance
            *second = node;
        }
    }
    *prev = node; 
    inorder(node->right, first, second, prev);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode* first = NULL; 
    struct TreeNode* second = NULL; 
    struct TreeNode* prev = NULL;

    //swap vals here
    if (first != NULL && second != NULL){
        int temp = first->val; 
        first->val = second->val;
        second->val = temp;
    }
}
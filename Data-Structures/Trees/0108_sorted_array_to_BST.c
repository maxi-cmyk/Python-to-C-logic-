// Practice for: 0108_sorted_array_to_BST.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *convert(int*nums, int left, int right){
    if (left > right){
        return NULL;
    }

    int mid = left + (right - left) / 2;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = convert(nums, left, mid -1);
    node->right = convert(nums, mid + 1, right);

    return node;
}

struct TreeNode *sortedArrayToBST(int* nums, int numsSize){
    return convert(nums, 0, numsSize - 1);

}

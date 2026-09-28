// Practice for: 0496_next_greater_I.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    // initialise array 
    int nextGreater[10001];
    // set all values to -1
    memset(nextGreater, -1, sizeof(nextGreater));

    // maximum stack size is nums2 
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1; 

    for (int i = 0; i < nums2Size; i++){
        int curr = nums2[i];
        // check if curr > top stack 
        // use while loop if multiple elements
        while (top >= 0 && curr > stack[top]){
            // pop smaller element
            int smaller = stack[top--];
            // map smaller element to greater element
            nextGreater[smaller] = curr;
        }
        // push greatest element to very top
        stack[++top] = curr;
    }
    free(stack); 

    int* res = (int*)malloc(nums1Size * sizeof(int)); 
    // have to return array ame length as nums1
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++){
        // check matching mapping
        res[i] = nextGreater[nums1[i]];
    }
    return res;
}
// Practice for: 0260_single_number_III.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize){
    //use XOR 
    unsigned int xor = 0;
    for (int i = 0; i < numsSize; i++){
        xor ^= nums[i];
    }
    unsigned int diff_bit = xor & -(unsigned int)xor;
    //partition 
    int a = 0;
    int b = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] & diff_bit){
            a^= nums[i];
        } else {
            b ^= nums[i];
        }
    }
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = a;
    result[1] = b;

    *returnSize = 2;
    return result;
}

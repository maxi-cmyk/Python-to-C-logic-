// Practice for: 0217_contains_dupe.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);  // avoids overflow
}

bool containsDuplicate (int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp_int);

    for (int i = 1; i < numsSize; i++){
        if (nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}



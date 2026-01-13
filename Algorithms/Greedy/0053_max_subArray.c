// Practice for: 0053_max_subArray.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

int maxSubArray (int *nums, int numsSize){
    int max_sum = nums[0];
    int curr_sum = 0;

    for (int i = 0; i < numsSize; i++){
        curr_sum += nums[i];
        if (curr_sum > max_sum){
            max_sum = curr_sum;
        }
        if (curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_sum;
}

int main() {
    int test1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    printf("Test 1 Max Subarray Sum: %d\n", maxSubArray(test1, size1)); // Expected: 6

    int test2[] = {-5, -1, -3};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    printf("Test 2 (All Negative): %d\n", maxSubArray(test2, size2));   // Expected: -1

    return 0;
}



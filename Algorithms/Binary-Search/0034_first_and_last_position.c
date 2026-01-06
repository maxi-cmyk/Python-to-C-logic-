// Practice for: 0034_first_and_last_position.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearch(int *nums, int numsSize, int target, bool search_left){
    int left = 0;
    int right = numsSize - 1;
    int idx = -1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            idx = mid;
            if (search_left){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] >target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return idx;
}

int* searchRange(int *nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* res = (int*) malloc(2 *sizeof(int));
    res[0] = binarySearch(nums, numsSize, target, true); //search left
    res[1] = binarySearch(nums, numsSize, target, false); //search right 

     return res;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = 6;
    int target = 8;
    int returnSize; // This will be filled by the function

    // 1. Call the function
    int* result = searchRange(nums, numsSize, target, &returnSize);

    // 2. Print results
    printf("Target %d found at range: [%d, %d]\n", target, result[0], result[1]);

    // 3. IMPORTANT: Free the memory allocated inside searchRange
    free(result);

    // Test Case 2: Not Found
    target = 6;
    result = searchRange(nums, numsSize, target, &returnSize);
    printf("Target %d found at range: [%d, %d]\n", target, result[0], result[1]);
    free(result);

    return 0;
}
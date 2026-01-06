// Practice for: 0033_search_rotated_array.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int search(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
         //left side is sorted 
        } else if (nums[mid] >= nums[left]) {
            if (nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        //right side is sorted
        }else {
            if (nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

void run_test(int* nums, int numsSize, int target, int expected) {
    int result = search(nums, numsSize, target);
    if (result == expected) {
        printf("✅ PASS: Target %d found at index %d\n", target, result);
    } else {
        printf("❌ FAIL: Target %d expected %d, but got %d\n", target, expected, result);
    }
}

int main() {
    // Test 1: Standard rotation
    int case1[] = {4, 5, 6, 7, 0, 1, 2};
    run_test(case1, 7, 0, 4);

    // Test 2: Standard rotation, searching left side
    run_test(case1, 7, 5, 1);

    // Test 3: Not found
    run_test(case1, 7, 3, -1);

    // Test 4: Small rotation
    int case4[] = {3, 1};
    run_test(case4, 2, 1, 1);

    // Test 5: Single element
    int case5[] = {1};
    run_test(case5, 1, 0, -1);

    return 0;
}
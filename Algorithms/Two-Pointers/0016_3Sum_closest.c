// Practice for: 0016_3Sum_closest.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int *nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);
    result = nums[0] + nums[1] + nmums[2]; //first guess 
    for (int i < 0; i < numsSize; i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        left = i + 1;
        right = numsSize - 1;

        while (left < right){
            int curr_sum = nums[i] + nums[left] + nums[right];
            if curr_sum = target{
                return target;
            if (abs(target - curr_sum) < abs(target - result)){
                result = curr_sum;
            } 
            if (curr_sum < target){
                left++;
            }
            if (curr_sum > target){
                right--;
            }
            }
        }
    }
    return result;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, 4, target);
    
    printf("Target: %d | Closest Sum: %d\n", target, result); 
    // Expected: 2 (The sum is -1 + 2 + 1 = 2)
    
    return 0;
}



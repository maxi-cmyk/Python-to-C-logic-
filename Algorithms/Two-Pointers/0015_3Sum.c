// Practice for: 0015_3Sum.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
//i + j + k = 0
int** threeSum(int *nums, int numsSize, int *returnSize, int **returnColoumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare); //built in function to sort array, just specify what we are sorting in helper fn
    int cap = 16;
    int **res = (int**) malloc(sizeof(int*) * cap); //pointer of arrays
    *returnSize = 0; //initialise zero first 

    for (int i = 0; i < numsSize - 2; i++){
        if (i > 0 && nums[i] == nums[i-1]){ //skip dupes
            continue;
        } 
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right){
            int total = nums[i] + nums[left] + nums[right];

            if (total < 0){
                left++; 
            } else if (total > 0){
                right--;
            } else {
                if (*returnSize == cap){ //check capacity
                    cap *= 2;
                    res = realloc(res,cap *sizeof(int*));
                } 
                res[*returnSize] = malloc(3*sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnSize)++;

                left++;
                right--;

                while (left < right && nums[left] == nums[left-1]){
                    left++;
                }
                while (left < right && nums[right] == nums[right+1]){
                    right--;
                }
            }
        }
    }
    *returnColoumnSizes = (int*)malloc((*returnSize * sizeof(int)));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColoumnSizes)[i] = 3;
    }
    return res;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int* returnColumnSizes;
    
    int** result = threeSum(nums, 6, &returnSize, &returnColumnSizes);
    
    printf("Found %d triplets:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]); // Clean up inner arrays
    }
    free(result); // Clean up outer array
    free(returnColumnSizes); // Clean up column sizes
    
    return 0;
}
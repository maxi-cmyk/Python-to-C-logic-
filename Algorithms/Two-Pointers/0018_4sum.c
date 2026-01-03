// Practice for: 0018_4sum.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
/*
 * 4SUM SUMMARY: THE NESTED MATRIX
 * -------------------------------
 * Logic: 2 Fixed Loops (i, j) + 2 Converging Pointers (left, right).
 * Complexity: O(n^3)
 * * C-RECORDS (The "Metadata"):
 * 1. res: The actual 2D Matrix (Array of pointers to arrays).
 * 2. returnSize: The 'Height' of the matrix (number of rows/quadruplets).
 * 3. returnColumnSizes: The 'Width Map' (An array where each index stores '4').
 * * OVERFLOW PROTECTION:
 * use (long) casting for 'sum' because 4 large 'int' values can exceed 
 * the 2,147,483,647 limit of a 32-bit signed integer.
 */

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes){
    //returnsize refers to how many quads did i find (how many rows)
    //returnColoumnSize refers to how long each row is (4), use int ** as a ptr to array
    *returnSize = 0;
    if(numsSize < 4){
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 16;
    int **res = (int**)malloc(sizeof(int*) * capacity);

    for (int i = 0; i < numsSize - 3; i++){
        if (i > 0 && nums[i] == nums[i-1]){ //skip dupes
            continue;
        }
        if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){ //if is more, skip entirely (already sorted!)
            break;
        }
        if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] < target){ //if is less, move fwd
            continue; 
        }
        for (int j = i + 1; j < numsSize - 2; j++){
            if (j > i + 1 && nums[j] == nums[j-1]){ //skip dupes
            continue;
            }
            int left = j + 1; //similar to 3sum
            int right = numsSize - 1;

            while (left < right){
                long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target){
                    if (capacity == *returnSize){
                        capacity *= 2;
                        res = realloc(res, capacity *sizeof(int*));

                    }
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];

                    (*returnSize)++;
                    left++;
                    right--;

                    //settle left and right dupes 
                    while (left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while (left < right & nums[right] == nums[right + 1]){
                        right--;
                    }
                } else if (sum > target){
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    *returnColumnSizes = (int*)malloc((*returnSize) *sizeof(int));
    for (int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = 4; //filling each row with 4
    }
    return res;
}

int main() {
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int size1 = 6;
    int target1 = 0;
    int returnSize;
    int* returnColumnSizes;

    int** res = fourSum(nums1, size1, target1, &returnSize, &returnColumnSizes);

    printf("Test 1: Standard Array\nFound %d quadruplets:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        // We use returnColumnSizes[i] to know how many elements to print
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d%s", res[i][j], j == 3 ? "" : ", ");
        }
        printf("]\n");
        free(res[i]); // Free individual row
    }
    
    free(res);               // Free array of pointers
    free(returnColumnSizes); // Free the 'Map'

    // Test 2: Huge Numbers (Testing Long Overflow)
    int nums2[] = {1000000000, 1000000000, 1000000000, 1000000000};
    // Note: This would fail if your sum wasn't (long)
    int** res2 = fourSum(nums2, 4, 0, &returnSize, &returnColumnSizes);
    printf("\nTest 2 (Huge Sum): Found %d results (Expected 0).\n", returnSize);

    return 0;
}
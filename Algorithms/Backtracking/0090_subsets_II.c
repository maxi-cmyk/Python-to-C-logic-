// Practice for: 0090_subsets_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <qsort.h>

int compare(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returncolumnSizes){
    qsort(nums. numsSize, sizeof(int), compare);

    int total = 1 << numsSize;
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    int count = 0;

    for (int i = 0; i < total; i++){
        int subset[numsSize];
        int size = 0;
        bool exclude = false;

        for (int j = 0; j < numsSize; j++){
            if ((i >> j) & 1){
                if (j > 0 && nums[j] == nums[j-1] && !((i >> (j-1)) & 1)){
                    exclude = true;
                    break;
                }
                subset[size++] = nums[j];
            }
        }
    }

    if(!exclude){
        result[count] = (int*)malloc(size * sizeof(int));
        for (int k = 0; k < size; k++){
            result[count][k] = subset[k];
            (*returnColumnSizes)[count] = size;
        }
    }
    *returnSize = count;
    return result; 
}
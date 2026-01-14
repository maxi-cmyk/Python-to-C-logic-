// Practice for: 0046_permutations.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//permutations are unique, so no repeats!

void dfs(int *nums, int numsSize, int **res, int *columnSizes, int *returnSize, int* path, int pathSize, int* used){
    if (pathSize == numsSize){
        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize], path, numsSize * sizeof(int)); //(dest, source, memory)
        columnSizes[*returnSize] =  numSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++){
        if (used[i]) {
            continue;
        }
        used[i] = 1;
        path[pathSize] = nums[i];
        dfs(nums, numsSize, res, columnSizes, returnSize, path, pathSize + 1, used);
        used[i] = 0;
    }
}

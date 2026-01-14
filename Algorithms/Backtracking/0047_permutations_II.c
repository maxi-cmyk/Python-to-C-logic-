// Practice for: 0047_permutations_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sort array first 
//implement skip logic 

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int *nums, int numsSize, int **res, int *columnSizes, int *returnSize, int* path, int pathSize, int* used){
    if (pathSize == numsSize){
        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize], path, numsSize * sizeof(int)); //(dest, source, memory)
        columnSizes[*returnSize] =  numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++){
        if(used[i]) {
            continue;
        }
        //skip dupes, skip previously used
        if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
            continue;
        } 
        
        used[i] = 1; //set used to true
        path[pathSize] = nums[i];
        dfs(nums, numsSize, res, columnSizes, returnSize, path, pathSize + 1, used);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int maxPerm = 50000;
    int **res = (int**)malloc(sizeof(int*) * maxPerm);
    *returnColumnSizes = (int*)malloc(maxPerm * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * numsSize);
    int* used = calloc(sizeof(int), numsSize); //set all to zero
    dfs(nums, numsSize, res, *returnColumnSizes, returnSize, path, 0, used);
    free(path);
    free(used);
    return res;
}

void run_test(int* nums, int size) {
    int returnSize;
    int* columnSizes;
    
    printf("Input: ");
    for(int i=0; i<size; i++) printf("%d ", nums[i]);
    printf("\n");

    int** results = permuteUnique(nums, size, &returnSize, &columnSizes);
    
    printf("Found %d permutations:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", results[i][j]);
        }
        printf("]\n");
        free(results[i]); // Free individual permutations
    }
    
    free(results);      // Free result pointer array
    free(columnSizes);  // Free sizes array
    printf("---------------------------\n");
}

int main() {
    int test1[] = {1, 1, 2};
    run_test(test1, 3);

    int test2[] = {2, 2, 1, 1};
    run_test(test2, 4);

    return 0;
}

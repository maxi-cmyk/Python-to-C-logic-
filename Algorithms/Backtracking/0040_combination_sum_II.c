// Practice for: 0040_combination_sum_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void dfs(int *candidates, int candidatesSize, int target, int **res, int *columnSize, int *returnSize, int* path, int pathSize, int start){
    // columnSize is length of indiv combination
    //returnSize is num of combinations
    
    if (target == 0){
        res[*returnSize] = (int*)malloc(pathSize * sizeof(int));
        memcpy(res[*returnSize], path, pathSize * sizeof(int));
        columnSize[*returnSize] = pathSize; 
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++){
        if(i > start && candidates[i] == candidates[i-1]){
            continue;
        } 
        if(candidates[i] > target){
            break;
        }
        if (candidates[i] <= target){
            path[pathSize] = candidates[i];
            //move i by 1 to avoid dupes
           dfs(candidates, candidatesSize, target - candidates[i], res, columnSize, returnSize, path, pathSize + 1, i + 1);
        }
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes){
    //sort array 
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int **res = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(500 * sizeof(int));
    *returnSize = 0;

    int *path = (int*)malloc(500 * sizeof(int));
    dfs(candidates, candidatesSize, target, res, *returnColumnSizes, returnSize, path, 0, 0);
    free(path);
    return res;
}

void print_and_free(char* label, int** res, int returnSize, int* colSizes) {
    printf("--- %s ---\n", label);
    printf("Total Combinations: %d\n", returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("]\n");
        // Free the individual combination array
        free(res[i]);
    }
    
    // Free the containers
    free(res);
    free(colSizes);
    printf("---------------------------\n\n");
}

int main() {
    int rSize;
    int* colSizes;

    // Test Case 1: Standard with Duplicates
    int test1[] = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    int** res1 = combinationSum2(test1, 7, target1, &rSize, &colSizes);
    print_and_free("Test Case 1: [10,1,2,7,6,1,5], Target: 8", res1, rSize, colSizes);

    // Test Case 2: Small overlapping numbers
    int test2[] = {2, 5, 2, 1, 2};
    int target2 = 5;
    int** res2 = combinationSum2(test2, 5, target2, &rSize, &colSizes);
    print_and_free("Test Case 2: [2,5,2,1,2], Target: 5", res2, rSize, colSizes);

    // Test Case 3: No valid combinations
    int test3[] = {2};
    int target3 = 1;
    int** res3 = combinationSum2(test3, 1, target3, &rSize, &colSizes);
    print_and_free("Test Case 3: [2], Target: 1 (Expect Empty)", res3, rSize, colSizes);

    return 0;
}
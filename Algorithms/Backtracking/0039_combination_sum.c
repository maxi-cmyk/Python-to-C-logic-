// Practice for: 0039_combination_sum.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs (int *candidates, int candidatesSize, int target, int **res, int *columnSize, int *returnSize, int* path, int pathSize, int start){
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
        if (candidates[i] <= target){
            path[pathSize] = candidates[i];
           dfs(candidates, candidatesSize, target - candidates[i], res, columnSize, returnSize, path, pathSize + 1, i);
        }
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes){
    int **res = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(500 * sizeof(int));
    *returnSize = 0;

    int *path = (int*)malloc(500 * sizeof(int));
    dfs(candidates, candidatesSize, target, res, *returnColumnSizes, returnSize, path, 0, 0);
    free(path);
    return res;
}

void print_and_free(int** results, int returnSize, int* columnSizes) {
    printf("Result Size: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", results[i][j]);
        }
        printf("]\n");
        free(results[i]); // Free each individual combination
    }
    free(results);      // Free the array of pointers
    free(columnSizes);  // Free the array of sizes
    printf("---------------------------\n");
}

int main() {
    printf("--- Testing Combination Sum I ---\n");
    int c1[] = {2, 3, 6, 7};
    int rSize1;
    int* colSizes1;
    // Calling your function (Assuming it matches the signature)
    int** res1 = combinationSum(c1, 4, 7, &rSize1, &colSizes1);
    print_and_free(res1, rSize1, colSizes1);
}
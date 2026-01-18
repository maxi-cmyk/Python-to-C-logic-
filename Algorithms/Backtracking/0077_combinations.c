// Practice for: 0077_combinations.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void dfs(int n, int k, int start, int *path, int pathSize, int **res, int* returnSize, int** returnColumnSizes){
    if(pathSize == k){
        res[*returnSize] = (int*)malloc(k * sizeof(int));
        memcpy(res[*returnSize], path, k * sizeof(int));
        (*returnColumnSizes)[*returnSize] = k; //every row has the same size k 
        (*returnSize)++;
        return;
    }
    for(int i = start; i <= n -(k - pathSize) + 1; i++){
        path[pathSize] = i;
        dfs(n, k, i + 1, path, pathSize + 1, res, returnSize, returnColumnSizes);
    }
}

int **combine(int n, int k, int *returnSize, int ** returnColumnSizes){
    int max_combi = 200000;
    int** res = (int**)malloc(max_combi * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_combi * sizeof(int));
    *returnSize = 0;

    int *path = (int*)malloc(k * sizeof(int));
    dfs(n, k, 1, path, 0, res, returnSize, returnColumnSizes);
    return res;
}

void test_combine(int n, int k) {
    int returnSize;
    int* returnColumnSizes;
    
    printf("Testing n=%d, k=%d:\n", n, k);
    
    // 1. Call your function
    int** result = combine(n, k, &returnSize, &returnColumnSizes);
    
    // 2. Print the results
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("]\n");
    }
    
    // 3. THE CLEANUP (Crucial Step)
    // First: Free each individual combination (the "rows")
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    // Second: Free the array of pointers (the "table")
    free(result);
    // Third: Free the column sizes array
    free(returnColumnSizes);
    
    printf("Memory freed successfully.\n\n");
}

int main() {
    // Case 1: Standard small set
    test_combine(4, 2); 
    // Expected: [1,2], [1,3], [1,4], [2,3], [2,4], [3,4]

    // Case 2: Minimal set
    test_combine(1, 1);
    // Expected: [1]

    // Case 3: N equals K (Only one combination)
    test_combine(5, 5);
    // Expected: [1,2,3,4,5]

    return 0;
}

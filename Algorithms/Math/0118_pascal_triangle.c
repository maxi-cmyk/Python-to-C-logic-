// Practice for: 0118_pascal_triangle.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++){
        int rowSize = i + 1;
        (*returnColumnSizes)[i] = rowSize;
        triangle[i] = (int*)malloc(rowSize * sizeof(int));
        triangle[i][0] = 1;
        triangle[i][rowSize - 1] = 1;

        //fill gaps 
        for (int j = 1; j < i; j++){
            //add from rows above 
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    return triangle;
}

int main() {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    
    // 1. Generate the triangle
    int** result = generate(numRows, &returnSize, &returnColumnSizes);
    
    // 2. Print the triangle
    printf("Pascal's Triangle (%d rows):\n", numRows);
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]\n");
    }
    printf("]\n");

    // 3. Cleanup: Free the memory (Caller's Responsibility!)
    for (int i = 0; i < returnSize; i++) {
        free(result[i]); // Free each row
    }
    free(result);             // Free the spine
    free(returnColumnSizes);  // Free the sizes array
    
    return 0;
}

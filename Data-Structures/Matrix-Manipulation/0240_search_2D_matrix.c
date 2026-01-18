// Practice for: 0240_search_2D_matrix.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int ** matrix, int matrixSize, int *matrixColSize, int target){
    if(matrixSize == 0 || matrixColSize[0] == 0){
        return false;
    }
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int r = 0;
    int c = cols - 1;

    //start from top right 
    
    while (r < rows && c >= 0){
        if(matrix[r][c] == target){
            return true;
        } else if (matrix[r][c] > target){ //move left, too big 
            c--;
        } else { //move down, too small 
            r++;
        }
    }
    return false; 
}

void test_240(int r, int c, int data[r][c], int target) {
    // 1. Setup int**
    int** matrix = (int**)malloc(r * sizeof(int*));
    int* colSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
        colSizes[i] = c;
        for (int j = 0; j < c; j++) matrix[i][j] = data[i][j];
    }

    // 2. Execute
    bool found = searchMatrix(matrix, r, colSizes, target);
    printf("Target %d Found: %s\n", target, found ? "TRUE" : "FALSE");

    // 3. Cleanup
    for (int i = 0; i < r; i++) free(matrix[i]);
    free(matrix);
    free(colSizes);
}

int main() {
    int mat[5][5] = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    printf("Test 1 (Target 5): ");
    test_240(5, 5, mat, 5);  // Expected: TRUE

    printf("Test 2 (Target 20): ");
    test_240(5, 5, mat, 20); // Expected: FALSE

    return 0;
}

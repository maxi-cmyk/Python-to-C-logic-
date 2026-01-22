// Practice for: 0054_spiral_matrix.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize = 0){
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;
    int* result = (int*)malloc(total * sizeof(int));

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while(*returnSize < total){
        //traverse right
        for( int i = left; i <= right && *returnSize < total; i++){
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        //traverse down
        for (int i = top; i <= bottom && *returnSize < total; i++){
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        //traverse left
        for (int i = right; i >= left && *returnSize < total; i++){
            result[(*returnSize)++] = matrix[bottom][i];
        }
        bottom--;

        //traverse up
        for (int i = bottom; i >= top && *returnSize < total; i++){
            result[(*returnSize)++] = matrix[i][left];
        }
        left++;
    }
    return result;
}

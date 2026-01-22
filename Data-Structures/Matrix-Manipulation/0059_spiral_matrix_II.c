// Practice for: 0059_spiral_matrix_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int** generateMatrix( int n. int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    int** matrix = (int**)malloc(n  * sizeof(int));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    //amke matrix
    for (int i = 0; i < n; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int total = n * n;
    int num = 1;

    while (n <= total){
        //move right
        for (int i = left; i <= right; i++){
            matrix[top][i] = num++;
        }
        top++;

        //move down
        for (int i = top; i <= bottom; i++){
            matrix[i][right] = num++;
        }
        right--;

        //move left
        for (int i = right; i >= left; i--){
            matrix[bottom][i] = num++;
        }
        bottom--;

        //move up
        for (int i = bottom; i >= top; i--){
            matrix[i][left] = num++;
        }
        left++:
    }
    return matrix;
}

// Practice for: 0048_rotate_image.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int len = matrixSize;
    int top = 0;
    int bottom = len - 1;

    while (top < bottom){
        for(int c = 0; c < len; c++){ //reverse 
            swap(&matrix[top][c], &matrix[bottom][c]);
        }
        top++;
        bottom--;
    }

    for (int r = 0; r < len; r++){ //transpose
        for(int c = r + 1; c < len; c++){
            swap(&matrix[r][c], &matrix[c][r]);
        }
    }
}

int main() {
    int n = 3;
    // 1. Allocate memory for rows (array of pointers)
    int** matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        // 2. Allocate memory for each column
        matrix[i] = malloc(n * sizeof(int));
    }

    // 3. Fill the matrix with 1-9
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = val++;
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Call your function
    rotate(matrix, n, &n);

    printf("\nRotated Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // 4. Clean up 
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}

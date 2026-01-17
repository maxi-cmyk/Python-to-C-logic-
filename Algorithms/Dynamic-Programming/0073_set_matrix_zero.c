// Practice for: 0073_set_matrix_zero.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void setZeroes(int **matrix, int matrixSize, int *matrixColSize){
    if (matrixSize == 0 || matrix == NULL){
        return;
    }
    int rows = matrixSize;
    int cols = matrixColSize[0];

    bool firstRowZero = false;
    bool firstColZero = false;

    for(int j = 0; j < cols; j++){
        if (matrix[0][j] == 0){
            firstRowZero = true;
            break;
        }
    }

    for(int i = 0; i < rows; i++){
        if(matrix[i][0] == 0){
            firstColZero = true;
            break;
        }
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero) {
        for(int j = 0; j < cols; j++){
            matrix[0][j] = 0;
        }
    }
    if(firstColZero){
        for(int i = 0; i < rows; i++){
            matrix[i][0] = 0;
        }
    }
}
void print_matrix(int** matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void test_73(int r, int c, int data[r][c]) {
    // Allocation
    int** matrix = (int**)malloc(r * sizeof(int*));
    int* colSize = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
        colSize[i] = c;
        for (int j = 0; j < c; j++) matrix[i][j] = data[i][j];
    }

    setZeroes(matrix, r, colSize);

    print_matrix(matrix, r, c);
    printf("-----------\n");

    // Cleanup
    for (int i = 0; i < r; i++) free(matrix[i]);
    free(matrix);
    free(colSize);
}

int main() {
    printf("Test 1 (Boundary Zeros):\n");
    int t1[3][4] = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    test_73(3, 4, t1);

    printf("Test 2 (Single Center Zero):\n");
    int t2[3][3] = {{1,1,1}, {1,0,1}, {1,1,1}};
    test_73(3, 3, t2);

    return 0;
}
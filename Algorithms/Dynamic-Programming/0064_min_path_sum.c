// Practice for: 0064_min_path_sum.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int minPathSum(int **grid, int gridSize, int *gridColSize){
    int m = gridSize;
    int n = gridColSize[0];

    //fill first row 
    for(int i = 1; i < n; i++){
        grid[0][i] += grid[0][i-1];
    }
    //fill first col
    for(int j = 1; j < m; j++){
        grid[j][0] += grid[j-1][0];
    }

    //fill rest 
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            grid[i][j] += MIN(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}

void test_64(int rows, int cols, int data[rows][cols]) {
    // 1. Allocate int** grid
    int** grid = (int**)malloc(rows * sizeof(int*));
    int* colSize = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        colSize[i] = cols;
        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
    }

    // 2. Run your function
    int result = minPathSum(grid, rows, colSize);
    printf("Result: %d\n", result);

    // 3. Clean up
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);
    free(colSize);
}

int main() {
    printf("Test 1 (Standard 3x3): ");
    int t1[3][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
    test_64(3, 3, t1); // Expected: 7 (1->3->1->1->1)

    printf("Test 2 (Greedy Trap): ");
    int t2[2][3] = {{1, 10, 1}, {1, 1, 1}};
    test_64(2, 3, t2); // Expected: 4

    printf("Test 3 (Single Row): ");
    int t3[1][3] = {{1, 2, 5}};
    test_64(1, 3, t3); // Expected: 8

    return 0;
}
// Practice for: 0063_unique_paths_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int ** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    //check if any obstacle at start and end 
    if(obstacleGrid[0][0]== 1 || obstacleGrid[m-1][n-1] == 1){
        return 0;
    }
    obstacleGrid[0][0] = 1;

    //check first row
    for(int i = 1; i < n; i++){
        obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1) ? 1 : 0;
    }

    //check first col
    for(int j = 1; j < m; j++){
        obstacleGrid[j][0] = (obstacleGrid[j][0] == 0 && obstacleGrid[j-1][0] == 1) ? 1 : 0;
    }

    //fill rest 
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){ //obstacle 
                obstacleGrid[i][j] = 0;
            } else {
                obstacleGrid[i][j] += (unsigned int)(long)obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[m-1][n-1];
}

void run_test(int rows, int cols, int data[rows][cols]) {
    // 1. Setup the int** grid for LeetCode format
    int** grid = (int**)malloc(rows * sizeof(int*));
    int* colSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        colSizes[i] = cols;
        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
    }

    // 2. Execute
    int result = uniquePathsWithObstacles(grid, rows, colSizes);
    printf("Result: %d\n", result);

    // 3. Cleanup
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);
    free(colSizes);
}

int main() {
    printf("Test 1 (Dead on Arrival): ");
    int t1[1][2] = {{1, 0}};
    run_test(1, 2, t1); // Expected: 0

    printf("Test 2 (Corner Trap): ");
    int t2[3][3] = {{0,0,0}, {0,1,1}, {0,1,0}};
    run_test(3, 3, t2); // Expected: 1

    printf("Test 3 (Large Empty 3x3): ");
    int t3[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    run_test(3, 3, t3); // Expected: 6

    return 0;
}

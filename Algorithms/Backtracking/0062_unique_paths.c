// Practice for: 0062_unique_paths.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    long long grid [m][n];
    //initialise first row and first col grid to 1
    for(int i = 0; i < m; i++){
        grid[i][0] = 1;
    }
    for(int j = 0; j < n; j++){
        grid[0][j] = 1;
    }

    //fill table 
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){ //grid[i][j] is just sum of paths to get there (right + down)
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return (int)grid[m-1][n-1];
}

int main() {
    printf("Paths for 3x7: %d\n", uniquePaths(3, 7)); // Expected: 28
    printf("Paths for 3x2: %d\n", uniquePaths(3, 2)); // Expected: 3
    return 0;
}

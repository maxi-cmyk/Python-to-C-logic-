// Practice for: 0120_triangle.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int* dp = (int*)malloc(triangleSize * sizeof(int));

    for (int i = 0; i < triangleSize; i++){
        dp[i] = triangle[triangleSize - 1][i];
    }

    //bottom up
    for (int row = triangleSize - 2; row >= 0; row--){
        for (int i = 0; i <= row; i++){
            dp[i] = triangle[row][i] + MIN(dp[i], dp[i+1]);
        }
    }
    int result = dp[0];
    free(dp);
    return result;
}


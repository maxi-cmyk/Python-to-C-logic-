// Practice for: 0096_unique_BST.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
    
//catalan numbers!

int numTrees(int n) {
    // 1. Allocate the DP array (size n + 1 so we can access dp[n])
    int* dp = (int*)calloc(n + 1, sizeof(int));
    
    // 2. Base Cases
    dp[0] = 1;
    dp[1] = 1;
    
    // 3. Fill the DP array from 2 up to n
    for (int nodes = 2; nodes <= n; nodes++) {
        // 4. Try every possible root for the current number of nodes
        for (int root = 1; root <= nodes; root++) {
            dp[nodes] += dp[root-1] * dp[nodes-root];
        }
    }
    int result = dp[n];
    free(dp); 
    return result;
}

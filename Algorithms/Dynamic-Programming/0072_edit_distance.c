// Practice for: 0072_edit_distance.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) MIN(a, MIN(b, c))

int minDistance(char* word1, char *word2){
    int m = strlen(word1);
    int n = strlen(word2);

    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++){
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++){
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            //found match
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } //find min between insert, delete, replace
            else {
                dp[i][j] = 1 + MIN3(dp[i][j-1], dp[i-1][j],dp[i-1][j-1]);
            }
        }

    }
    return dp[m][n];
}

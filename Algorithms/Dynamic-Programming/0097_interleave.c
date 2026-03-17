// Practice for: 0097_interleave.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

bool isInterleaving (char* s1, char* s2, char* s3){
    int n = strlen(s1);
    int m = strlen(s2);
    int l = strlen(s3);

    if (l != n + m){
        return false;
    }

    //swap s1 and s2 if s2 is longer than s1 
    //need to swap the lengths as well!
    if (n < m){
        char* temp = s1;
        s1 = s2; 
        s2 = temp;
        int temp1 = n;
        n = m;
        m = temp1;

    }
    //shorter length is m
    int* dp = (int*)calloc((m + 1), sizeof(int));
    
    dp[0] = true;

    for (int j = 1; j < n+1; j++){
        // do this so we know which part of s3 starts with which part of s2
        dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
    }

    for (int i = 1; i < n+1; i++){
        //same thing for s1, start from zero here since we re comparing s1
        dp[0] = dp[0] && s1[i-1] == s3[i-1];
        //checking consecutive 
        for (int j = 1; j < n+1; j++){
            dp[j] = (dp[j] && (s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]));
        }
    }
    bool result = dp[m];
    free(dp);
    return result;
}


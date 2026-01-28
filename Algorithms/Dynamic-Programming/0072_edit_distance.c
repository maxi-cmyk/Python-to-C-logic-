// Practice for: 0072_edit_distance.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } //find min between insert, delete, replace
            else {
                dp[i][j] = 1 + MIN3(dp[i][j-1], dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

void run_test(char* w1, char* w2, int expected) {
    int result = minDistance(w1, w2);
    printf("Word1: \"%s\" | Word2: \"%s\"\n", w1, w2);
    printf("Result: %d | Expected: %d | %s\n", 
           result, expected, (result == expected ? "PASS" : "FAIL"));
    printf("--------------------------------------------------\n");
}

int main() {
    printf("--- Edit Distance (#72) Test Suite ---\n\n");

    // Case 1: Standard example
    run_test("horse", "ros", 3);

    // Case 2: Complex example
    run_test("intention", "execution", 5);

    // Case 3: Empty string (Base Case)
    run_test("sea", "", 3);

    // Case 4: No change
    run_test("coffee", "coffee", 0);

    // Case 5: Single character change
    run_test("a", "b", 1);

    // Case 6: Completely different
    run_test("abc", "def", 3);

    return 0;
}

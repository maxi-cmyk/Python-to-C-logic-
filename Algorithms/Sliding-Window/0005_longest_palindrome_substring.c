// Practice for: 0005_longest_palindrome_substring.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expand (char *s, int left, int right, int n){
    while (left >= 0 && right < n && s[left] == s[right]){
        left--;
        right++;       
    }
    return right - left - 1;
}

char* longestPalindrome(char* s){
    int n = strlen(s);
    if (n == 0){
        return s;
    }
    int start = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++){
        int odd_length = expand(s,i,i,n);
        int even_length = expand(s,i,i+1,n);
        int curr_len = (odd_length > even_length) ? odd_length : even_length;

        if (curr_len > max_len){
            start = i - (curr_len -1) / 2;
            max_len = curr_len;
        }
    }
    char* result = calloc((max_len +1),sizeof(char));
    for (int i = 0; i < max_len; i++){
        result[i] = s[start + i];

    }
    return result;
}

int main() {
    char* inputs[] = {"babad", "cbbd", "a", "aaaaa", "ac"};
    char* expected[] = {"bab", "bb", "a", "aaaaa", "a"}; // "bab" or "aba" are both fine
    int num_tests = 5;

    printf("--- Testing Longest Palindromic Substring (C) ---\n");

    for (int i = 0; i < num_tests; i++) {
        char* result = longestPalindrome(inputs[i]);
        
        printf("Input: %s | Result: %s ", inputs[i], result);
        
        // Basic check (since babad can be bab or aba, we check length)
        if (strlen(result) >= strlen(expected[i])) {
            printf("✅\n");
        } else {
            printf("❌ (Expected length %lu)\n", strlen(expected[i]));
        }

        // IMPORTANT: Free the memory allocated by malloc/calloc!
        free(result);
    }

    return 0;
}

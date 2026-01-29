// Practice for: 0091_decode_ways.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDecodings(char* s){
    if(s == NULL || s[0] == '0'){
        return 0;
    }

    int n = strlen(s);
    int prev2 = 1;
    int prev1 = 1;

    for(int i = 1; i < n; i++){
        int curr = 0;
        if (s[i] != '0'){
            curr += prev1;
        }
        int twoDigit = (s[i-1] - '0') * 10 + (s[i] - '0');
        if (twoDigit >= 10 && twoDigit <= 26){
            curr += prev2;
        }
        if (curr == 0){
            return 0;
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

void run_test(char* s, int expected) {
    int result = numDecodings(s);
    printf("Input: %-8s | Result: %-2d | Expected: %-2d | %s\n", 
           s, result, expected, (result == expected ? "PASS" : "FAIL"));
}

int main() {
    printf("--- LeetCode #91: Decode Ways - Test Suite ---\n\n");

    run_test("12", 2);      // "AB", "L"
    run_test("226", 3);     // "BBF", "BZ", "VF"
    run_test("06", 0);      // Leading zero is invalid
    run_test("10", 1);      // "J" (10 is valid, but 0 alone is not)
    run_test("2101", 1);    // "BAA" (2, 10, 1)
    run_test("30", 0);      // '30' is too big, '0' cannot stand alone
    run_test("1111", 5);    // (Standard Fibonacci result: 1111, 11 11, 11 1 1, 1 11 1, 1 1 11)
    run_test("27", 1);      // "BG" (27 is too big to be 'Z')

    return 0;
}
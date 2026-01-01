// Practice for: 0008_myAtoi.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi (char *s){
    //if the first instance is a non-digit, return zero
    int i = 0;
    int sign = 1; //default
    long res = 0;

    while (s[i] == ' '){ //traverse whitspaces 
        i++;
    }
    //sign
    if (s[i] == '-'){
        sign = -1;
        i++;
    } else if (s[i] == '+'){
        sign = 1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9'){
        res = res * 10 + (s[i] - '0');
        i++;
    }

    //check bounds
    if (res * sign <= INT_MIN){
        return INT_MIN;
    }
    if (res * sign >= INT_MAX){
        return INT_MAX;
    }

    return res*sign;
}

int main() {
    char* test_strings[] = {
        "42", 
        "   -42", 
        "4193 with words", 
        "words and 987", 
        "91283472332", 
        "-91283472332",
        "+1"
    };

    int expected[] = {
        42, 
        -42, 
        4193, 
        0, 
        INT_MAX, 
        INT_MIN, 
        1
    };

    printf("--- Running myAtoi C Tests ---\n");
    for (int i = 0; i < 7; i++) {
        int result = myAtoi(test_strings[i]);
        if (result == expected[i]) {
            printf("PASS: [%s] -> %d\n", test_strings[i], result);
        } else {
            printf("FAIL: [%s] -> Expected %d, but got %d\n", 
                   test_strings[i], expected[i], result);
        }
    }
    return 0;
}
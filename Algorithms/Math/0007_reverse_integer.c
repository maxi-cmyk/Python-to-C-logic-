// Practice for: 0007_reverse_integer.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <limits.h>

long reverse(int x){ //no need to check for sign in C 
    long res = 0;
    while (x != 0){ // % and / work with negative numbers
        res = res * 10 + (x % 10);
        x /= 10;  
    }
    if (res > INT_MAX || res < INT_MIN){
        return 0;
    }
   return res;
}

int main() {
    int cases[] = {123, -123, 120, 1534236469};
    int expected[] = {321, -321, 21, 0};

    printf("--- Testing Reverse Integer ---\n");
    for (int i = 0; i < 4; i++) {
        int result = reverse(cases[i]);
        if (result == expected[i]) {
            printf("✅ Input: %d | Result: %d\n", cases[i], result);
        } else {
            printf("❌ Input: %d | Expected: %d, Got: %d\n", cases[i], expected[i], result);
        }
    }
    return 0;
}

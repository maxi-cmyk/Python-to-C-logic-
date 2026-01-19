// Practice for: 0009_reverse_integer.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool isPalindrome(int n){
    if(n < 0){
        return false;
    }
    long long rev = 0;
    long long ori = n
    while(n > 0){
        rev = (n % 10) + rev * 10;
        n /= 10;
    }
    return ori == rev; 
}
// Practice for: 0125_valid_palindrome.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s){
    if (strlen(s) == 0){
        return true;
    }
    
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right){
        while (left < right && !isalnum(s[left])){
            left++;
        }
        while (left < right && !isalnum(s[right])){
            right--;
        }
        if (tolower(s[left]) != tolower(s[right])){
           return false;
        }
        left++;
        right--;
    }
    return true;
}

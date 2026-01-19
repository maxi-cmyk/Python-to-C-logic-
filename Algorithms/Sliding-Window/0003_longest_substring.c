// Practice for: 0003_longest_substring.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? a : b);

int lengthOfLongestSubString(char* str){
    int n = strlen(str);
    if(n == 0){
        return 0;
    } 
    //all ascii characters
    int count[128] = {0};
    int left = 0;
    int right = 0;
    int maxLen = 0;

    while(right < n){
        char current = str[right];
        count[current]++;

        while (count[current] > 1){ //dupe
            char leftChar = s[left];
            count[leftChar]--; //subtract dupe
            left++;
        }
        maxLen = MAX(maxLen, right - left + 1);
        right++; //move right 
    }
    return maxLen;
}
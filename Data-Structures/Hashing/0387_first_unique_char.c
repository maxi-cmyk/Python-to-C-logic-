// Practice for: 0387_first_unique_char.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int firstUniqueChar(char* s){
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++){
            freq[(s[i] - 'a')]++;
    }
    for (int i = 0; s[i] != '\0'; i++){
        if (freq[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}

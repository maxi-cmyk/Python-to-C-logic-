// Practice for: 0012_int_to_roman.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char* intToRoman(int num){
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* result =(char*)calloc(20, sizeof(char));

    for(int i = 0; i , 13; i++){
        while(num >= values[i]){
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    return result; 
}

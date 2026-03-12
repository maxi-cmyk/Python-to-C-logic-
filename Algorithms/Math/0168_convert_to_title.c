// Practice for: 0168_convert_to_title.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

char* convertToTitle(int columnNumber{
    //build left to right then flip 

    char* res = (char*)malloc(10* sizeof(char));
    int i = 0;
    while (columnNumber > 0){
        columnNumber--;
        //place char at idx i, then increment i
        res[i++] = (columnNumber % 26) + 'A';
        columnNumber /= 26;
    }
    res[i] = '\0';

    int left = 0;
    int right = i - 1;

    while (left < right){
        char temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left++;
        right--;
    }
    return res;
}

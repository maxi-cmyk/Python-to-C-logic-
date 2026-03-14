// Practice for: 0006_zigzag.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows){
    if (numRows == 1 || numRows >= strlen(s)){
        return s;
    }

    int len = strlen(s);
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int cycle = 2 * numRows - 2;

    for (int r = 0; r < numRows; r++){
        for (int i = r; i < len; i += cycle){
            res[index++] = s[i];
            int diag = i + cycle - 2 * r;

            if (r > 0 && r < numRows - 1 && diag < len) {
                res[index++] = s[diag];
            }
        }
    }
    res[index] = '\0';
    return res;
}
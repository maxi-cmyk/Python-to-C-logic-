// Practice for: 0119_pascal_triangle_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int* getRow (int rowIndex, int* rowSize){
    int* res = calloc(rowIndex + 1, sizeof(int));
    long long temp = 1;
    res[0] = 1;

    for (int i = 1; i <= rowIndex; i++){
        //nCr, n--, r++
        temp = temp * (rowIndex - i) / i;
        res[i] = (int)temp;
    }
    *rowSize = rowIndex+1; 
    return res;
}

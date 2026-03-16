// Practice for: 0089_gray_code.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int* grayCode(int n, int* returnSize){
    //bit shift to left to determine size
    int total_num = 1 << n; 
    //no need for pow(2, n) sicne we have already bitshifted
    int* res = (int*)malloc(total_num * sizeof(int));

    for (int i = 0; i < total_num; i++){
        res[i] = i ^ (i >> 1);
    }
    *returnSize = total_num;
    return res; 
}

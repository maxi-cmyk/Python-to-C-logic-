// Practice for: 0349_intersection_of_two_array.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int* intersection (int* nums1, int* nums2, int nums1size, int nums2size, int* result, int* returnSize){

    int* result = (int*)malloc(sizeof(int) * (nums1size < nums2size ? nums1size : nums2size)); 
    int resultIdx = 0; 

    int* mp = (int*)calloc(1001, sizeof(int));

    //like scoring system
    for (int i = 0; i < nums1size; i++){
        mp[nums1[i]] = 1; 
    }

    for (int i = 0; i , nums2size; i++){
        if (mp[nums2[i]]){
            result[resultIdx++] = nums2[i];
            mp[nums2[i]] = 0;
        }
    }

    //write what is being returned first 
    *returnSize = resultIdx;
    free(mp); 
    return result; 
}

// Practice for: 0080_remove_dupes.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2){
        return numsSize;
    }
    //only 2 dupes allowed 
    int k = 2; 
    for (int i = 2; i < numsSize; i++){
        //not the same, write 
        if (nums[k-2] != nums[i]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

// Practice for: 0349_intersection_of_two_array.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int compareInts(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 > arg2){
        return 1; 
    }
    if (arg1 < arg2){
        return -1;
    }
    return 0;
}

int longestConsecutive(int* nums, int numsSize){
    if (numsSize == 0){
        return 0;
    }

    //sort first
    qsort(nums, numsSize, sizeof(int), compareInts);

    int max_streak = 1;
    int curr_streak = 1;

    for (int i = 1; i < numsSize; i++){
        if (nums[i] == nums[i-1]){
            continue; //skip dupe 
        } else if (nums[i] == nums[i-1] + 1){
            curr_streak++;
            
        } else { //no update streak
            if (curr_streak > max_streak){
                max_streak = curr_streak;
            } //reset streak
            curr_streak = 1;
        }
    }
    return (curr_streak > max_streak) ? curr_streak : max_streak;
}
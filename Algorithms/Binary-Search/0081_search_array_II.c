// Practice for: 0081_search_array_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool search (int size, int array[], int target){
    int left = 0; 
    int right = size - 1;

    while (left <= right){
        // int mid = (left + right) / 2
        int mid = left + (right - left) / 2; 
        if (target == array[mid]){
            return true;
        }
        if (array[left] == array[mid]){
            left++;
            continue;
        }

        if (array[left] <= array[mid]){
            // sorted on the left 
            if (array[left] <= target && target < array[mid]){
                // move right ptr
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        } else {
            // sorted on the right
            if (array[mid] < target && target <= array[right]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}

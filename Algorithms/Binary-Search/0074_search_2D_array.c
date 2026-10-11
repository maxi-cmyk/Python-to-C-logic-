// Practice for: 0074_search_2D_array.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// binary search in 2D

bool searchMatrix(int rows, int cols, int matrix[rows][cols], int target){
    int low = 0;
    int high = (rows * cols) - 1;

    while (low <= high){
        int mid = (high - low) / 2;
        int mid_val = matrix[mid / cols][mid % cols];

        if (mid_val == target){
            return true;
        } else if (mid_val < target){
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return false;
}

int main(void)
{
    int matrix[3][4] = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    printf("%s\n",
           searchMatrix(3, 4, matrix, 16) ? "true" : "false");
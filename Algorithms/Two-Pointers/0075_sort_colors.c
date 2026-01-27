// Practice for: 0075_sort_colors.py
// Bridge logic from Python to C pointers here.

//sort in place and with O(n) time
//red is 0, white is 1, blue is 2

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize){
    int red = 0;
    int white = 0;
    int blue = numsSize - 1;

    while(white <= blue){
        if (nums[white] == 0){
            swap(&nums[red], &nums[white]);
            white++;
            red++;
        } else if (nums[white] == 1){
            white++;
        } else{
            swap(&nums[blue], &nums[white]);
            blue--;
        }
    }
}

void printArray(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], (i == numsSize - 1) ? "" : ", ");
    }
    printf("]\n");
}

void run_test(int* nums, int numsSize, char* testName) {
    printf("Running %s...\n", testName);
    printf("Before: ");
    printArray(nums, numsSize);
    
    sortColors(nums, numsSize);
    
    printf("After:  ");
    printArray(nums, numsSize);
    printf("---------------------------\n");
}

int main() {
    // Case 1: Standard LeetCode example
    int case1[] = {2, 0, 2, 1, 1, 0};
    run_test(case1, 6, "Standard Scramble");

    // Case 2: Minimal mix
    int case2[] = {2, 0, 1};
    run_test(case2, 3, "The Blue Trap");

    // Case 3: Already sorted
    int case3[] = {0, 1, 2};
    run_test(case3, 3, "Already Sorted");

    // Case 4: Only 0s and 2s
    int case4[] = {2, 0, 2, 0};
    run_test(case4, 4, "Missing Middle Color (1s)");

    // Case 5: Single element
    int case5[] = {1};
    run_test(case5, 1, "Single Element");

    return 0;
}


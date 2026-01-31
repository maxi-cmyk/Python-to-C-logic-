// Practice for: 0137_single_number_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize){
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < numsSize; i++){
        //add to ones if not in twos, read this like discrete maths
        ones = (ones ^ nums[i]) & ~twos;
        //add to twos if not in new ones
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

void run_test(int* nums, int size, int expected) {
    int result = singleNumber(nums, size);
    printf("Result: %d | Expected: %d | %s\n", 
           result, expected, (result == expected ? "PASS" : "FAIL"));
}

int main() {
    printf("--- #137 Single Number II Test Suite ---\n\n");

    int t1[] = {2, 2, 3, 2};
    run_test(t1, 4, 3);

    int t2[] = {0, 1, 0, 1, 0, 1, 99};
    run_test(t2, 7, 99);

    int t3[] = {-2, -2, 1, -2};
    run_test(t3, 4, 1);

    int t4[] = {4, 4, 4, -5};
    run_test(t4, 4, -5);

    return 0;
}

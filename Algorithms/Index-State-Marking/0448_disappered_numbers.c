// Practice for: 0448_disappered_numbers.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findDisappearedNumbers (int* nums, int numsSize, int* returnSize){
    // remember to return allocated memory size, array has no metadata
    // index state marking 
    for (int i = 0; i < numsSize; i++){
        int idx = abs(nums[i]) - 1; 
        if (nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
    }
    //allocate on heap
    int* res = (int*)malloc(numsSize * sizeof(int));

    if (!res){
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > 0){
            //add 1 to idx for missing value since started from zero
            res[count++] = i + 1;
        }
    }
    *returnSize = count; 
    res = realloc(res, count * sizeof(int));
    return res;
}

void runTestCase(int id, int* input, int size, int* expected, int expectedSize) {
    int returnSize = 0;
    int* actual = findDisappearedNumbers(input, size, &returnSize);

    bool match = (returnSize == expectedSize);
    for (int i = 0; match && i < returnSize; i++) {
        if (actual[i] != expected[i]) match = false;
    }

    printf("Test %d: %s [Got: ", id, match ? "PASSED" : "FAILED");
    for (int i = 0; i < returnSize; i++) printf("%d ", actual[i]);
    printf("| Expected: ");
    for (int i = 0; i < expectedSize; i++) printf("%d ", expected[i]);
    printf("]\n");

    free(actual); // Verify caller cleanup works cleanly
}

int main() {
    int t1[] = {1};
    int e1[] = {};
    runTestCase(1, t1, 1, e1, 0);

    int t2[] = {1, 1};
    int e2[] = {2};
    runTestCase(2, t2, 2, e2, 1);

    int t3[] = {2, 2, 2, 2};
    int e3[] = {1, 3, 4};
    runTestCase(3, t3, 4, e3, 3);

    int t4[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int e4[] = {5, 6};
    runTestCase(4, t4, 8, e4, 2);

    return 0;
}
// Practice for: 0228_summary_ranges.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize){

    //returnSize is returned as a pointer bcs it would allow 
    //function to write directly into caller stack frame 
    if (numsSize == 0){
        *returnSize = 0;
        return NULL; 
    } 
    
    char **res = (char**)malloc(sizeof(char*)* numsSize); 
    if (!res){
        *returnSize = 0; 
        return NULL;
    }

    int count = 0; 
    for (int i = 0; i < numsSize; i++){
        int start = nums[i];
        while (i + 1 < numsSize && (long)nums[i+1] == (long)nums[i] + 1){
            i++;
        }
        int end = nums[i]; 
        res[count] = (char*)malloc(32*sizeof(char));
        if (start == end){
            snprintf(res[count], 32, "%d", start); 
        } else {
            snprintf(res[count], 32, "%d -> %d", start, end);
        }
        count++; 
    }
    *returnSize = count; 
    return res; 
}

// Helper harness to run test cases and manage memory
void runTestCase(int testNum, int* nums, int numsSize) {
    printf("=== Test Case %d ===\n", testNum);
    printf("Input: [");
    for (int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], (i == numsSize - 1) ? "" : ", ");
    }
    printf("]\n");

    // 1. Caller declares returnSize on its local stack frame
    int returnSize = -1; // Initialized to sentinel to prove it gets overwritten

    // 2. Pass the memory address (&returnSize) to the callee
    char **result = summaryRanges(nums, numsSize, &returnSize);

    // 3. Caller reads `returnSize` to know how many strings were returned
    printf("Returned Size (*returnSize): %d\n", returnSize);
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"%s", result[i], (i == returnSize - 1) ? "" : ", ");
    }
    printf("]\n");

    // 4. Caller frees all dynamically allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]); // Free individual row strings
    }
    free(result);        // Free the pointer spine
    printf("\n");
}

int main(void) {
    // Test 1: Standard mixed ranges and single points
    int t1[] = {0, 1, 2, 4, 5, 7};
    runTestCase(1, t1, sizeof(t1) / sizeof(t1[0]));

    // Test 2: Isolated values and pairs
    int t2[] = {0, 2, 3, 4, 6, 8, 9};
    runTestCase(2, t2, sizeof(t2) / sizeof(t2[0]));

    // Test 3: Empty input array
    runTestCase(3, NULL, 0);

    // Test 4: Single-element array
    int t4[] = {-1};
    runTestCase(4, t4, sizeof(t4) / sizeof(t4[0]));

    // Test 5: Negative bounds and large range spans
    int t5[] = {-2147483648, -2147483647, 0, 2147483646, 2147483647};
    runTestCase(5, t5, sizeof(t5) / sizeof(t5[0]));

    // Test 6: random
    int t6[] = {56, 90, 101, 300, 301};
    runTestCase(5, t6, sizeof(t6) / sizeof(t6[0]));
    return 0;
}

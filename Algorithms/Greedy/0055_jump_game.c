// Practice for: 0055_jump_game.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool canJump(int *nums, int numsSize){
    int goal = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--){
        if(i + nums[i] >= goal){
            goal = i;
        }
    }
    return goal == 0;
}

void run_test(int* nums, int size, bool expected) {
    bool result = canJump(nums, size);
    printf("Input: [");
    for(int i = 0; i < size; i++) printf("%d%s", nums[i], i == size-1 ? "" : ", ");
    printf("] | Expected: %s | Result: %s\n", 
           expected ? "true" : "false", 
           result ? "true" : "false");
    
    if (result == expected) printf("✅ PASS\n");
    else printf("❌ FAIL\n");
    printf("--------------------------------------------------\n");
}

int main() {
    // Case 1: Standard Success
    int t1[] = {2, 3, 1, 1, 4};
    run_test(t1, 5, true);

    // Case 2: The Zero Trap
    int t2[] = {3, 2, 1, 0, 4};
    run_test(t2, 5, false);

    // Case 3: Single Element (Edge Case)
    int t3[] = {0};
    run_test(t3, 1, true);

    // Case 4: The Leap
    int t4[] = {5, 0, 0, 0, 0, 0};
    run_test(t4, 6, true);

    return 0;
}
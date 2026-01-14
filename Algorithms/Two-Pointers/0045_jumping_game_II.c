// Practice for: 0045_jumping_game_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (a > b ? a : b)

int jump (int *nums, int numsSize){
    //use two pointers to track

    int near = 0;
    int far = 0;
    int jumps = 0;

    while(far < numsSize -1){
        int max_dist = 0;
        for(int i = near; i < far + 1; i++){
            max_dist = MAX(max_dist, i + nums[i]);
        }
        near = far + 1;
        far = max_dist;
        jumps++;

    }
    return jumps;

}

void run_jump_test(int* nums, int size, int expected) {
    int result = jump(nums, size);
    printf("Input: [");
    for(int i = 0; i < size; i++) printf("%d%s", nums[i], i == size-1 ? "" : ", ");
    printf("] | Expected: %d | Result: %d\n", expected, result);
    
    if (result == expected) printf("✅ PASS\n");
    else printf("❌ FAIL\n");
    printf("--------------------------------------------------\n");
}

int main() {
    // Case 1: Standard
    int t1[] = {2, 3, 1, 1, 4};
    run_jump_test(t1, 5, 2);

    // Case 2: Single element
    int t2[] = {0};
    run_jump_test(t2, 1, 0);

    // Case 3: Forced linear steps
    int t3[] = {1, 1, 1, 1, 1};
    run_jump_test(t3, 5, 4);

    // Case 4: The Leap
    int t4[] = {10, 0, 0, 0};
    run_jump_test(t4, 4, 1);

    return 0;
}

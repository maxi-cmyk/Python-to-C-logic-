// Practice for: 0031_next_permutations.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

//swap helper function
void swap (int *a, int *b){
    int temp = *a; //swapping addresses
    *a = *b;
    *b = temp;
}

void reverse (int *nums, int start, int end){
    while (start < end) {
        swap(&nums[start],&nums[end]); //swap addresses
        start++;
        end--;
    }
}

void nextPermutation (int *nums, int numsSize){
    int i = numsSize - 1;
    while (i > 0 && nums[i-1] >= nums[i]){ //find pivot, first decreasing element
        i--;
    }
    if (i == 0){
        reverse(nums, i, numsSize-1);
        return;
    }
    int j = numsSize - 1;
    //looking for smallest element from right of pivot that is larger than pivot 
    while (j > i-1 && nums[j] <= nums[i-1]){ 
        j--;

    } 
    swap(&nums[i-1], &nums[j]);
    reverse(nums, i, numsSize-1);
}

void printArray(int *nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", nums[i], i == size - 1 ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    // Case 1: Standard
    int case1[] = {1, 2, 3};
    nextPermutation(case1, 3);
    printf("Case 1: "); printArray(case1, 3);

    // Case 2: Wrap around
    int case2[] = {3, 2, 1};
    nextPermutation(case2, 3);
    printf("Case 2: "); printArray(case2, 3);

    // Case 3: Pivot at start
    int case3[] = {1, 3, 2};
    nextPermutation(case3, 3);
    printf("Case 3: "); printArray(case3, 3);

    return 0;
}
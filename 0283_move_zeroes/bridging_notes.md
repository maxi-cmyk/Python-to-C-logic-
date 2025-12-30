#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    // 'left' is our slow pointer (where the next non-zero should go)
    int left = 0;

    // 'right' is our fast pointer (the scout)
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != 0) {
            // THE C SWAP: nums[left], nums[right] = nums[right], nums[left]
            // We use a temporary variable to hold the value
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            // Move the non-zero boundary forward
            left++;
        }
    }
}

//test
int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int size = 5;

    moveZeroes(arr, size);

    // Print result: 1 3 12 0 0 
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Practice for: 0011_container_max_area.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int max_area = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right){
        max_area = MAX(max_area, (right - left) * MIN(height[left], height[right]));
        if (height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

void test_11(int* heights, int size, int expected) {
    int result = maxArea(heights, size);
    printf("Result: %d | Expected: %d | %s\n", 
            result, expected, (result == expected ? "PASS" : "FAIL"));
}

int main() {
    int case1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    test_11(case1, 9, 49);

    int case2[] = {1, 1};
    test_11(case2, 2, 1);

    int case3[] = {4, 3, 2, 1, 4};
    test_11(case3, 5, 16);

    return 0;
}

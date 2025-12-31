// Practice for: 0069_sqrt(x).py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    if (x < 2){
        return x;
    }
    int left = 1;
    int right = x/2;

    while (left <= right){
        int mid = left + (right - left) / 2;
        long square = (long)mid * mid;

        if (square == x){
            return mid;
        } else if (square < x){
            left = mid+1; //in binary search, we move only left and right!
        } else {
            right = mid-1;
        }
    }
    return right;
}

int main() {
    int test_inputs[] = {0, 1, 4, 8, 16, 2147395600};
    int expected_outputs[] = {0, 1, 2, 2, 4, 46340};
    int num_tests = 6;

    printf("--- Testing Sqrt(x) Binary Search ---\n");

    for (int i = 0; i < num_tests; i++) {
        int result = mySqrt(test_inputs[i]);
        if (result == expected_outputs[i]) {
            printf("PASS: sqrt(%d) = %d\n", test_inputs[i], result);
        } else {
            printf("FAIL: sqrt(%d) | Expected %d, but got %d\n", 
                   test_inputs[i], expected_outputs[i], result);
        }
    }

    return 0;
}

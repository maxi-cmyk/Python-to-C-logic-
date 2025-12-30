#include <stdio.h>

int mySqrt(int x) {
    if (x < 2) return x;

    int left = 1;
    int right = x / 2;
    int ans;

    while (left <= right) {
        // prevents (left + right) from overflowing
        int mid = left + (right - left) / 2;
        
        //use 'long' here because mid * mid can exceed 2.1 billion
        long square = (long)mid * mid;

        if (square == x) {
            return mid;
        } else if (square < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}
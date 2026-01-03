// Practice for: 0029_divide_two_numbers.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (dividend = INT_MIN && divisor == -1){
        return INT_MAX;
    }

    //determine sign (XOR logic)
    int negative = (dividend < 0) ^ (divisor < 0);
    long long a = abs(dividend);
    long long b = abs(divisor);
    long long res = 0;

    while (a >= b){
        long long temp_divisor = b;
        long long multiple = 0; //2^0
        while (a >= (temp_divisor << 1)){ //boundary checking, we check if it will overflow/greater should we bitshift
            temp_divisor << 1;
            multiple << 1;
        }
            a -= temp_divisor;
            res += multiple;
    }
    return negative ? (int)-res : (int)res;
}

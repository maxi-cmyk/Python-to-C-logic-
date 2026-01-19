// Practice for: 0050_pow(x,n).py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double calc(double base, long long exp){
    if(exp == 0){
        return 1.0;
    }
    double res = calc(base, exp / 2);
    if (exp % 2 == 1){
        return res = res * res * base;
    } else {
        return res * res;
    } 
}

double myPow(double x, int n){
    long long N = n;
    long long ans = calc(x, abs(N));
    return n > 0 ? ans : 1/ans;
}

// Practice for: 0202_happy_number.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

//floyd's cycle detection algo (tortise and hare algo)

int nextNum (int n){
    int output = 0; 

    while (n != 0){
        int digit = n % 10; 
        //remember that c has no ** function
        output += digit * digit;
        n /= 10;
    }
    return output;
}

bool isHappy(int n){
    int slow = nextNum(n);
    int fast = nextNum(nextNum(n));

    while (slow != fast){
        if (fast == 1){
            return true;
        }
        slow = nextNum(slow);
        fast = nextNum(nextNum(fast));

    }
    return slow == 1;
}

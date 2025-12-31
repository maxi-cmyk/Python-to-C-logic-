// Practice for: 0121_best_time_stock.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int bestTimeStock(int prices[], int size){
    if (size == 0){
        return 0;
    }

    int buy_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < size; i++){
        if (prices[i] < buy_price){
            buy_price = prices[i];
        } else { 
            int profit = prices[i] - buy_price;
            if (profit > max_profit){
                max_profit = profit;
            }
        }
        }
        return max_profit;
}

int main() {
    int test1[] = {7, 1, 5, 3, 6, 4};
    int size1 = 6;
    printf("Test 1 Result: %d (Expected: 5)\n", bestTimeStock(test1, size1));

    int test2[] = {7, 6, 4, 3, 1};
    int size2 = 5;
    printf("Test 2 Result: %d (Expected: 0)\n", bestTimeStock(test2, size2));

    return 0;
}

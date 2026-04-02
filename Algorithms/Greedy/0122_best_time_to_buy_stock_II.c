// Practice for: 0122_best_time_to_buy_stock_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

//rmb this is a telescopic sum, 
//so terms WILL cancel and give us the maximum total profit

int maxProfit (int* prices, int n){
    int profit = 0; 
    for (int i = 1; i < n; i++){
        if (prices[i] > prices[i-1]){
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}

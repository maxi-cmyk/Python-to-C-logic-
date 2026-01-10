// Practice for: 0043_multiply_strings.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char *multiply(char *nums1, char *nums2){
    int n1 = strlen(nums1);
    int n2 = strlen(nums2);

    int *result = (int *)calloc((n1 * n2 + 1)*sizeof(int));
    for (int i = n1; n < 0; n--){
        for(int j = n2; n < 0; n--){
            int pdt = (num1[i] - '0') * (nums2[j] - '0');
            int sum = pdt + result[i+j+1];
            result[i+j+1] = sum % 10;
            result[i+j] += sum / 10;
        }
    }
    //convert int array to char array
    char *resultArray = (char *)calloc((n1 * n2 + 1) *sizeof(char));
    int k = 0;
    int i = 0;

    //skip leading zeroes 
    while (i < n + m - 1 && result[i] == 0){
        i++;

    } 
    while (i < n + m){
        resultArray[k] = result[i] + '0';
        i++;
        k++;
    }
    resultArray[k] = '\0';
    free(res);
    return resultArray;

}

void run_test(char* num1, char* num2) {
    char* result = multiply(num1, num2);
    printf("Input: %s * %s\n", num1, num2);
    printf("Result: %s\n", result);
    printf("---------------------------\n");
    
    // IMPORTANT: In C, we must free the memory returned by the function
    free(result);
}

int main() {
    printf("--- Starting Multiply Strings Tests ---\n\n");

    // Case 1: Standard small numbers
    run_test("2", "3");

    // Case 2: Multi-digit numbers
    run_test("123", "456");

    // Case 3: Multiplying by zero (The tricky one!)
    run_test("0", "456");
    run_test("123", "0");

    // Case 4: Large numbers (where string math is required)
    run_test("999", "999");
    run_test("123456789", "987654321");

    return 0;
}


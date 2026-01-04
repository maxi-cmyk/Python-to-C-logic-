// Practice for: 0022_generate_paranthesis.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **res, int *returnSize, char *temp, int n, int open, int close, int pos){
    // (())-> ()(), so we are just updating the inner few, need all combinations 
    if (pos == 2*n){ //buffer
        temp[pos] = '\0';
        res[*returnSize] = (char*)malloc((2*n+1) *sizeof(char));
        strcpy(res[*returnSize], temp);
        (*returnSize)++;
        return;
    }
    

    //open bracket valid? 
    if (open < n){
        temp[pos] = '('; //((
        backtrack(res, returnSize, temp, n, open+1, close, pos+1); //updates here 
    }
    if (close < open){
        temp[pos] = ')'; //  ))
        backtrack(res, returnSize, temp, n, open, close+1, pos+1); //updates here 
    }
}

char **generateParenthesis (int n, int *returnSize){
    char **res = (char**)malloc(2000 *sizeof(char*));
    //buffer 
    char *temp = (char*)malloc((2*n+1) * sizeof(char));
    *returnSize = 0;
    backtrack(res, returnSize, temp, n, 0, 0, 0);
    free(temp);
    return res;
}

int main() {
    int n = 3;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);

    printf("Generated %d pairs for n=%d:\n", returnSize, n);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // Clean up each string
    }
    free(result); // Clean up the array of pointers

    return 0;
}

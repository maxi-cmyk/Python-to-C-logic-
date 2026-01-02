// Practice for: 0017_letter_phone_number.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//hashtable
char* phone_chars[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void convert(char *digits, int idx, char *curr_comb, char **res, int *count){
    if (digits[idx] == '\0'){
        res[*count] = strdup(curr_comb); //strdup is duping the curr_comb
        (*count)++;
        return;
    }

    char *letters = phone_chars[digits[idx] - '0'];
    for (int i = 0; i < strlen(letters); i++){
        curr_comb[idx] = letters[i];
        convert(digits, idx + 1, curr_comb, res, count);
    }
}

char **letterCombinations(char *digits, int *returnSize){
    int len = strlen(digits);
    *returnSize = 0;
    if (len == 0){ //edge case
        return NULL;
    }
    int total_combinations = 1;
    for (int i = 0; i < len; i++){
        total_combinations *= strlen(phone_chars[digits[i] - '0']);     
    }
    char **res = (char **)malloc(total_combinations * sizeof(char*));
    char *curr_comb = (char*)malloc((len+1) * sizeof(char));
    curr_comb[len] = '\0'; //add null terminator 

    int count = 0;
    convert(digits, 0, curr_comb, res, &count);

    *returnSize = count;
    free(curr_comb);
    return res;
}

int main() {
    int returnSize;
    char** res = letterCombinations("23", &returnSize);

    printf("Total combinations: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", res[i]);
        free(res[i]); // Clean up!
    }
    free(res);
    return 0;
}
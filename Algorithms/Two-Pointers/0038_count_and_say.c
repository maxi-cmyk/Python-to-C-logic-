// Practice for: 0038_count_and_say.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char* countAndSay(int n){
    char* curr = (char*)malloc(3000 * sizeof(char));
    char* next = (char*)malloc(3000 * sizeof(char));

    strcpy(curr, "1");

    for(int i = 1; i < n; i++){
        int curr_len = strlen(curr);
        int next_ptr = 0;
        int j = 0;
        
        while (j < curr_len){
            int count = 1;
            //consecutive 
            while(j + 1 < curr_len && curr[j] == curr[j+1]){
                j++;
                count++;
            }
            next[next_ptr++] = count + '0';
            next[next_ptr++] = curr[j];
            j++;
        } 
        next[next_ptr] = '\0';
        strcpy(curr, next);
    }
    free(next);
    return curr;
    
}

void run_test(int n, char* expected) {
    char* result = countAndSay(n);
    
    printf("n = %d\n", n);
    printf("Expected: %s\n", expected);
    printf("Result:   %s\n", result);
    
    if (strcmp(result, expected) == 0) {
        printf("STATUS:   [PASS]\n");
    } else {
        printf("STATUS:   [FAIL]\n");
    }
    printf("---------------------------\n");

    // Clean up the memory allocated by the function
    free(result);
}

int main() {
    run_test(1, "1");
    run_test(2, "11");
    run_test(3, "21");
    run_test(4, "1211");
    run_test(5, "111221");
    run_test(6, "312211");

    return 0;
}

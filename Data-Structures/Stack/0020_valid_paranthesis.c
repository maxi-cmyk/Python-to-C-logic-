// Practice for: 0020_valid_paranthesis.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

bool isValid (char *s){
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for(int i = 0; i < n; i++){
        char c = s[i];

        //push open brackets
        if (c == '(' || c == '[' || c == '{'){
            stack[++top] = c;
        } 
        //handle closing brackets 
        else {
            if (top == -1){
                free(stack);
                return false;
            }
            char last = stack[top--];
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                free(stack);
                return false;
            }
        }
    }
    bool result = (top == -1);
    free(stack);
    return result;
}

void run_test(char* s, bool expected) {
    bool result = isValid(s);
    printf("Input: %-12s | Expected: %s | Result: %s | %s\n", 
           s, 
           expected ? "true " : "false", 
           result ? "true " : "false",
           (result == expected ? "PASS" : "FAIL"));
}

int main() {
    printf("--- Valid Parentheses Test Suite ---\n");
    
    // Test Case 1: Simple
    run_test("()", true);
    
    // Test Case 2: All types
    run_test("()[]{}", true);
    
    // Test Case 3: Wrong partner
    run_test("(]", false);
    
    // Test Case 4: Nested correctly
    run_test("([{}])", true);
    
    // Test Case 5: Starts with closer (The "Empty Stack" test)
    run_test("]", false);
    
    // Test Case 6: Leftover open (The "Final Check" test)
    run_test("((", false);

    return 0;
}

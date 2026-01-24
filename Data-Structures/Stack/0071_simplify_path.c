// Practice for: 0071_simplify_path.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path){
    int n = strlen(path);
    char** stack = (char**)malloc(n * sizeof(char));
    int top = 0;

    char* token = strtok(path, "/");
    while (token != NULL){
        //use strcmp
        if(strcmp(token, "..") == 0){
            if (top > 0){
                top--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0){
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }
    char* result = (char*)malloc((n+1) * sizeof(int));
    result[0] = '\0';
    if (top == 0){
        strcpy(result, "/");
    } else {
        for(int i = 0; i < top; i++){
            strcat(result, "/");
            strcat(rsult, stack[i]);
        }
    }
    free(stack);
    return result;
}

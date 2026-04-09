// Practice for: 0098_restore_ip_address.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void backtrack(char * s, int index, int seg, int *path, char **res, int *returnSize){
    // 4 segments, stop 
    if (seg == 4){
        //reached null terminator 
        if (s[index] == '\0'){
            //allocate 16 bytes total 
            char *ip = (char*)malloc(16 * sizeof(char)); 
            sprintf(ip, "%d.%d.%d.%d", path[0], path[1], path[2], path[3]);
            res[*returnSize] = ip;
            (*returnSize)++;
        }
        return;
    }
    int val = 0; 
    for (int i = index; i < index + 3 && s[i] != '\0'; i++){
        if (i > index && s[index] == '0'){
            break;
        }
        val = val * 10 + (s[i] - '0');
        if (val <= 255){
            path[seg] = val; 
            backtrack(s, i + 1, seg + 1, path, res, returnSize);
        }
    }
}

char **restoreIpAddresses(char *s, int* returnSize){
    *returnSize = 0;
    int len = strlen(s);
    if (len < 4 || len > 12){
        return NULL;
    }
    //allocate mem 
    char **res = (char **)malloc(100 * sizeof(char*));
    int path[4] = {0};
    backtrack(s, 0, 0, path, res, returnSize);
    return res;
}
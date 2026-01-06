// Practice for: 0443_string_compression.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compress(char* chars, int charSize){
    int i = 0;
    int write = 0;
    while (i < charSize){
        char curr = chars[i];
        int count = 0;
        while (i < charSize && chars[i] == curr){
            count+=1;
            i+=1;
        } 
        chars[write] = curr;
        write++;

        if (count > 1){
            char buffer[10];
            int len = sprintf(buffer, "%d", count); //turns int to string, return len of string 
            // (dest, type, source)
            for(int n = 0; n < len; n++){
                chars[write] = buffer[n];
                write++;
            }
        }
    }
    return write; 
}

int main() {
    char test[] = {'a','a','b','b','c','c','c'};
    int size = sizeof(test) / sizeof(test[0]);

    int new_len = compress(test, size);

    printf("New Length: %d\n", new_len);
    printf("Compressed String: ");
    for (int i = 0; i < new_len; i++) {
        printf("%c", test[i]);
    }
    printf("\n");

    return 0;
}



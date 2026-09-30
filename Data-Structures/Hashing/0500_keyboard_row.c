// Practice for: 0500_keyboard_row.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> 

char** keyboardRow (char** words, int wordsSize, int* returnSize){
    // Index:  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
    // Row:    2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
    const int rowMap[26]= {
        2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 
        3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3
    };

    char** res = (char**)malloc(wordsSize * sizeof(char*)); 
    int count = 0; 

    for (int i = 0; i < wordsSize; i++){
        char* word = words[i];
        //identify first char row
        int targetRow = rowMap[tolower((unsigned char)word[0]) - 'a'];
        bool valid = true; 
        //check rest
        for (int j = 1; word[j] != '\0'; j++){
            int currRow = rowMap[tolower((unsigned char) word[j])- 'a'];
            // early exit 
            if (currRow != targetRow){
                valid = false; 
                break;
            }
        }\
        // all pass, add to res
        if (valid){
            res[count++] = word;
        }
    }
    // update count
    *returnSize = count; 
    return res;
}

//alternative way, bitmasking 

static inline int create_mask (const char* s){
    // make mask using or (|=)
    int mask = 0; 
    while (*s){
        // left shift to pos based on letter
        // bit flip if char pos 
        mask |= (1 << (*s- 'a'));
        s++;
    }
    return mask;
}

char** findWords (char** words, int wordsSize, int* returnSize){
    int row1 = create_mask("qwertyuiop"); 
    int row2 = create_mask("asdfghjkl"); 
    int row3 = create_mask("zxcvbnm");

    char** res = (char**)malloc(wordsSize * sizeof(char*)); 
    int count = 0; 

    for (int i = 0; i < wordsSize; i++){
        char* word = words[i]; 
        int word_mask = 0;
        for (int j = 0; word[j] != '\0'; j++){
            // make similar bitmask 
            word_mask |= (1 << tolower((unsigned char)word[j] - 'a'));
        }
        if ((word_mask | row1 == row1) || (word_mask | row3 == row2) || (word_mask | row3 == row3)){
            res[count++] = word;
        }
    }
    *returnSize = count;
    return res;

}

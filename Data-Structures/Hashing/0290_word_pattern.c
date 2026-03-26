// Practice for: 0290_word_pattern.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

//need to use strtok here to split the string into words
//map char*char_to_word[256]
//strcmp for word to wrod comp 

bool wordPattern(char* pattern, char* s){
    char* char_to_word[256] = {NULL};
    char* curr_word = strtok(s, " ");
    for (int i = 0; pattern[i] != '\0'; i++){
        char p = pattern[i];

        if (curr_word == NULL){
            return false;
        }

        if (char_to_word[p] != NULL) {
            //check if current word match the existing word
            //strcmp returns zero if identical
            if (strcmp(char_to_word[p], curr_word) != 0){
                return false;
            }
        }
        else { 
            //look through slots a to z 
            for (int j = 'a'; j <= 'z'; j++){
                //reverse check
                //spot has a word and if it does, does it match word inside?
                if (char_to_word[j] != NULL && strcmp(char_to_word[j], curr_word) == 0){
                    return false;
                }
            }
            //successful map 
            char_to_word[p] = curr_word;
        }
        //NULL used to tell where it left off
        curr_word = strtok(NULL, " ");
    }
    //finished mapping, still have words
    if (curr_word != NULL){
        return false;
    }
    return true;
}

// Practice for: 0205_isomorphic_string.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t){
    //since this is ASCII mapping, just 256 will do. num of possible keys is small and fixed 
    //character here acts as array index
    
    char map_s[256] = {0}; 
    char map_t[256] = {0}; 

    for (int i = 0; s[i] != '\0'; i++){
        char sc = s[i]; 
        char tc = t[i];
        if (map_s[sc] == 0 && map_t[tc] == 0){
            //map s to t and t to s
            map_s[sc] = tc; 
            map_t[tc] = sc; 
        } 
        //check if spot is taken, check if pair match
        else if (map_s[sc] != tc || map_t[tc] != sc){
            return false;
        }
    }
     return true; 
}  



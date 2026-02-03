// Practice for: 0318_max_product.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProduct(char** words, int wordsSize){
    if (wordsSize == 0){
        return 0;
    }

    int* masks = (int*)malloc(wordsSize * sizeof(int));
    int* lens = (int*)malloc(wordsSize * sizeof(int));
    int pdt = 0;

    for (int i = 0; i < wordsSize; i++){
        int mask = 0;
        int len = 0;
        for (int j = 0; words[i][j] != '\0'; j++){
            //bitshift to left so its unqiue 
            mask |= (1 << (words[i][j] - 'a'));
            len++;
        }
        masks[i] = mask;
        lens[i] = len;
    }
    //brute force compare

    for (int i = 0; i < wordsSize; i++){
        for( int j = i + 1; j < wordsSize; j++){
            //use &, if == 0, then unique, so multiply
            if ((masks[i] & masks[j]) == 0){
                pdt = MAX(pdt, lens[i] * lens[j]);
            }
        }
    }
    free(masks);
    free(lens);
    return pdt;
}

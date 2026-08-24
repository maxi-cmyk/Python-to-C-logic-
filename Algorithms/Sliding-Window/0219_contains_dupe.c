// Practice for: 0219_contains_dupe.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val; 
    int idx;
} Element; 

int compareElements(const void *a, const void *b) {
    const Element *elemA = (const Element *)a;
    const Element *elemB = (const Element *)b;

    if (elemA->val != elemB->val) {
        return (elemA->val > elemB->val) - (elemA->val < elemB->val);
    }
    return (elemA->idx > elemB->idx) - (elemA->idx < elemB->idx);
}

bool containsNearbyDupe(int* nums, int numsSize, int k){
    if (numsSize <=1 || k <= 0){
        return false;
    }

    Element *elements = (Element*)malloc(sizeof(Element) * numsSize);

    if (!elements){
        return false;
    }

    for (int i = 0; i < numsSize; i++){
        elements[i].val = nums[i];
        elements[i].idx = i;
    }
    qsort(elements, numsSize, sizeof(Element), compareElements);

    for (int i = 0; i < numsSize -1; i++){
        if(elements[i].val == elements[i+1].val){
            if(abs(elements[i].idx - elements[i+1].idx) <= k){
                free(elements); 
                return true;
            }
        }
    }
    free(elements);
    return false;
}


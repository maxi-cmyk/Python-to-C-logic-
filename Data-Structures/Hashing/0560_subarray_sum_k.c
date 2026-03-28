// Practice for: 0560_subarray_sum_k.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

//hashmap node
//prefix sum hash map 
//have to start with {0:1} as a base value, means we hae seen 0 once 

struct HashNode { 
    int prefix_sum;
    int count; 
    UT_hash_handle hh;
};

int subArraySum(int* nums, int numsSize, int k) {
    struct HashNode *hash_table = NULL;
    struct HashNode *current_node, *temp_node; 
    int count = 0; 
    int total = 0;

    //adding {0:1}
    current_node = (struct HashNode*)malloc(sizeof(struct HashNode));
    current_node->prefix_sum = 0;
    current_node->count = 1; 
    HASH_ADD_INT(hash_table, prefix_sum, current_node);

    for (int i = 0; i < numsSize; i++){
        total += nums[i];
        int target_past_sum = total - k;

        HASH_FIND_INT(hash_table, &target_past_sum, temp_node);
        if (temp_node != NULL){
            //check if total - k exists
            count += temp_node->count;
        }

        HASH_FIND_INT(hash_table, &total, temp_node);
        if (temp_node != NULL){
            //seen value 
            temp_node->count++;
        } else {
            //first time seeing, build new node
            current_node = (struct HashNode*)malloc(sizeof(struct HashNode));
            current_node->prefix_sum = total; 
            current_node->count = 1;
            HASH_ADD_INT(hash_table, prefix_sum, current_node);
        }
    }
    //iterate through hash table and free every node
    HASH_ITER(hh, hash_table, current_node, temp_node) {
        HASH_DEL(hash_table, current_node);
        free(current_node);
    }
    return count;
    
}

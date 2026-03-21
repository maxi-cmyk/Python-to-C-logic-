// Practice for: 0203_remove_element.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val; 
    struct ListNode *next;
}; 

struct ListNode *removeElements (struct ListNode *head, int val){
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    dummy->next = head;
    struct ListNode *current = dummy;
    
    while (current->next != NULL){
        if (current->next->val == val){
            //must remove from memory
            struct ListNode *trash = current->next;
            current->next = current->next->next;
            free(trash);
        } else {
            current = current->next;
        }
    }
    //must initialise new variable, free dummy variable
    struct ListNode *newHead = dummy->next;
    free(dummy);
    return newHead;

}

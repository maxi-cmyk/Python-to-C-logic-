// Practice for: 0141_linked_list_cycle.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head){
    struct ListNode *fast = head; 
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next; 

        if (fast == slow){
            return true;
        }
    }
    return false;
}
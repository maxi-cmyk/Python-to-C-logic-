// Practice for: 0142_linked_list_cycle_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val; 
    struct ListNode *next;
};

// returning address of cycle's starting node 
struct ListNode *cycle (struct ListNode *head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    // detect cycle 
    struct ListNode *slow = head; 
    struct ListNode *fast = head; 

    while (fast != NULL && fast->next != NULL){
        // fast ptr move twice as fast 
        slow = slow->next; 
        fast = fast->next->next;

        // meet, cycle detected, find next meeting point 
        // return slow 

        if (slow == fast){
            slow = head; 
            while (slow != fast){
                slow = slow->next; 
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

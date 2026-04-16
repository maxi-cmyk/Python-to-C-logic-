// Practice for: 0019_remove_node.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

//use two pointer tech 
//time complexity -> o(n), space complexity -> o(1)

struct ListNode {
    int val; 
    struct ListNode *next;
}; 

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //make dummy node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head; 

    //make 2 pointers, start at dummy
    struct ListNode* fast = dummy; 
    struct ListNode* slow = dummy; 

    //move fast pointer first by n places
    for (int i = 0; i <= n; i++){
        fast = fast->next;
    }

    //mathematically guarenteed that when fast hits null, slow will be at (n-1)th node
    while(fast != NULL){
        fast = fast->next; 
        slow = slow->next;
    }

    //reached target, remove 
    //need to make a temp basically to remove (grab the address first, then delete)
    struct ListNode* target = slow->next; 
    
    //connect first
    slow->next = slow->next->next;
    //destroy target
    free(target);

    //start of list, need this to return the full new list
    struct ListNode* newHead = dummy->next; 

    //free dummy
    free(dummy); 
    return newHead;
}

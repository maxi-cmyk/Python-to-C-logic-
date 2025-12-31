//ned to malloc the new list 
#include <stdio.h> 
#include <stdlib.h> 

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    //create a dummy variable
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *curr = dummy; //make a copy of dummy to move fwd
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) { //traverse the whole thing
        int sum = carry;

        if (l1 != NULL){
            sum += l1 -> val; //while l1 still has a value, add it to the sum and move fwd
            l1 = l1 -> next;
        }

        if (l2 != NULL){
            sum += l2 -> val; //while l2 still has a value, add it to the sum and move fwd
            l2 = l2 -> next;
        }

        carry = sum/10;
        //create new struct 
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode -> val = sum % 10;
        newNode-> next = NULL;

        curr->next = newNode; //link to new node, move curr
        curr = curr->next;

        struct ListNode* res = dummy->next; //result starts from dummy->next as we dont want the zero (first element)
        //free (dummy);
        return res;

    }
}


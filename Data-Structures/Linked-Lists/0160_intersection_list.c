// Practice for: 0160_intersection_list.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode (struct ListNode *headA, struct ListNode *headB){
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    while (ptrA != ptrB){
        ptrA = (ptrA != NULL) ? ptrA->next : headB;
        ptrB = (ptrA != NULL) ? ptrB->next : headA;
    }
    return ptrA;
}
// safe to return ptrA bc if no intersect, ptrA will traverse the whole of B and return NULL

// Practice for: 0021_merge_two_linked_list.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;

};

// Helper 1: Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper 2: Print the list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2){
    //dummy varible is on stack. we only care about dummy.next onwards
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL){
        if (list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next; //increment list1
        } else {
            tail->next = list2;
            list2 = list2->next; //increment list2
        }

        tail = tail->next; //increment tail
    }
    
    if (list1 != NULL){
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    return dummy.next; //we are only interested in dummy.next onwards!
}

int main() {
    // TEST 1: Overlapping
    // L1: 1 -> 2 -> 4
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    
    // L2: 1 -> 3 -> 4
    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    printf("Test 1 (Overlapping):\n");
    struct ListNode* res1 = mergeTwoLists(l1, l2);
    printList(res1); // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL

    // TEST 2: One empty
    struct ListNode* l3 = NULL;
    struct ListNode* l4 = createNode(0);
    
    printf("\nTest 2 (One Empty):\n");
    struct ListNode* res2 = mergeTwoLists(l3, l4);
    printList(res2); // Expected: 0 -> NULL

    // TEST 3: Different Lengths
    struct ListNode* l5 = createNode(5);
    struct ListNode* l6 = createNode(1);
    l6->next = createNode(2);
    l6->next->next = createNode(3);

    printf("\nTest 3 (Diff Lengths):\n");
    struct ListNode* res3 = mergeTwoLists(l5, l6);
    printList(res3); // Expected: 1 -> 2 -> 3 -> 5 -> NULL

    return 0;
}
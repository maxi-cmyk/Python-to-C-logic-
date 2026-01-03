// Practice for: 0206_reverse_linked_list.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next; 

};

// Helper to create nodes
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper to print the list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct ListNode* reverseList (struct Listnode *head){
    struct ListNode *prev = NULL; 
    struct ListNode *curr = head;
    struct ListNode *next = NULL; //like a temp 

    while (curr != NULL){ //like arithemic swapping logic 
        next = curr->next;  //a = temp
        curr->next = prev;  //flip direction

        prev = curr; //a = b
        curr = next;//b = temp
    }
    return prev;
}

int main() {
    // 1. Setup: 1 -> 2 -> 3 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    // 2. The Reverse
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    // 3. Cleanup: Always free memory in C!
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


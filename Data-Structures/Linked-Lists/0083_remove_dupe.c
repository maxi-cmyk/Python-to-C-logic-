// Practice for: 0083_remove_dupe.py
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

struct ListNode* deleteDuplicates(struct ListNode *head){
    //list empty or only 1 node
    if (head -> next == NULL || head == NULL){
        return head;
    }

    struct ListNode *temp = head;
    while (temp != NULL && temp -> next != NULL){
        if (temp->val == temp ->next->val){
            struct ListNode *deleteNode = temp->next;
            temp->next = temp->next->next; //skip dupe
            free(deleteNode); //free deleted node 
        } else {
            temp = temp->next; //traverse normally
        }
    }
    return head;
}

int main() {
    // Case: 1 -> 1 -> 2
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);

    printf("Original: ");
    printList(head);

    head = deleteDuplicates(head);

    printf("After Deleting Duplicates: ");
    printList(head);

    //clean memory
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
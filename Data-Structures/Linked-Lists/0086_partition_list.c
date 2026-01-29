// Practice for: 0086_partition_list.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode smallHead, bigHead;

    struct ListNode *small = &smallHead;
    struct ListNode *big = &bigHead;

    while (head != NULL){
        if (head->val < x){
            small->next = head;
            small = small->next;
        } else {
            big->next = head;
            big = big->next;
        } 
        head = head->next;    
    }
    small->next = bigHead.next;
    big->next = NULL;
    return smallHead.next;
}

struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

void printList(struct ListNode* head) {
    if (!head) { printf("EMPTY\n"); return; }
    while (head) {
        printf("%d%s", head->val, head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    // Test Case: Tail is Small
    // Word of caution: The 4 and 5 are >= 3, the 1 is < 3.
    // In the original list, 5 points to 1. 
    // If we don't set 5->next = NULL, we get a loop!
    int arr[] = {4, 5, 1};
    int x = 3;
    
    struct ListNode* list = createList(arr, 3);
    printf("Before Partition (x=%d): ", x);
    printList(list);
    
    list = partition(list, x);
    
    printf("After Partition:        ");
    printList(list);
    
    return 0;
}
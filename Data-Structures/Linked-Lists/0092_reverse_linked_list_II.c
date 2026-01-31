// Practice for: 0092_reverse_linked_list.py
// Bridge logic from Python to C pointers here.

//make a dummy node to anchor the list 

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right){
    if (!head || left == right){
        return head;
    }
    //create node om stack
    struct ListNode dummy;
    dummy.next = head;

    //anchor before reversal
    struct ListNode *prev = &dummy;

    for(int i = 0; i < left - 1; i++){
        prev = prev->next;
    }
    struct ListNode *start = prev->next;

    for (int j = 0; j < right - left; j++){
        struct ListNode *then = start->next;
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;

    }
    return dummy.next;
}

struct ListNode *createList(int* arr, int size){
    if (size == 0){
        return NULL;
    }
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
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

// Helper to print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d%s", head->val, head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* list = createList(arr, 5);

    printf("Original List:  ");
    printList(list);

    // Test Case: Reverse from position 2 to 4
    // Expected: 1 -> 4 -> 3 -> 2 -> 5
    list = reverseBetween(list, 2, 4);

    printf("Reversed (2-4): ");
    printList(list);

    return 0;
}


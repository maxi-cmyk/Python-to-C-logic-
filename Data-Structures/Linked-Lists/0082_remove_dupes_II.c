// Practice for: 0082_remove_dupes_II.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates (struct ListNode *head){
    struct ListNode dummy;
        dummy.val = 0;
        dummy.next = head;

    struct ListNode* prev = &dummy;
    while (head != NULL && head->next != NULL){
        if (head->val == head->next->val){
            int dupe = head->val;
            while (head != NULL && head->next != NULL && head->val == dupe){
                struct ListNode* temp = head;
                head = head->next;
                free(temp);
            }
            prev->next = head;      
        } else {
            prev = head;
            head = head->next;
        }
    }
    return dummy.next;
}

// Helper to create a list from an array
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

// Helper to print the list
void printList(struct ListNode* head) {
    if (!head) {
        printf("EMPTY\n");
        return;
    }
    while (head) {
        printf("%d%s", head->val, head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    // Test Case: End Duplicates
    int arr[] = {1, 2, 2};
    struct ListNode* list = createList(arr, 3);
    
    printf("Before: ");
    printList(list);
    
    list = deleteDuplicates(list);
    
    printf("After:  ");
    printList(list);
    
    return 0;
}

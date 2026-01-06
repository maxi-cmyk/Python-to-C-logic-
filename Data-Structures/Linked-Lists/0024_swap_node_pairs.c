// Practice for: 0024_swap_node_pairs.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{ //linked list
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *swapPairs(struct ListNode *head){
    //edge case 
    if(head == NULL || head-> next== NULL){
        return NULL;
    }

    //dummy 
    ListNode dummy;
    dummy.next = head; //use "." to access the actual value 
    ListNode* prev = &dummy; // prev is a pointer that points to address of dummy, use pointer bcs need to move prev 

    while(prev->next != NULL && prev ->next->next != NULL){
        ListNode* a = prev->next;
        ListNode* b = a->next;

        //swapping
        a->next = b->next; //a points to node after b 
        b->next = a; //b points to a 
        prev->next = b; //prev points to b

        prev = a; //move fwd by 2
    }
    return dummy.next;
}

// Helper: Create a list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
    }
    curr->next = NULL;
    return head;
}

// Helper: Print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* list = createList(arr, 5);

    printf("Original: ");
    printList(list);

    struct ListNode* swapped = swapPairs(list);

    printf("Swapped:  ");
    printList(swapped);

    return 0;
}

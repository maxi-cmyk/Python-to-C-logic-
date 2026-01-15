// Practice for: 0061_rotate_list.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode * next; //struct (node) * next;
};

struct ListNode *rotateRight(struct ListNode *head, int k){
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    int length = 1;
    //find length and tail 
    struct ListNode *tail = head;
    while(tail->next != NULL){ //must put if not count will be 1 too high
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0){
        return head;
    }
    tail->next = head; //connect end to head 

    struct ListNode *newTail = head;
    for(int i = 0; i < length - k - 1; i++){
        newTail = newTail->next;
    }
    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;
    return newHead; //its already a circle so just cut 
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    if (!head) {
        printf("Empty List\n");
        return;
    }
    while (head) {
        printf("%d%s", head->val, head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    // Case 1: Standard [1, 2, 3, 4, 5], k = 2
    struct ListNode* h1 = createNode(1);
    h1->next = createNode(2);
    h1->next->next = createNode(3);
    h1->next->next->next = createNode(4);
    h1->next->next->next->next = createNode(5);

    printf("Test 1 Original: ");
    printList(h1);
    h1 = rotateRight(h1, 2);
    printf("Test 1 Rotated (k=2): ");
    printList(h1);

    // Case 2: Large k [1, 2], k = 5
    struct ListNode* h2 = createNode(1);
    h2->next = createNode(2);

    printf("\nTest 2 Original: ");
    printList(h2);
    h2 = rotateRight(h2, 5);
    printf("Test 2 Rotated (k=5): ");
    printList(h2);

    return 0;
}
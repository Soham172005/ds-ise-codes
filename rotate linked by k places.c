1.	// Rotate a Linked List by ‘k’ places.
Example 1:
input: 1 → 2 → 3 → 4 → 5 , k = 1
output: 5 → 1 → 2 → 3 → 4
Example 2:
input: 1 → 2 → 3 → 4 → 5 , k = 2
output: 4 → 5 → 1 → 2 → 3

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Function to create a new node with a given value
ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to get the length of the linked list
int getListLength(ListNode* head) {
    int length = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to rotate the linked list by 'k' places
ListNode* rotateList(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head; // No rotation needed
    }

    int length = getListLength(head);
    k = k % length; // In case k is larger than the length

    if (k == 0) {
        return head; // No rotation needed if k is multiple of the length
    }

    ListNode* temp = head;
    
    // Find the node before the rotation point
    for (int i = 1; i < length - k; i++) {
        temp = temp->next;
    }

    ListNode* newHead = temp->next; // New head will be the (length - k)th node
    temp->next = NULL; // Disconnect the rotated part

    // Find the last node and link it to the original head
    ListNode* lastNode = newHead;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = head;

    return newHead;
}

// Function to add a number to the linked list (inserting at the end)
ListNode* addNumberToList(int num) {
    ListNode* head = NULL;
    ListNode* temp = NULL;

    if (num == 0) {
        return createNode(0);
    }

    while (num > 0) {
        ListNode* newNode = createNode(num % 10);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        num /= 10;
    }
    return head;
}

int main() {
    // Input: 1 → 2 → 3 → 4 → 5, k = 2
    ListNode* head = addNumberToList(12345); 
    
    int k = 2; // Number of places to rotate
    printf("Original List: ");
    printList(head);
    
    head = rotateList(head, k);
    
    printf("Rotated List by %d places: ", k);
    printList(head);
    
    return 0;
}

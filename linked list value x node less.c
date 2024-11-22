	// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. You should preserve the original relative order of the nodes in each of the two partitions. 
For example: 
●	Input: 1 → 5 → 3 → 2 → 4 → 2  and x = 3
Output: 1 → 2 → 2 → 3 → 5 → 4

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the linked list
void appendNode(ListNode** head, int val) {
    ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to partition the list based on the value x
ListNode* partition(ListNode* head, int x) {
    // Two dummy nodes to represent the beginning of the two partitions
    ListNode *lessHead = NULL, *greaterHead = NULL;
    ListNode *less = NULL, *greater = NULL;

    // Traverse the original list
    while (head != NULL) {
        if (head->val < x) {
            if (less == NULL) {
                lessHead = head;
                less = lessHead;
            } else {
                less->next = head;
                less = less->next;
            }
        } else {
            if (greater == NULL) {
                greaterHead = head;
                greater = greaterHead;
            } else {
                greater->next = head;
                greater = greater->next;
            }
        }
        head = head->next;
    }

    // Avoid cycle in the linked list
    if (less != NULL) less->next = NULL;
    if (greater != NULL) greater->next = NULL;

    // If the "less than x" list is non-empty, connect it to the "greater or equal to x" list
    if (lessHead == NULL) {
        return greaterHead;  // If no node is less than x, return the "greater or equal to x" list
    }

    // Otherwise, concatenate the lists
    less->next = greaterHead;

    return lessHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the partitioning
int main() {
    ListNode* head = NULL;

    // Create the linked list 1 -> 5 -> 3 -> 2 -> 4 -> 2
    appendNode(&head, 1);
    appendNode(&head, 5);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 4);
    appendNode(&head, 2);

    int x = 3;

    printf("Original List: ");
    printList(head);

    // Partition the list based on x
    ListNode* partitionedHead = partition(head, x);

    printf("Partitioned List: ");
    printList(partitionedHead);

    return 0;
}

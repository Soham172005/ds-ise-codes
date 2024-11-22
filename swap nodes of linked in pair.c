/*Swap nodes of a linked list in pairs
Example 1:
input: 1 → 2 → 3 → 4
output: 2 → 1 → 4 → 3
Example 2:
input: 1 → 2 → 3
output: 2 → 1 → 3*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to swap nodes of the linked list in pairs
struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* current = head;
    struct Node* newHead = head->next; // The second node will become the new head

    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next->next;  // Store the node after the next one
        current->next->next = current;            // Point next node to the current node
        if (temp == NULL || temp->next == NULL) { // If next pair doesn't exist
            current->next = temp;
            break;
        }
        current->next = temp->next; // Point current node's next to the next pair's second node
        current = temp;             // Move to the next pair
    }

    return newHead;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data;

    // Taking user input for linked list elements
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Original linked list:\n");
    printList(head);

    // Swap nodes in pairs
    head = swapPairs(head);

    printf("Linked list after swapping nodes in pairs:\n");
    printList(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

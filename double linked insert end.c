/*12. Implement the following operations on doubly linked lists:
a. Insert (end)
b. concatenate two lists
c. display*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to concatenate two doubly linked lists
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the last node of the first list to the head of the second list
    temp->next = head2;
    head2->prev = temp;

    return head1;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the operations
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at end (List 1)\n");
        printf("2. Insert at end (List 2)\n");
        printf("3. Concatenate lists\n");
        printf("4. Display List 1\n");
        printf("5. Display List 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end of List 1: ");
                scanf("%d", &data);
                insertAtEnd(&head1, data);
                break;
            case 2:
                printf("Enter data to insert at end of List 2: ");
                scanf("%d", &data);
                insertAtEnd(&head2, data);
                break;
            case 3:
                head1 = concatenateLists(head1, head2);
                head2 = NULL; // Clear List 2 after concatenation
                printf("Lists concatenated.\n");
                break;
            case 4:
                printf("List 1: ");
                displayList(head1);
                break;
            case 5:
                printf("List 2: ");
                displayList(head2);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

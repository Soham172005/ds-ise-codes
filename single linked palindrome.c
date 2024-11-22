/*Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if
its a palindrome or not, respectively. For example
a. List 1 → 2 → 1 is a palindrome.
b. List 1 → 2 → 3 is not a palindrome.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) return 1;

    struct Node *slow = head, *fast = head;

    // Finding the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    slow = reverseList(slow);
    struct Node* second_half = slow;
    struct Node* first_half = head;

    // Compare both halves
    while (second_half != NULL) {
        if (first_half->data != second_half->data) {
            return 0; // Not a palindrome
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return 1; // Is a palindrome
}

// Function to print the linked list (for debugging)
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
    int n, value;

    // Taking input for the linked list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Linked List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

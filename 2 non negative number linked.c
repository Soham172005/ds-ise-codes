// Add 2 non-negative numbers that have been given as a linked list
Given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
operand_1:       7 → 2 → 3 → 3
operand_2:               5 → 7 → 4
result:               7 → 8 → 0 → 7

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

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);  // Reverse the first list
    l2 = reverseList(l2);  // Reverse the second list
    
    ListNode* result = NULL;  // Initialize the result list
    ListNode* temp = NULL;
    int carry = 0;
    
    // Add corresponding digits from both lists
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        // Add the value from l1 if present
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add the value from l2 if present
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Calculate carry for next iteration
        carry = sum / 10;
        
        // Create a new node for the result list
        if (result == NULL) {
            result = createNode(sum % 10);
            temp = result;
        } else {
            temp->next = createNode(sum % 10);
            temp = temp->next;
        }
    }
    
    // Reverse the result list before returning it
    return reverseList(result);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to add a number to the linked list
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
    // Operand 1: 7 → 2 → 3 → 3
    ListNode* operand_1 = addNumberToList(7233); 
    
    // Operand 2: 5 → 7 → 4
    ListNode* operand_2 = addNumberToList(574);
    
    // Add the two numbers
    ListNode* result = addTwoNumbers(operand_1, operand_2);
    
    // Print the result
    printf("Result: ");
    printList(result);
    
    return 0;
}

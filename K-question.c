#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Maximum size of the array

// Structure to represent k queues
typedef struct {
    int arr[MAX_SIZE];   // Array to store elements
    int front[MAX_SIZE]; // Array to store front indices of k queues
    int rear[MAX_SIZE];  // Array to store rear indices of k queues
    int next[MAX_SIZE];  // Array to manage free list
    int free;            // Index of the first free slot
    int k;               // Number of queues
    int n;               // Total capacity of the array
} kQueues;

// Function to initialize k queues
void initKQueues(kQueues *qs, int k, int n) {
    qs->k = k;
    qs->n = n;
    qs->free = 0;

    for (int i = 0; i < k; i++) {
        qs->front[i] = -1; // Front of all queues initially -1
        qs->rear[i] = -1;  // Rear of all queues initially -1
    }

    for (int i = 0; i < n - 1; i++) {
        qs->next[i] = i + 1; // Initialize free list
    }
    qs->next[n - 1] = -1; // Last slot points to -1
}

// Function to check if a queue is empty
bool isEmpty(kQueues *qs, int qn) {
    return qs->front[qn] == -1;
}

// Function to enqueue an element to a specific queue
void enqueue(kQueues *qs, int x, int qn) {
    if (qs->free == -1) {
        printf("Queue overflow\n");
        return;
    }

    int i = qs->free; // Get the first free index
    qs->free = qs->next[i]; // Update the free index

    if (qs->front[qn] == -1) {
        qs->front[qn] = i; // If queue is empty, update front
    } else {
        qs->next[qs->rear[qn]] = i; // Link the new element
    }

    qs->next[i] = -1; // Mark next of new element as -1
    qs->rear[qn] = i; // Update rear of the queue
    qs->arr[i] = x;   // Store the element
}

// Function to dequeue an element from a specific queue
int dequeue(kQueues *qs, int qn) {
    if (isEmpty(qs, qn)) {
        printf("Queue underflow\n");
        return -1;
    }

    int i = qs->front[qn]; // Get the front index of the queue
    qs->front[qn] = qs->next[i]; // Update front to next element

    if (qs->front[qn] == -1) {
        qs->rear[qn] = -1; // If queue is empty, update rear
    }

    qs->next[i] = qs->free; // Add the index to free list
    qs->free = i;

    return qs->arr[i];
}

// Function to display the elements of a specific queue
void displayq(kQueues *qs, int qn) {
    if (isEmpty(qs, qn)) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    int i = qs->front[qn];
    printf("Queue %d: ", qn);
    while (i != -1) {
        printf("%d ", qs->arr[i]);
        i = qs->next[i];
    }
    printf("\n");
}

// Function to display all queues
void displayAll(kQueues *qs) {
    for (int i = 0; i < qs->k; i++) {
        displayq(qs, i);
    }
}

// Main function for testing
int main() {
    int k, n;
    printf("Enter the number of queues: ");
    scanf("%d", &k);
    printf("Enter the total capacity of the array: ");
    scanf("%d", &n);

    kQueues qs;
    initKQueues(&qs, k, n);

    int choice, x, qn;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display a specific queue\n");
        printf("4. Display all queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter the queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(&qs, x, qn);
                break;

            case 2: // Dequeue
                printf("Enter the queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                printf("Dequeued from queue %d: %d\n", qn, dequeue(&qs, qn));
                break;

            case 3: // Display a specific queue
                printf("Enter the queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                displayq(&qs, qn);
                break;

            case 4: // Display all queues
                printf("Contents of all queues:\n");
                displayAll(&qs);
                break;

            case 5: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


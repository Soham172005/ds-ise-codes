/*Write a program to implement a Hash Table using quadratic probing as the
collision resolution strategy. The table should support the following operations:
a. Insert
b. Search*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Define the size of the hash table

typedef struct {
    int key;
    int isOccupied;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;  // Mark each slot as empty
    }
}

// Hash function to calculate index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert function with quadratic probing
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    // Quadratic probing to find an empty slot
    while (hashTable[(index + i * i) % TABLE_SIZE].isOccupied) {
        i++;
        if (i == TABLE_SIZE) {  // If we've tried all slots, the table is full
            printf("Hash Table is full, cannot insert key %d\n", key);
            return;
        }
    }

    int insertIndex = (index + i * i) % TABLE_SIZE;
    hashTable[insertIndex].key = key;
    hashTable[insertIndex].isOccupied = 1;  // Mark slot as occupied
    printf("Inserted key %d at index %d\n", key, insertIndex);
}

// Search function with quadratic probing
int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    // Quadratic probing to find the key
    while (hashTable[(index + i * i) % TABLE_SIZE].isOccupied) {
        int searchIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[searchIndex].key == key) {
            return searchIndex;  // Key found
        }
        i++;
        if (i == TABLE_SIZE) {  // If we've tried all slots, key is not in the table
            break;
        }
    }

    return -1;  // Key not found
}

int main() {
    int choice, key, index;
    initializeTable();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = search(key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found in the hash table\n", key);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

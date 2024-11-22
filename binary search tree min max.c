//Construct a Binary search tree and get the minimum and maximum key in the tree.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return createNode(key);

    // Recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the unchanged node pointer
    return node;
}

// Function to find the minimum key in the BST
int findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

// Function to find the maximum key in the BST
int findMax(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->key;
}

// Main function to test the program
int main() {
    struct Node* root = NULL;
    int n, key;

    // Take number of nodes as input
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Take node values as input
    printf("Enter the values for each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Find and display minimum and maximum keys
    if (root != NULL) {
        int min = findMin(root);
        int max = findMax(root);
        printf("Minimum key in the BST: %d\n", min);
        printf("Maximum key in the BST: %d\n", max);
    } else {
        printf("The tree is empty.\n");
    }

    return 0;
}

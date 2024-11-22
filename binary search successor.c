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

// Insert a node in the BST
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

// Find the minimum value node in a given subtree
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Find the successor of a given node in the BST
struct Node* findSuccessor(struct Node* root, struct Node* target) {
    struct Node* successor = NULL;

    while (root != NULL) {
        if (target->key < root->key) {
            successor = root; // Move left and update successor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// Helper function to find a node by key
struct Node* findNode(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
}

// Main function to test the program
int main() {
    struct Node* root = NULL;
    int n, key, targetKey;

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

    // Take the target node key as input
    printf("Enter the key of the node to find its successor: ");
    scanf("%d", &targetKey);

    // Find the target node
    struct Node* targetNode = findNode(root, targetKey);
    if (targetNode == NULL) {
        printf("Node with key %d not found in the BST.\n", targetKey);
        return 1;
    }

    // Find and display the successor
    struct Node* successor = findSuccessor(root, targetNode);
    if (successor != NULL)
        printf("The successor of node with key %d is: %d\n", targetKey, successor->key);
    else
        printf("The node with key %d has no successor in the BST.\n", targetKey);

    return 0;
}

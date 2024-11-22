//construct a binary tree and perform traversals
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

// Recursive function to construct the binary tree
struct Node* constructTree() {
    int key;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &key);

    // Base case: if key is -1, return NULL (no node)
    if (key == -1)
        return NULL;

    // Create a new node with the input key
    struct Node* newNode = createNode(key);

    // Recursively construct the left and right subtrees
    printf("Enter left child of %d:\n", key);
    newNode->left = constructTree();

    printf("Enter right child of %d:\n", key);
    newNode->right = constructTree();

    return newNode;
}

// In-order traversal (Left, Root, Right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// Main function to test the program
int main() {
    struct Node* root = NULL;

    printf("Construct the binary tree:\n");
    root = constructTree();

    // Display traversals
    printf("\nIn-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

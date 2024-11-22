//count the number of leaves
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

    if (key == -1)
        return NULL;

    struct Node* newNode = createNode(key);

    printf("Enter left child of %d:\n", key);
    newNode->left = constructTree();

    printf("Enter right child of %d:\n", key);
    newNode->right = constructTree();

    return newNode;
}

// Recursive function to count the number of leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    // A node is a leaf if it has no children
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count leaf nodes in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// In-order traversal for testing
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function to test the program
int main() {
    struct Node* root = NULL;

    printf("Construct the binary tree:\n");
    root = constructTree();

    // Display in-order traversal
    printf("\nIn-order traversal of the tree: ");
    inOrder(root);
    printf("\n");

    // Count and display the number of leaf nodes
    int leafCount = countLeaves(root);
    printf("Number of leaves in the tree: %d\n", leafCount);

    return 0;
}

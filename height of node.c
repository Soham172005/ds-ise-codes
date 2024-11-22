//height of a node
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

// Recursive function to find the height of a given node
int getHeight(struct Node* root, int key) {
    if (root == NULL)
        return -1;

    if (root->key == key) {
        return height(root);
    }

    int leftHeight = getHeight(root->left, key);
    if (leftHeight != -1)
        return leftHeight;

    return getHeight(root->right, key);
}

// Recursive function to calculate the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return -1;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
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
    int key;

    printf("Construct the binary tree:\n");
    root = constructTree();

    // Display in-order traversal
    printf("\nIn-order traversal of the tree: ");
    inOrder(root);
    printf("\n");

    // Get height of a given node
    printf("Enter the key of the node to find its height: ");
    scanf("%d", &key);

    int nodeHeight = getHeight(root, key);
    if (nodeHeight == -1)
        printf("Node with key %d not found in the tree.\n", key);
    else
        printf("The height of the node with key %d is: %d\n", key, nodeHeight);

    return 0;
}

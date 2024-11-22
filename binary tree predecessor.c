//predecessor binary tree

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(data);

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // return the (unchanged) node pointer
    return root;
}

// Function to find the predecessor of a given node
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    // Case 1: If the node has a left child, find the rightmost node in the left subtree
    if (node->left != NULL) {
        struct Node* temp = node->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    // Case 2: If no left child, go up to the ancestors
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            root = root->left;
        } else if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            break;
        }
    }

    return predecessor;
}

// In-order traversal to print the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST:\n");
    inorder(root);
    printf("\n");

    // Find the predecessor of a node (e.g., node with value 40)
    struct Node* node = root->left->right;  // This is the node with value 40
    struct Node* predecessor = findPredecessor(root, node);

    if (predecessor != NULL)
        printf("Predecessor of %d is %d\n", node->data, predecessor->data);
    else
        printf("No predecessor found for %d\n", node->data);

    return 0;
}

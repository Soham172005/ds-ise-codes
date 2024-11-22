1.	// Construct an AVL tree and excecute left  rotatio on it.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of an AVL Tree Node
typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Function to create a new AVL Node
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to get the height of a node
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// Function to calculate the balance factor of a node
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotation function (used in left rotation scenarios)
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    // Return the new root
    return x;
}

// Left rotation function (used when right child is too tall)
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    // Return the new root
    return y;
}

// Function to insert a new key into the AVL tree and balance it
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    // Update height of this ancestor node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Left heavy (balance > 1)
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right heavy (balance < -1)
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Right-Left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Left-Right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    return node;
}

// Function to print the inorder traversal of the tree
void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to print the tree (for demonstration)
void printTree(AVLNode* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    printTree(root->left, space);
}

int main() {
    AVLNode* root = NULL;

    // Insert elements into the AVL tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);

    printf("Inorder traversal before rotation:\n");
    inorder(root);
    printf("\n");

    // Print the tree structure before the rotation
    printf("\nTree structure before rotation:\n");
    printTree(root, 0);

    // Execute left rotation on the root (example)
    root = leftRotate(root);

    printf("\nInorder traversal after left rotation:\n");
    inorder(root);
    printf("\n");

    // Print the tree structure after the rotation
    printf("\nTree structure after left rotation:\n");
    printTree(root, 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// BST Node Structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to create a new tree node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserts a value into the BST (Ignores duplicates)
Node* insert(Node* root, int value) {
    // If tree/subtree is empty, create a new root node
    if (root == NULL) {
        return createNode(value);
    }

    // Go left if the value is smaller
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    // Go right if the value is larger
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Note: If value == root->data, we simply do nothing (ignores duplicates)

    return root;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Memory Cleanup using Postorder Traversal (Left -> Right -> Root)
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {40, 20, 60, 10, 30, 50, 70};
    int count = sizeof(values) / sizeof(values[0]);

    // Populate the BST
    for (int i = 0; i < count; i++) {
        root = insert(root, values[i]);
    }

    // Output result
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    // Clean up allocated memory
    freeTree(root);

    return 0;
}
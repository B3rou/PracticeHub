#include <stdio.h>
#include <stdlib.h>

// BST Node Structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to create a new node
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

// Inserts a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search function: Returns 1 if value exists in BST, 0 otherwise
int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    
    // Search left if target is smaller, right if larger
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// findMin function: Finds the smallest element in a non-empty BST (leftmost node)
int findMin(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Memory cleanup
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++)
        root = insert(root, numbers[i]);

    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));

    freeTree(root);
    return 0;
}
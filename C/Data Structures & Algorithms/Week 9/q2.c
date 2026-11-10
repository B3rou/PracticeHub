#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* insertAVL(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Case 1: Left Left (LL)
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // Case 2: Right Right (RR)
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // Case 3: Left Right (LR)
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void runTest(const char* testName, int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertAVL(root, arr[i]);
    }

    printf("=== Test %s ===\n", testName);
    printf("Kok: %d\n", root->data);
    printf("Preorder: ");
    preorder(root);
    printf("\n\n");

    freeTree(root);
}

int main() {
    int testA[] = {30, 20, 10};
    int testB[] = {10, 20, 30};
    int testC[] = {30, 10, 20};
    int testD[] = {10, 30, 20};

    runTest("A (LL)", testA, 3);
    runTest("B (RR)", testB, 3);
    runTest("C (LR)", testC, 3);
    runTest("D (RL)", testD, 3);

    return 0;
}
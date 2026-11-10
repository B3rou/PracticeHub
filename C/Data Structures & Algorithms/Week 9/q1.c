#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* n) {
    if (n == NULL) return 0;
    int leftH = height(n->left);
    int rightH = height(n->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int balanceFactor(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* insertBST(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data) {
        node->left = insertBST(node->left, data);
    } else if (data > node->data) {
        node->right = insertBST(node->right, data);
    }
    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

int main() {
    Node* root = NULL;
    int inputSequence[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        root = insertBST(root, inputSequence[i]);
        printf("%d eklendi. BF(kok) = %d\n", inputSequence[i], balanceFactor(root));
    }

    int bf = balanceFactor(root);
    if (bf < -1) {
        printf("RR dengesizligi: Sol rotasyon!\n");
        root = rotateLeft(root);
    }

    printf("Kok: %d\n", root->data);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
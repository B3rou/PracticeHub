#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

// Calculates max node depth (levels)
int getNodeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftH = getNodeHeight(root->left);
    int rightH = getNodeHeight(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

// Recursive search tracking visited nodes step-by-step
int searchTreasure(Node* root, int target, int step) {
    if (root == NULL) {
        return 0;
    }

    // Log step-by-step traversal
    printf("Adim %d: [%d] dugumu ziyaret edildi.\n", step, root->data);

    if (root->data == target) {
        return 1;
    }

    if (target < root->data) {
        return searchTreasure(root->left, target, step + 1);
    } else {
        return searchTreasure(root->right, target, step + 1);
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
    int treasureValues[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(treasureValues) / sizeof(treasureValues[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, treasureValues[i]);
    }

    int nodeHeight = getNodeHeight(root);
    int edgeHeight = (nodeHeight > 0) ? nodeHeight - 1 : 0;

    printf("=========================================\n");
    printf("        HAZINE AGACI OYUNU              \n");
    printf("=========================================\n");
    printf("Agac Yuksekligi (Dugum Sayisi / Maks Adim): %d\n", nodeHeight);
    printf("Agac Yuksekligi (Kenar Sayisi): %d\n", edgeHeight);
    printf("En kotu durumda hazineyi bulmak icin maks %d adim gerekir.\n", nodeHeight);
    printf("=========================================\n\n");

    int target;
    char choice;

    do {
        printf("Kazamiz icin bir sayi giriniz: ");
        if (scanf("%d", &target) != 1) break;

        printf("\n--- Kazi Baslatiliyor ---\n");
        int found = searchTreasure(root, target, 1);

        printf("\n--- Sonuc ---\n");
        if (found) {
            printf(">> Hazine bulundu! <<\n");
        } else {
            printf(">> Bosuna kazdin! <<\n");
        }

        printf("\nTekrar kazmak ister misiniz? (e/h): ");
        scanf(" %c", &choice);
        printf("\n");

    } while (choice == 'e' || choice == 'E');

    printf("Oyun bitti. Agac bellegi temizleniyor...\n");
    freeTree(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(1);
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    // Insert at the head if list is empty or new value is smaller than head
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // Traverse to find the correct insertion point
    Node *current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(Node** head, int value) {
    if (*head == NULL) return;
    
    // If head holds the value to be removed
    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    // If value was found
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int count(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;
    
    // Test values from the assignment
    int values[] = {23, 11, 5, 9, 6, 4, 12, 24};
    for (int i = 0; i < 8; i++) {
        addOrdered(&head, values[i]);
    }
    
    printf("Sirali Liste: ");
    printList(head);
    
    printf("Dugum sayisi: %d\n", count(head));
    
    removeNode(&head, 9);
    printf("9 silindikten sonra: ");
    printList(head);
    
    clear(&head);
    printf("Temizlendikten sonra dugum sayisi: %d\n", count(head));
    
    return 0;
}
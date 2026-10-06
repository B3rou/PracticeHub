#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int number;
    char name[50];
    struct Node *next;
    struct Node *prev;
} Node;

void insertOrdered(Node** head, Node** tail, int number, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(1);
    }
    
    newNode->number = number;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;

    // Case 1: Empty list
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // Case 2: Insert at the beginning (before current head)
    if ((*head)->number >= number) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Traverse to find the correct insertion point
    Node* current = *head;
    while (current->next != NULL && current->next->number < number) {
        current = current->next;
    }

    // Case 3: Insert at the end
    if (current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
        *tail = newNode; // Update the tail pointer
    } 
    // Case 4: Insert in the middle
    else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void displayForward(Node* head) {
    Node* current = head;
    printf("Bastan Sona Liste:\n");
    while (current != NULL) {
        printf("[No: %d, Isim: %s] ", current->number, current->name);
        if (current->next != NULL) printf("<-> ");
        current = current->next;
    }
    printf("\n\n");
}

void displayBackward(Node* tail) {
    Node* current = tail;
    printf("Sondan Basa Liste:\n");
    while (current != NULL) {
        printf("[No: %d, Isim: %s] ", current->number, current->name);
        if (current->prev != NULL) printf("<-> ");
        current = current->prev;
    }
    printf("\n\n");
}

// Good practice: Always clean up memory
void clearList(Node** head, Node** tail) {
    Node* current = *head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    *tail = NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting students out of order to test the sorting
    insertOrdered(&head, &tail, 105, "Ali");
    insertOrdered(&head, &tail, 102, "Veli");
    insertOrdered(&head, &tail, 108, "Ayse");
    insertOrdered(&head, &tail, 101, "Fatma");

    displayForward(head);
    displayBackward(tail);

    clearList(&head, &tail);
    return 0;
}
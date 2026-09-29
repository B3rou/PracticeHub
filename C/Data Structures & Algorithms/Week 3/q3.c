#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Basic append function just to populate the list for testing
void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    // Fast moves 2 steps, slow moves 1 step. 
    // When fast reaches the end, slow is in the middle.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
    
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    
    printf("Tek sayida elemanli liste: ");
    printList(head);
    
    Node* mid = findMiddle(head);
    if (mid != NULL) printf("Ortadaki eleman: %d\n\n", mid->data);
    
    // Add one more to make it even
    append(&head, 60);
    printf("Cift sayida elemanli liste: ");
    printList(head);
    
    mid = findMiddle(head);
    if (mid != NULL) printf("Ortadaki eleman (ikincisi): %d\n", mid->data);
    
    clear(&head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    newNode->data = value;
    
    // If position is <= 0 or list is empty, insert at head
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    int currentIndex = 0;
    
    // Traverse until we hit the position - 1, or the end of the list
    while (current->next != NULL && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }
    
    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAt(Node** head, int position) {
    if (*head == NULL || position < 0) return;
    
    // If position is 0, delete the head
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    Node* current = *head;
    int currentIndex = 0;
    
    // Find the node just before the one we want to delete
    while (current->next != NULL && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }
    
    // If the next node is NULL, the position was invalid
    if (current->next == NULL) return;
    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
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
    
    insertAt(&head, 10, 0);  // Insert at 0
    insertAt(&head, 30, 5);  // Insert out of bounds (goes to end)
    insertAt(&head, 20, 1);  // Insert at index 1
    insertAt(&head, 5, -3);  // Negative index (goes to head)
    
    printf("Liste: ");
    printList(head); // Should be 5 -> 10 -> 20 -> 30 -> NULL
    
    deleteAt(&head, 2); // Deletes 20
    printf("2. indisteki dugum silindi: ");
    printList(head); 
    
    clear(&head);
    return 0;
}
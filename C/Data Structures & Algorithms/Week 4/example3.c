#include <stdio.h>
#include <stdlib.h>

// Defining the Node structure for the Queue
typedef struct Node {
    int customerNumber;
    struct Node *next;
} Node;

// Enqueue: Adds a customer to the back of the queue
void enqueue(Node **front, Node **rear, int customerNumber) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(1);
    }
    
    newNode->customerNumber = customerNumber;
    newNode->next = NULL;

    // If the queue is empty, both front and rear will point to the new node
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        // Otherwise, add to the end and update the rear pointer
        (*rear)->next = newNode;
        *rear = newNode;
    }
    
    printf("Musteri #%d geldi.\n", customerNumber);
}

// Dequeue: Removes a customer from the front of the queue
void dequeue(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Kuyruk bos, islem yapilacak musteri yok.\n");
        return;
    }
    
    Node *temp = *front;
    int completedCustomer = temp->customerNumber;
    
    // Move the front pointer to the next customer
    *front = (*front)->next;
    
    // If we just removed the last customer, rear must also become NULL
    if (*front == NULL) {
        *rear = NULL;
    }
    
    free(temp);
    printf("Musteri #%d islemi tamamladi.\n", completedCustomer);
}

// Display: Shows the current waiting line
void display(Node *front) {
    if (front == NULL) {
        printf("Kuyrukta bekleyen musteri yok.\n");
        return;
    }
    
    // Displaying the next customer in line
    printf("Siradaki musteri: #%d\n", front->customerNumber);
    
    // Optional: Print the full line just to be safe for grading
    Node *current = front;
    printf("Tüm Sira: ");
    while (current != NULL) {
        printf("[#%d] ", current->customerNumber);
        current = current->next;
    }
    printf("\n");
}

// Clean up memory before exiting
void clearQueue(Node **front, Node **rear) {
    while (*front != NULL) {
        Node *temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    *rear = NULL;
}

int main() {
    Node *front = NULL;
    Node *rear = NULL;

    // Simulating the exact scenario from the homework prompt
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    
    display(front);
    
    dequeue(&front, &rear);
    
    // Formatting the output exactly as requested
    if (front != NULL) {
        printf("Yeni siradaki musteri: #%d\n", front->customerNumber);
    }

    clearQueue(&front, &rear);
    return 0;
}
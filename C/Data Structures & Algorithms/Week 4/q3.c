#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

// Wrapping front and rear in a single struct
typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName) {
    PrintJob* newJob = (PrintJob*)malloc(sizeof(PrintJob));
    if (newJob == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    
    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    // If the queue is empty
    if (q->rear == NULL) {
        q->front = newJob;
        q->rear = newJob;
    } else {
        // Add to the end of the queue
        q->rear->next = newJob;
        q->rear = newJob;
    }
    
    printf("Kuyruga eklendi: %s\n", fileName);
}

void processNextJob(Queue* q) {
    // Check if the queue is empty
    if (q->front == NULL) {
        printf("Kuyruk bos, yazdirilacak is yok.\n");
        return;
    }
    
    PrintJob* temp = q->front;
    printf("Yazdiriliyor: %s\n", temp->fileName);
    
    // Move front pointer forward
    q->front = q->front->next;
    
    // If the queue becomes empty after dequeuing, update rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
}

// Passed by value as requested in the skeleton, so it doesn't modify the original pointers
void showQueue(Queue q) {
    if (q.front == NULL) {
        printf("Yazici kuyrugu bos.\n");
        return;
    }
    
    PrintJob* current = q.front;
    int position = 1;
    
    printf("\n--- Yazici Kuyrugu ---\n");
    while (current != NULL) {
        printf("%d. %s\n", position++, current->fileName);
        current = current->next;
    }
    printf("----------------------\n");
}

void clearQueue(Queue* q) {
    while (q->front != NULL) {
        PrintJob* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

int main() {
    Queue q = {NULL, NULL}; // Initialize empty queue
    int choice;
    char fileName[50];

    printf("--- Yazici Yonetim Sistemi ---\n");

    while (1) {
        printf("\n1. Yeni dosya ekle\n2. Yazdir\n3. Kuyrugu goster\n4. Cikis\nSeciminiz: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Dosya adi: ");
                scanf(" %49s", fileName);
                enqueuePrintJob(&q, fileName);
                break;
            case 2:
                processNextJob(&q);
                break;
            case 3:
                showQueue(q);
                break;
            case 4:
                clearQueue(&q);
                printf("Yazici kapaniyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }

    return 0;
}
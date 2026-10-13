#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Universal Node structure for Queue, Stack, and Linked List
typedef struct Patient {
    int id;
    char name[50];
    char status[20];
    struct Patient* next;
} Patient;

// Queue Structure (FIFO) for waiting room
typedef struct Queue {
    Patient* front;
    Patient* rear;
} Queue;

// ================= QUEUE OPERATIONS (Waiting Room) =================

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int id, const char* name) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    
    newPatient->id = id;
    strcpy(newPatient->name, name);
    strcpy(newPatient->status, "bekliyor");
    newPatient->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newPatient;
    } else {
        q->rear->next = newPatient;
        q->rear = newPatient;
    }
}

// Removes from queue and returns the node so it can be passed to the stack
Patient* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    
    Patient* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    temp->next = NULL; // Isolate the node
    return temp;
}

// ================= STACK OPERATIONS (Examination Room) =================

// Pushes a patient node onto the stack
void push(Patient** top, Patient* p) {
    if (p == NULL) return;
    
    strcpy(p->status, "muayenede");
    p->next = *top;
    *top = p;
}

// Pops a patient node from the stack and returns it
Patient* pop(Patient** top) {
    if (*top == NULL) return NULL;
    
    Patient* temp = *top;
    *top = (*top)->next;
    temp->next = NULL; // Isolate the node
    
    return temp;
}

// ================= LINKED LIST OPERATIONS (History) =================

// Appends a finished patient to the history list
void addToHistory(Patient** hHead, Patient** hTail, Patient* p) {
    if (p == NULL) return;
    
    strcpy(p->status, "tamamlandi");
    p->next = NULL;
    
    if (*hHead == NULL) {
        *hHead = *hTail = p;
    } else {
        (*hTail)->next = p;
        *hTail = p;
    }
}

// ================= DISPLAY FUNCTIONS =================

void displayQueue(Queue* q) {
    printf("--- Bekleyen Hastalar ---\n");
    if (q->front == NULL) {
        printf("Hasta yok.\n");
        return;
    }
    Patient* current = q->front;
    while (current != NULL) {
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n", current->id, current->name, current->status);
        current = current->next;
    }
}

void displayStack(Patient* top) {
    printf("--- Muayene Odasindaki Hastalar ---\n");
    if (top == NULL) {
        printf("Hasta yok.\n");
        return;
    }
    Patient* current = top;
    while (current != NULL) {
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n", current->id, current->name, current->status);
        current = current->next;
    }
}

void displayHistory(Patient* head) {
    printf("--- Tamamlanan Hastalar ---\n");
    if (head == NULL) {
        printf("Hasta yok.\n");
        return;
    }
    Patient* current = head;
    while (current != NULL) {
        printf("Hasta ID: %d, Isim: %s, Durum: %s\n", current->id, current->name, current->status);
        current = current->next;
    }
}

void displayAll(Queue* q, Patient* top, Patient* hHead) {
    displayQueue(q);
    displayStack(top);
    displayHistory(hHead);
    printf("\n");
}

// ================= MAIN FUNCTION =================

int main() {
    // 1. Initialize data structures
    Queue waitingRoom;
    initQueue(&waitingRoom);
    
    Patient* examinationRoomTop = NULL; // Stack
    Patient* historyHead = NULL;        // Linked List Head
    Patient* historyTail = NULL;        // Linked List Tail for O(1) appending

    // 2. Register Patients
    enqueue(&waitingRoom, 1, "Ahmet");
    enqueue(&waitingRoom, 2, "Mehmet");
    enqueue(&waitingRoom, 3, "Ayse");

    printf("=== Baslangic Durumu ===\n");
    displayAll(&waitingRoom, examinationRoomTop, historyHead);

    // 3. Process Ahmet
    // Dequeue from waiting room -> push to examination room
    push(&examinationRoomTop, dequeue(&waitingRoom));
    
    // Pop from examination room -> add to history
    addToHistory(&historyHead, &historyTail, pop(&examinationRoomTop));

    // 4. Process Mehmet
    push(&examinationRoomTop, dequeue(&waitingRoom));
    addToHistory(&historyHead, &historyTail, pop(&examinationRoomTop));
    
    // 5. Ayse stays in the queue

    // 6. Final State Print
    printf("=== Tum Islemler Sonrasi ===\n");
    displayAll(&waitingRoom, examinationRoomTop, historyHead);

    return 0;
}
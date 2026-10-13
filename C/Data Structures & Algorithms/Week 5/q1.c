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

Patient* dequeue(Queue* q) {
    // Requirement: Empty checks during removal operations
    if (q->front == NULL) {
        printf("Uyari: Kuyruk bos, cikarilacak hasta yok.\n");
        return NULL;
    }
    
    Patient* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    temp->next = NULL; // Isolate the node completely
    return temp;
}

// ================= STACK OPERATIONS (Examination Room) =================

void push(Patient** top, Patient* p) {
    if (p == NULL) return;
    
    strcpy(p->status, "muayenede");
    p->next = *top;
    *top = p;
}

Patient* pop(Patient** top) {
    // Requirement: Empty checks during removal operations
    if (*top == NULL) {
        printf("Uyari: Yigin bos, cikarilacak hasta yok.\n");
        return NULL;
    }
    
    Patient* temp = *top;
    *top = (*top)->next;
    temp->next = NULL; // Isolate the node completely
    
    return temp;
}

// ================= LINKED LIST OPERATIONS (History) =================

void addToHistory(Patient** hHead, Patient** hTail, Patient* p) {
    if (p == NULL) return;
    
    strcpy(p->status, "tamamlandi");
    p->next = NULL;
    
    // Append to the end of the history list
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
}

// ================= MEMORY CLEANUP =================
void freeAll(Queue* q, Patient** top, Patient** hHead) {
    Patient* current;
    
    // Clean queue silently
    while (q->front != NULL) {
        current = dequeue(q);
        free(current);
    }
    // Clean stack silently
    while (*top != NULL) {
        current = pop(top);
        free(current);
    }
    // Clean history
    while (*hHead != NULL) {
        current = *hHead;
        *hHead = (*hHead)->next;
        free(current);
    }
}

// ================= MAIN FUNCTION =================

int main() {
    // 1. Initialize data structures
    Queue waitingRoom;
    initQueue(&waitingRoom);
    
    Patient* examinationRoomTop = NULL; 
    Patient* historyHead = NULL;        
    Patient* historyTail = NULL;        
    Patient* currentPatient = NULL;

    // 2. Register Patients
    enqueue(&waitingRoom, 1, "Ahmet");
    enqueue(&waitingRoom, 2, "Mehmet");
    enqueue(&waitingRoom, 3, "Ayse");

    printf("\n=== Baslangic Durumu ===\n");
    displayAll(&waitingRoom, examinationRoomTop, historyHead);

    printf("\n=== Hasta Aktarim Islemleri ===\n");
    
    // 3. Process Ahmet
    currentPatient = dequeue(&waitingRoom);
    if (currentPatient != NULL) {
        push(&examinationRoomTop, currentPatient);
        printf("> Ahmet muayeneye alindi (Durum: %s)\n", examinationRoomTop->status);
        
        // Visual proof that the patient is in the stack
        displayStack(examinationRoomTop);
        
        currentPatient = pop(&examinationRoomTop);
        addToHistory(&historyHead, &historyTail, currentPatient);
        printf("> Ahmet'in muayenesi bitti, gecmise eklendi.\n\n");
    }

    // 4. Process Mehmet
    currentPatient = dequeue(&waitingRoom);
    if (currentPatient != NULL) {
        push(&examinationRoomTop, currentPatient);
        printf("> Mehmet muayeneye alindi (Durum: %s)\n", examinationRoomTop->status);
        
        // Visual proof that the patient is in the stack
        displayStack(examinationRoomTop);
        
        currentPatient = pop(&examinationRoomTop);
        addToHistory(&historyHead, &historyTail, currentPatient);
        printf("> Mehmet'in muayenesi bitti, gecmise eklendi.\n\n");
    }
    
    // 5. Ayse stays in the queue
    printf("> Ayse bekleme kuyrugunda birakildi.\n\n");

    // 6. Final State Print (Matching exactly the requested output)
    printf("=== Tum Islemler Sonrasi ===\n");
    displayAll(&waitingRoom, examinationRoomTop, historyHead);

    // 7. Prevent Memory Leaks
    freeAll(&waitingRoom, &examinationRoomTop, &historyHead);

    return 0;
}
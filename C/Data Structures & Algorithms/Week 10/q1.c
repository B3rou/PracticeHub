#include <stdio.h>
#include <stdlib.h>

#define NUM_CITIES 5

// City labels and names mapped to indices 0..4
const char* CITY_CODES[NUM_CITIES] = {"A", "B", "C", "D", "E"};
const char* CITY_NAMES[NUM_CITIES] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};

// Adjacency List Node
typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

// Graph Structure
typedef struct Graph {
    int numVertices;
    AdjNode** adjLists;
} Graph;

// Dynamic Queue Node for BFS
typedef struct QueueNode {
    int vertex;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// ================= QUEUE OPERATIONS (For BFS) =================

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) exit(1);
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int vertex) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) exit(1);
    newNode->vertex = vertex;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    QueueNode* temp = q->front;
    int vertex = temp->vertex;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return vertex;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// ================= GRAPH OPERATIONS =================

AdjNode* createAdjNode(int v) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    if (!newNode) exit(1);
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) exit(1);
    graph->numVertices = vertices;
    graph->adjLists = (AdjNode**)malloc(vertices * sizeof(AdjNode*));
    if (!graph->adjLists) exit(1);

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Inserts neighbor in ascending index order for deterministic traversal
void addSortedNeighbor(AdjNode** head, int dest) {
    AdjNode* newNode = createAdjNode(dest);
    if (*head == NULL || (*head)->vertex > dest) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    AdjNode* current = *head;
    while (current->next != NULL && current->next->vertex < dest) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Adds an undirected edge between src and dest
void addEdge(Graph* graph, int src, int dest) {
    addSortedNeighbor(&graph->adjLists[src], dest);
    addSortedNeighbor(&graph->adjLists[dest], src);
}

void printGraph(Graph* graph) {
    printf("=== Sehir Grafi (Komsuluk Listesi) ===\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s (%s) -> ", CITY_CODES[i], CITY_NAMES[i]);
        AdjNode* temp = graph->adjLists[i];
        while (temp) {
            printf("%s (%s)", CITY_CODES[temp->vertex], CITY_NAMES[temp->vertex]);
            if (temp->next) printf(", ");
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

// ================= BFS & DFS ALGORITHMS =================

void BFS(Graph* graph, int startVertex) {
    int visited[NUM_CITIES] = {0};
    Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Dolasimi: ");
    int first = 1;

    while (!isQueueEmpty(q)) {
        int curr = dequeue(q);
        if (!first) printf(" -> ");
        printf("%s (%s)", CITY_CODES[curr], CITY_NAMES[curr]);
        first = 0;

        AdjNode* temp = graph->adjLists[curr];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(q);
}

void DFSUtil(Graph* graph, int vertex, int visited[], int* first) {
    visited[vertex] = 1;
    if (!(*first)) printf(" -> ");
    printf("%s (%s)", CITY_CODES[vertex], CITY_NAMES[vertex]);
    *first = 0;

    AdjNode* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited, first);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    int visited[NUM_CITIES] = {0};
    int first = 1;
    printf("DFS Dolasimi: ");
    DFSUtil(graph, startVertex, visited, &first);
    printf("\n");
}

// ================= MEMORY CLEANUP =================

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjNode* current = graph->adjLists[i];
        while (current != NULL) {
            AdjNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    // 0: Istanbul (A), 1: Ankara (B), 2: Izmir (C), 3: Bursa (D), 4: Antalya (E)
    Graph* cityGraph = createGraph(NUM_CITIES);

    addEdge(cityGraph, 0, 1); // Istanbul - Ankara
    addEdge(cityGraph, 0, 3); // Istanbul - Bursa
    addEdge(cityGraph, 1, 2); // Ankara - Izmir
    addEdge(cityGraph, 1, 4); // Ankara - Antalya
    addEdge(cityGraph, 3, 4); // Bursa - Antalya

    printGraph(cityGraph);

    // Traverse starting from A (Istanbul - index 0)
    BFS(cityGraph, 0);
    DFS(cityGraph, 0);

    freeGraph(cityGraph);
    return 0;
}
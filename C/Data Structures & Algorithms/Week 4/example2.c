#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the Node structure for the linked list
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Check if the stack is empty (returns 1 if empty, 0 otherwise)
int isEmpty(Node *top) {
    return top == NULL ? 1 : 0;
}

// Push an element onto the stack (insert at the head)
void push(Node **top, char value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop an element from the stack (remove from the head)
char pop(Node **top) {
    if (isEmpty(*top)) {
        return '\0';
    }
    Node *temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    
    return poppedValue;
}

// Utility function to check if the pairs match
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Main logic to check balanced parentheses
int areParenthesesBalanced(char exp[]) {
    Node *stack = NULL; // Initialize an empty linked list (Stack)

    for (int i = 0; i < strlen(exp); i++) {
        // Push opening brackets to the stack
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&stack, exp[i]);
        }
        // When encountering a closing bracket
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // If stack is empty, there is a closing bracket without an opening one
            if (isEmpty(stack)) {
                return 0; // False
            }
            
            // Pop the top element and check if it matches the current closing bracket
            char topChar = pop(&stack);
            if (!isMatchingPair(topChar, exp[i])) {
                // Free any remaining nodes in the stack to prevent memory leaks before exiting
                while (!isEmpty(stack)) pop(&stack);
                return 0; // False
            }
        }
    }

    // If the stack is completely empty at the end, the string is balanced
    int result = isEmpty(stack);
    
    // Clean up memory just in case (e.g., if there are left over open brackets like "((()")
    while (!isEmpty(stack)) {
        pop(&stack);
    }
    
    return result;
}

int main() {
    char exp[100];
    
    printf("Bir ifade giriniz: ");
    scanf("%s", exp);

    printf("Ifade: %s\n", exp);

    if (areParenthesesBalanced(exp)) {
        printf("Sonuc: Parantezler dengede!\n");
    } else {
        printf("Sonuc: Parantezler dengede degil!\n");
    }

    return 0;
}
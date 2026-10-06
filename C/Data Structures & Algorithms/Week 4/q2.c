#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

void pushWord(Word** top, char* text) {
    Word* newWord = (Word*)malloc(sizeof(Word));
    if (newWord == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    strcpy(newWord->text, text);
    
    // Push to the top of the stack
    newWord->next = *top;
    *top = newWord;
    
    printf("Eklendi: %s\n", text);
}

void popWord(Word** top) {
    if (*top == NULL) {
        printf("Geri alinacak kelime yok (Stack bos).\n");
        return;
    }
    
    Word* temp = *top;
    char poppedText[50];
    strcpy(poppedText, temp->text);
    
    // Move top pointer down and free the old top
    *top = (*top)->next;
    free(temp);
    
    printf("Geri alindi (Undo): %s\n", poppedText);
}

// Helper function to print the stack from bottom to top using recursion
void printReverse(Word* node) {
    if (node == NULL) return;
    
    // Recursive call goes all the way to the bottom node first
    printReverse(node->next);
    
    // Prints as the recursion unwinds back to the top
    printf("%s ", node->text);
}

void showWords(Word* top) {
    if (top == NULL) {
        printf("Metin belgesi bos.\n");
        return;
    }
    
    printf("Guncel Metin: ");
    printReverse(top);
    printf("\n");
}

void clearStack(Word** top) {
    while (*top != NULL) {
        Word* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    Word* top = NULL;
    int choice;
    char inputWord[50];

    printf("--- Basit Metin Editoru (Undo Simulasoynu) ---\n");

    while (1) {
        printf("\n1. Kelime Ekle (add)\n2. Geri Al (undo)\n3. Metni Goster (show)\n4. Cikis\nSeciminiz: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Eklenecek kelime: ");
                scanf(" %49s", inputWord); // Prevents buffer overflow
                pushWord(&top, inputWord);
                break;
            case 2:
                popWord(&top);
                break;
            case 3:
                showWords(top);
                break;
            case 4:
                clearStack(&top);
                printf("Editor kapatiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }

    return 0;
}
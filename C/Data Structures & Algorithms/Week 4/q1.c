#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

void addSongToEnd(Song** head, char* name) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (newSong == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;

    // Case 1: Empty playlist
    if (*head == NULL) {
        *head = newSong;
        printf("'%s' listeye eklendi.\n", name);
        return;
    }

    // Case 2: Traverse to the end
    Song* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newSong;
    newSong->prev = temp;
    printf("'%s' listeye eklendi.\n", name);
}

void removeSong(Song** head, char* name) {
    if (*head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    Song* temp = *head;
    
    // Search for the song
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }
    
    // If we reached the end without finding it
    if (temp == NULL) {
        printf("'%s' adli sarki bulunamadi.\n", name);
        return;
    }
    
    // If the song to delete is the head
    if (temp == *head) {
        *head = temp->next;
    }
    
    // Update the previous node's next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    // Update the next node's prev pointer
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    printf("'%s' listeden silindi.\n", name);
}

void playNext(Song** current) {
    if (*current == NULL) {
        printf("Liste bos veya sarki secilmedi.\n");
        return;
    }
    
    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Su an caliyor (Ileri): %s\n", (*current)->name);
    } else {
        printf("Listenin sonundasiniz. Siradaki sarki yok.\n");
    }
}

void playPrevious(Song** current) {
    if (*current == NULL) {
        printf("Liste bos veya sarki secilmedi.\n");
        return;
    }
    
    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Su an caliyor (Geri): %s\n", (*current)->name);
    } else {
        printf("Listenin basindasiniz. Onceki sarki yok.\n");
    }
}

void displayPlaylist(Song* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    Song* temp = head;
    printf("\n--- Calma Listesi ---\n");
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
    printf("---------------------\n");
}

void clearMemory(Song** head) {
    Song* current = *head;
    while (current != NULL) {
        Song* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    Song* head = NULL;
    Song* currentSong = NULL;
    int choice;
    char name[50];

    while (1) {
        printf("\n1. Sarki Ekle\n2. Sarki Sil\n3. Sonraki Sarkiyi Cal\n4. Onceki Sarkiyi Cal\n5. Listeyi Goster\n6. Cikis\nSeciminiz: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Sarki adi: ");
                scanf(" %[^\n]", name); // Reads string with spaces
                addSongToEnd(&head, name);
                // If this is the first song, set it as currently playing
                if (currentSong == NULL) currentSong = head;
                break;
            case 2:
                printf("Silinecek sarki adi: ");
                scanf(" %[^\n]", name);
                
                // Edge Case Defense: If we are deleting the song currently playing
                if (currentSong != NULL && strcmp(currentSong->name, name) == 0) {
                    if (currentSong->next != NULL) currentSong = currentSong->next;
                    else if (currentSong->prev != NULL) currentSong = currentSong->prev;
                    else currentSong = NULL;
                }
                
                removeSong(&head, name);
                break;
            case 3:
                playNext(&currentSong);
                break;
            case 4:
                playPrevious(&currentSong);
                break;
            case 5:
                displayPlaylist(head);
                if (currentSong != NULL) {
                    printf("Su an caliyor: %s\n", currentSong->name);
                }
                break;
            case 6:
                clearMemory(&head);
                printf("Cikis yapiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
#include <stdio.h>

int myStrlen(char* str);

int main() {
    
    char string[100];
    scanf("%s", string);
    printf("%d", myStrlen(string));
    
}

int myStrlen(char* str) {
    
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        continue;
    }
    return i;
}
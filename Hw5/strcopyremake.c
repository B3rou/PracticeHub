#include <stdio.h>

void myStrcopy(char* src, char* dest);

int main() {
    
    char src[100];
    char dest[100];
    scanf("%s", src);
    myStrcopy(dest, src);
    printf("%s", dest);
    
}

void myStrcopy(char* dest, char* src) {
    
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
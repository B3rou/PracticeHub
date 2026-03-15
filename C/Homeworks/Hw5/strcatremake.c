#include <stdio.h>

void myStrcat(char* src, char* dest);

int main() {
    
    int i;
    char src[100];
    char dest[100];
    fgets(src, 100, stdin);
    i = 0;
    while (src[i] != '\0')
    {
        if (src[i] == '\n')
        {
            src[i] = '\0';
            break;
        }
        i++;
    }
    fgets(dest, 100, stdin);
    i = 0;
    while (dest[i] != '\0')
    {
        if (dest[i] == '\n')
        {
            dest[i] = '\0';
            break;
        }
        i++;
    }
    myStrcat(dest, src);
    printf("%s", src);
    
}

void myStrcat(char* dest, char* src) {
    
    int i, j;
    for (i = 0; src[i] != '\0'; i++)
    {
        continue;
    }
    for (i, j = 0; dest[j] != '\0'; i++, j++)
    {
        src[i] = dest[j];
    }
    src[i] = '\0'; 
}
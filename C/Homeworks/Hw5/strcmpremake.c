#include <stdio.h>

int myStrcmp(char *s1, char *s2);   

int main(void) {

    char str1[100];
    char str2[100];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    int result = myStrcmp(str1, str2);
    if (result < 0) {
        printf("First string is less than second string.\n");
    } else if (result > 0) {
        printf("First string is greater than second string.\n");
    } else {
        printf("Both strings are equal.\n");
    }
    getchar();
    getchar();
    return 0; 

}

int myStrcmp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
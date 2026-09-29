#include <stdio.h>

int main() {
    int num, originalNum, remainder, reversed = 0;

    printf("Bir tam sayi giriniz: ");
    scanf("%d", &originalNum);

    num = originalNum;

    while (num != 0) {
        remainder = num % 10;
        reversed = (reversed * 10) + remainder;
        num = num / 10;
    }

    if (originalNum == reversed) {
        printf("%d bir Palindrom Sayidir.\n", originalNum);
    } else {
        printf("%d bir Palindrom Sayi degildir.\n", originalNum);
    }

    return 0;
}
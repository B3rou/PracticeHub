#include <stdio.h>

unsigned long long binaryConvert(unsigned long long x) {

    if (x == 0)
        return x;
    if (x == 1)
        return x;
    return (binaryConvert(x / 2)*10 + x % 2);
}

int main(void) {
    unsigned long long x;
    printf("Please enter the integer you want to convert to binary: ");
    scanf("%llu", &x);
    printf("%llu is %llu as binary", x, binaryConvert(x));
    getchar();
    getchar();
    return 0;
}

/*

        4 0
        2 0
        1 1

        1 0 0

*/
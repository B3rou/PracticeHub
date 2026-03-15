#include <stdio.h>

int digitSum(int x) {
    if (x == 0)
        return x;
    return ((x % 10) + digitSum(x/10));
}

int main(void) {
    int x;
    printf("Please enter the number: ");
    scanf("%d", &x);
    printf("The sum of the digits of %d is %d", x, digitSum(x));
    getchar();
    getchar();
    return 0;
}
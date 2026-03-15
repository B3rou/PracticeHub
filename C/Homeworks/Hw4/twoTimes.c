#include <stdio.h>

void twoTimes(int *xptr) {

    *xptr *= 2;

}

int main(void) {

    int x;
    int *xptr;
    xptr = &x;
    printf("Please enter the number you want to multiply by 2: ");
    scanf("%d", &x);
    twoTimes(xptr);
    printf("The answer is %d", x);
    getchar();
    getchar();
}
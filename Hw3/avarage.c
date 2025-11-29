#include <stdio.h>

int main(void){

    int x,y,z;
    printf("3 Sayi Giriniz:\n");
    scanf("%d%d%d", &x,&y,&z);

    if (x > y && z > x || (x > z && y > x ))
    printf("Ortanca Sayi: %d", x);
    else if ((y > x && z > y) || (y > z && x > y))
    printf("Ortanca Sayi: %d", y);
    else
    printf("Ortanca Sayi: %d", z);

    getchar();
    getchar();
    return 0;
}

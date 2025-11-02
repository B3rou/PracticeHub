#include <stdio.h>

int x, i, j;
int main(void)
{
    printf("Kaca kadar olsun?");
    scanf("%d", &x);

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= x; j++)
        {
            printf("%dx%d = %d |", j, i, i*j);
        }
        printf("\n");
    }
    getchar();
    getchar();
}
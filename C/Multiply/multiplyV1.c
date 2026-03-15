#include <stdio.h>

int x, i, j;
int main(void)
{
    printf("Kaca kadar olsun?");
    scanf("%d", &x);

    for (i = 1; i <= x; i++)
    {
        for (j = 1; j < 10; j++)
        {
            printf("%dx%d = %d\n", i, j, i*j);
        }
    }
    getchar();
    getchar();
}
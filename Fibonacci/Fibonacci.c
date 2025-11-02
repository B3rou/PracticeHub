#include <stdio.h>
int main(void)
{
    int i, n; // for dongusu icin 1, istenen sayi icin 1
    long long x = 0, y = 1, temp; // hesap icin 3 degisken olusturduk.
    printf("Kac Fibonacci Sayisi Istiyorsunuz?\n");
    scanf("%d", &n); //input aliyoruz

    for (i = 0; i < n; i++)
    {
        if (i == 1) // ozel durumlari hallediyoruz
        {
        printf("%lld ", x);
        }
        else if (i == 1) // ozel durumlari hallediyoruz
        {
        printf("%lld ", y);
        }
        else
        {
        temp = x + y;
        printf("%lld ", temp);
        x = y;
        y = temp;
        }
    }
    printf("\n");
    getchar(); // ilki buffer temizliginde kullanilir
    getchar(); // 2. getchar()'i kullanarak komut isteminin kapanmasini engelliyoruz.
}
#include <stdio.h>

int main(void)
{
    int x,y; //iki integere ihtiyacimiz var
    scanf("%d%d", &x,&y); //input
    printf("x:%d, y:%d", x,y); //check ediyoruz

    getchar();
    getchar(); //okuyabilmek adina cmdyi durduruyoruz

    x = x + y; // x degerimiz artik x + y
    y = x - y; // y degerimiz artik (x + y) - y = x    ** Aslinda burada x - y yapiyoruz. Ama suanda x'in net degil brut bir degeri var. x + y den y cikartiyoruz ve asil x kaliyor.
    x = x - y; // x degerimiz artik (x + y) - x = y    ** Burada da y nin guncel degeri eski x degerimiz (asil x), brut olan x'den eski x degerini cikarinca elimizde y kaliyor.
               // Aslinda kabaca soylemek gerekirse 3 integerlik degerin 2sini tek integerde, digerini tek integerde toplayip tekrar paylastirdik diyebiliriz.
    
    printf("x:%d, y:%d", x,y); //check ediyoruz

    getchar();
    getchar(); //okuyabilmek adina cmdyi durduruyoruz

}
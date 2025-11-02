#include <stdio.h>

int main(void)
{
    int x,y,temp; // 2 integer ve 1 temp'e ihtiyacimiz var
    scanf("%d%d", &x,&y); //input

    printf("x:%d, y:%d", x,y); //check ediyoruz

    getchar(); //buffer temizligi
    getchar(); //okuyabilmek adina cmdyi durduruyoruz
    
    temp = x;
    x = y;
    y = temp;
    
    printf("x:%d, y:%d", x,y); //degiskenlerin degistigini yazdiriyoruz
    
    getchar(); //buffer temizligi
    getchar(); //okuyabilmek adina cmdyi durduruyoruz
}
#include <stdio.h>

int main(void)
{
    int bolunen, bolen; //2 integer gerekli
    printf("Lutfen bolmek istediginiz sayiyi girin:");
    scanf("%d", &bolunen); //input
    printf("Lutfen kaca bolmek istediginizi girin:");
    scanf("%d", &bolen); //input
    
    if (bolen == 0) //bolen 0 olursa program duzgun calismayacaktir
    {
        printf("Hata bolen 0 olmamalidir.");
        getchar();
        getchar();//cmdyi bekletiyoruz ki kullanıcı hatayi okuyabilsin
        return 0; //fonksiyonu durdurduk
    }

    printf("Bolum: %d, Kalan: %d", bolunen/bolen, bolunen%bolen); //sonucu yazdiriyoruz

    getchar(); //buffer temizligi
    getchar(); //cmdyi bekletiyoruz ki kullanıcı sonucu okuyabilsin
}
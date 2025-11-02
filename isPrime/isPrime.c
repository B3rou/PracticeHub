#include <stdio.h>
#include <math.h>
unsigned long long x; // negatif sayilara ihtiyacimiz yok
char devam;
int main(void)
{
	do
	{
		printf("Bir sayi giriniz.\n");
		scanf("%lld", &x); // input aliyoruz
		double karekok = sqrt(x); // secili sayinin karekokune ihtiyacimiz var
		int i;
			for (i = 2; i <= karekok + 1; i++) // secili sayinin karekokune kadar teker teker bolum deneyerek kalan hesabi yapacak, + 1 de ekledik ki kusuratlarda sorun asla cikmasin
			{
				if (x == 1)
				{
					printf("Sayiniz Asal Degildir.\n"); // bu sayiya ozel muamele gerekli
					break;
				}
				if (x == 2)
				{
					printf("Sayiniz Asaldir.\n"); // bu sayiya ozel muamele gerekli
					break;
	 	   		}
				if (x % i == 0) // mod operatoru
				{
					printf("Sayiniz Asal Degildir.\n");
					break;
				}
				else if (i >= karekok)
				{
					printf("Sayiniz Asaldir.\n");
					break;
				}
			}
			printf("Baska sayi denemek ister misiniz? y/n\n");
		do
		{
			scanf("%c", &devam);
		}
		while (devam != 'n' && devam != 'N' && devam != 'y' && devam != 'Y'); // kullanicinin tekrar etmek isteyip istemedigini soruyoruz
	}
	while (devam == 'y' || devam == 'Y'); // tekrar etmek istenirse basa donuyoruz
}


#include <stdio.h>

int height, width; // 2 integere ihtiyacimiz var

int main(void)
{
	printf("Yukseklik Giriniz:");
	scanf("%d", &height); // input aliyoruz
	printf("Genislik Giriniz:");
	scanf("%d", &width);
	int i;
	int j;
	for (i = 0; i < width; i++) //ilk satiri yazdiriyoruz
	{
		if (i == 0)
		{
			printf("*");	
		}	
		else if (i == width - 1)
		{
			printf("*");	
		}	
		else
		{
			printf("-");
		}
	}
	printf("\n");
	for (j = 0; j < height - 2; j++) // kutunun sutunlarini yazdiriyoruz, -2 kullanma sebebimiz ise tepe ve tabani cikartmamiz
	{
		printf("|");
		int k;
		for (k = 0; k < width - 2; k++) // bosluklari koyuyoruz, -2 cikartma sebebimiz ise satir basi ve sonundaki | leri dislamak
		{
			
			printf(" ");
		
		}
		printf("|\n");
	}
	for (i = 0; i < width; i++) // tekrardan tabani yazdiriyoruz
	{
		if (i == 0)
		{
			printf("*");	
		}	
		else if (i == width - 1)
		{
			printf("*");	
		}	
		else
		{
			printf("-");
		}
	}
	getchar(); // buffer temizligi
	getchar(); // konsol kapanmasin diye durduruyoruz
}

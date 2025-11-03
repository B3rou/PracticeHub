#include <stdio.h>

int main(void){
	
	int sayi, sum;
	printf("Bir sayi giriniz");
	scanf("%d", &sayi);
	
	while (sayi != 0){
		sum += sayi % 10;
		sayi /= 10;
	}
	printf("%d", sum);
}

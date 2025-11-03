#include <stdio.h>

int main(void){
	
	int sayi, sum, decimal, rev;
	printf("Bir sayi giriniz");
	scanf("%d", &sayi);
	
	while (sayi != 0){
		decimal = sayi % 10;
		rev = rev * 10 + decimal;
		sayi /= 10;
	}
	
	printf("%d", rev);
}

#include <stdio.h>

int main(void){
	
	int sayi, initial, decimal, rev = 0;
	printf("Bir sayi giriniz");
	scanf("%d", &sayi);
	
	if (sayi < 0)
		return (0);
	
	initial = sayi;
	
	while (sayi != 0){
		decimal = sayi % 10;
		rev = rev * 10 + decimal;
		sayi /= 10;
	}
	
	if (initial == rev)
		printf("Your number is palindrome\n");
	else
		printf("Your number isn't palindrome\n");
		
	printf("Your Number: %d\nReversed Version: %d", initial, rev);
	
	return (0);
}

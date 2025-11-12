#include <stdio.h>
#include <math.h>

int pallindrome(int x);
int isPrime(int x);

int main(void){
	
	int number, reverse;
	
	printf("Please enter the number.\n");
	scanf("%d", &number);
	reverse = pallindrome(number);
	
	if (isPrime(number) && isPrime(reverse))
		printf("Your number is an Emirp number.");
	else
		printf("Your number is not an Emirp number. ");
	
}

int pallindrome(int x){
	int reverse = 0;
	while (x != 0){
		reverse = reverse*10 + (x%10);
		x /= 10;
	}
	return(reverse);
}

int isPrime(int x){
	if (x < 2) return (0);
	int i;
	for(i = sqrt(x); i > 1; i--){
		if (x % i == 0){
			return(0);
		}
	}
	return(1);
}

#include <stdio.h>

int digitCalculator(int x) {
	
	if (x == 0)
		return 0;
	return 1 + digitCalculator(x/10);
	
}

int main(void) {
	
	int x;
	printf("Please enter the number you wondering it's digit count... ");
	scanf("%d", &x);
	printf("Alright here: %d", digitCalculator(x));
	
}

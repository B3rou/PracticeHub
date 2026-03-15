#include <stdio.h>

int factorial(int x) {
	
	if (x == 0)
		return 1;
	return x * factorial(x-1);
	
}

int main(void) {
	
	int x;
	printf("Please enter the number you want to claculate it's factorial. ");
	scanf("%d", &x);
	printf("There you go: %d", factorial(x));
	
	
}

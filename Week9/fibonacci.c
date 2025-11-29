#include <stdio.h>

int fibonacci(int x) {
	
	if (x == 0 || x == 1)
		return x;
	return fibonacci(x-1) + fibonacci(x-2);
}

int main(void) {

	int x;
	printf("Please enter which N for fibonacci. ");
	scanf("%d", &x);
	printf("There you go: %d", fibonacci(x));

}

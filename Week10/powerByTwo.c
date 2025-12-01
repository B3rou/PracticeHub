#include <stdio.h>

void powerByTwo(int *xptr) {
	
	printf("There you go champion. Here is the result: %d", *xptr * *xptr);
	
}

int main(void) {
	int x;
	int* xptr = &x;
	printf("Please enter the value you want to power by 2: ");
	scanf("%d", xptr);
	
	powerByTwo(xptr);
}




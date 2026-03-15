#include <stdio.h>

int main(void) {
	int x, y;
	int* xptr = &x;
	int* yptr = &y;
	printf("Please enter 2 values\n");
	scanf("%d%d", xptr, yptr);
	printf("x = %d, y = %d\n", *xptr, *yptr);
	int temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
	printf("Swapped.\nNew Values are: x = %d, y = %d", *xptr, *yptr);
	return 0;
}

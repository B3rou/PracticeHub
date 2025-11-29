#include <stdio.h>

void reversing(int x, int *yptr) {
	if (x == 0)
        return;
    *yptr = *yptr*10 + x % 10;
    reversing(x/10, yptr);
}

int pallindromeCheck(int x) {
	int y = 0;
    int *yptr;
    yptr = &y;
    reversing(x, yptr);
	printf("\nReversed number is: %d\n", y);
	if (x == y)
		return 1;
	else
		return 0;
	
}

int main(void) {
	
	int x;
	printf("Please enter the number you want to check if it's pallindrome or not. ");
	scanf("%d", &x);
	if (pallindromeCheck(x))
		printf("Yeah, %d is Pallindrome!", x);
	else
		printf("Sorry but %d is not Pallindrome...", x);
    getchar();
    getchar();
	return 0;
}


#include <stdio.h>

int main(void) {
	
	int goal, sold;
	int* goalptr = &goal;
	int* soldptr = &sold;
	
	printf("What's your daily goal?\n");
	printf("It's: ");
	scanf("%d", goalptr);
	
	printf("Alright champion. How many u sold so far?\n");
	printf("I just sold: ");
	scanf("%d", soldptr);
	
	printf("Okay, you %d to go! Get back to work ^^", *goalptr - *soldptr);	
}

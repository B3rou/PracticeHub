#include <stdio.h>

void factorial(void);

int main(void){
	factorial();
}

void factorial(void){

	int num, i, sum = 1;
	printf("Please enter the number:\n");
	scanf("%d", &num);
	
	if (num < 0){
		printf("Error: The input couldn't be below 0.");
		
	}

	for (i = num; i>0; i--){
		sum *= i;
	}
	
	printf("%d's factorial is: %d", num, sum);
}

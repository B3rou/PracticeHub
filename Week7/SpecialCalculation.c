#include <stdio.h>

void coolCalculation(int n);

int main(void){
	
	int n;
	printf("Please enter the number.\n");
	scanf("%d", &n);
	coolCalculation(n);
}


void coolCalculation(int n){

	float sum, factorial = 1;
	int i, j;
	for (i = 1; i <= n; i++){
		for (j = i; j > 0; j--){
			factorial *= j;
		}
		sum += factorial/(i + 1);
		factorial = 1;
	}
	printf("The Computer Says that the answer is: %f", sum);
}

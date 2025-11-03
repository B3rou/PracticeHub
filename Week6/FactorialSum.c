#include <stdio.h>


int main(void){
	
	int i, j, last, factorial = 1, sum = 0;
	printf("Kaca kadar gitmek istersiniz?");
	scanf("%d", &last);
	
	for (i = 1; i<=last; i++){
		for (j = 1; j<=i; j++){
			factorial *= j;
		}
		sum += factorial;
		factorial = 1;
	}
	printf("%d", sum);
	return (0);
}

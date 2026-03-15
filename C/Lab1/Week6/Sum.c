#include <stdio.h>

int main(void){
	
	int i, last, sum = 0;
	printf("Kaca kadar gitmek istersiniz?");
	scanf("%d", &last);
	
	for (i = 1; i<=last; i++){
		sum += i;
	}
	printf("%d", sum);
}	

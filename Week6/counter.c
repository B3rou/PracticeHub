#include <stdio.h>

int main(void){
	
	int i, last;
	printf("Kaca kadar sayilmasini istersiniz?: \t");
	scanf("%d", &last);
	for (i = 1; i<= last; i++)
		printf("%d ", i);
	getchar();
	getchar();
}

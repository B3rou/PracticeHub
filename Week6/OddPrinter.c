#include <stdio.h>

int main(void){
	
	int i = 0, last;
	printf("Kaca kadar gitmek istersiniz?");
	scanf("%d", &last);
	
	while (i <= last){
		if (i%2 == 1)
			printf("%d ", i);
		i++;
	}
	
	return 0;
}

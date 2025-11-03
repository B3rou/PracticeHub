#include <stdio.h>

int main(void){
	
		
	int i, j=0, height;
	printf("Yukseklik ne olsun?");
	scanf("%d", &height);
	
	for (i=1;i<=height;i++){
		for (j=0;j<i;j++){
			printf("#");	
		}
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>

int main(void){
	
		
	int i, j, blank, height, letter = 65;
	printf("Yukseklik ne olsun?");
	scanf("%d", &height);
	
	for (i=1;i<=height;i++){
		blank = height;
		for (; blank>i; blank--)
			printf(" ");
		for (j=0;j<i;j++){
			printf("%c ", letter);
			if (letter == 90)
				letter = 65;
			else
				letter++;
				
		}
		printf("\n");
	}
	
	return 0;
}

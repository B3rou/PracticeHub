#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomMe(int* ptr) {
	
	*ptr = rand() % 10;
	return;
}

int main(void) {
	srand(time(NULL));
	int i,len;
	printf("How many randomized numbers your looking for?\n");
	scanf("%d", &len);
	
	int randomized[len];
	
	printf("Generated Randomized Numbers! There you go:\n");
	
	for (i = 0; i < len; i++) 
	{
		randomMe(&randomized[i]);
		printf("%d. %d\n", i + 1, randomized[i]);
	}
	
	return 0;
}

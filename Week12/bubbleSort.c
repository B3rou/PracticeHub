#include <stdio.h>

void swapNext(int* ptr)
{
	int temp = *ptr;
	*ptr = *(ptr + 1);
	*(ptr + 1) = temp;
	return;
}

int main(void) {
	int len,i,j;
	printf("Please enter the amount you'll enter.\n");
	scanf("%d", &len);
	int array[len];	
	for (i = 0; i < len; i++) {
		scanf("%d", &array[i]);
	}
	printf ("Alright, here's the array you entered.\n");
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("Now, we'll bubble sort it.");
	for (j = len - 1; j > 0; j--)
		for (i = 0; i < j; i++) {
			if (array[i] > array[i+1])
				swapNext(&array[i]);
		}
	printf("\nDone:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}




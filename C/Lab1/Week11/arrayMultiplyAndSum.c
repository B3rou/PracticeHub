#include <stdio.h>

int multiply(int* ptr, int len) {
	int sum = *ptr, i;
	if (len == 0)
		return sum;
	for (i = 1; i < len; i++) 
	{
		sum *= *(ptr + i);
	}
	return sum;
}	

int sum(int* ptr, int len) {
	int sum = 0, i;
	
	for (i = 0; i < len; i++) 
	{
		sum += *(ptr + i);
	}

	return sum;
}

int main(void) {
	
	int i,len;
	printf("How many numbers you'll enter'?\n");
	scanf("%d", &len);
	int array[len];
	
	for (i = 0; i < len; i++) 
	{
		printf("%d.", i);
		scanf("%d", &array[i]);
	}
	
	printf("Alright.\nMultiply is : %d\nSum is: %d", multiply(array, len), sum(array, len));
}

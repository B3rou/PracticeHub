#include <stdio.h>

int main(void) 
{
	
	int i, amount;
	printf("Please enter the amount of values you'ld like to enter.\n");
	scanf("%d", &amount);
	int sorted[amount];
	int *sortedptr[amount];
	for (i = 0; i < amount; i++) 
	{	
		sortedptr[i] = &sorted[i];
		printf("The %d. number is: ", i+1);
		scanf("%d", sortedptr[i]);
	}
	int len = sizeof(sorted) / sizeof(sorted[0]);
	int index, number, base = 0;
	int temp;
	
	while (1) 
	{
		number = sorted[base];
		index = base;
		for (i = base; i < len; i++) 
		{
			if (sorted[i] < number) 
			{
				number = sorted[i];
				index = i;
			}
		}
		temp = sorted[base];
		sorted[base] = sorted[index];
		sorted[index] = temp;
		base++;
		if (base == len) break;
	}
	printf("Here is the sorted array of your input: ");
	for (i = 0; i < len; i++)
		printf("%d ", sorted[i]);
	printf("\n");
	printf("The greatest number among them is: %d. GG!", sorted[len-1]);
}

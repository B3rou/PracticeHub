#include <stdio.h>

void swap(int* ptr1, int*ptr2) {
	printf("Swapping it!\n");
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	return;
}

int main(void) {
	
	int arr[] = {7,5,8};
	int i, len = sizeof(arr)/sizeof(arr[0]);
	printf("Current array is something like that:\n");
	
	for (i = 0; i < len; i++){
		printf("%d ", *(arr + i));
	}
	
	printf("\nWell, choose indexes you'ld like to swap. (Start from 1 to end like a human beeing. Your not computer...)\n");
	int index1, index2;
	int* ptr1; 
	int* ptr2;
	
	do {
	scanf("%d%d", &index1, &index2);
	} while (0 >= index1 || index1 > len || 0 >= index2 || index2 > len);
	
	ptr1 = &arr[index1 - 1];
	ptr2 = &arr[index2 - 1];
	
	swap(ptr1, ptr2);
	
	for (i = 0; i < len; i++){
		printf("%d ", *(arr + i));
	}
	
	printf("\nThere you go!");
	
	return 0;
}

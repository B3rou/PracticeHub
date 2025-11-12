#include <stdio.h>

float add(float x, float y);
float sub(float x, float y);
float multiply(float x, float y);
float div(float x, float y);

int main(void){
	
	float x,y;
	int sellection;
	printf("Please enter 2 Value.\n");
	scanf("%f%f", &x, &y);
	printf("Please select the operation:\n");
	printf("1. Addition\n");
	printf("2. Substraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	scanf("%d", &sellection);
	
	
	switch(sellection){
		case 1:
			printf("%.2f + %.2f is equal to %f", x, y, add(x,y));
			break;
		case 2:
			printf("%.2f - %.2f is equal to %f", x, y, sub(x,y));
			break;
		case 3:
			printf("%.2f * %.2f is equal to %f", x, y, multiply(x,y));
			break;
		case 4:
			if (y == 0){
				printf("Error: Can't divide by 0");
				break;
			}
			printf("%.2f / %.2f is equal to %.2f", x, y, div(x,y));
			break;
	}
}


float add(float x, float y){
	
	return(x+y);
	
}

float sub(float x, float y){
	
	return(x-y);
}

float multiply(float x, float y){
	
	return(x*y);
}

float div(float x, float y){
	
	return(x/y);
}


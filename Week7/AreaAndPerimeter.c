#include <stdio.h>

float squareArea(float edge);
float squarePerimeter(float edge);

int main(void){
	float a;
	printf("Please enter the Square's edge:");
	scanf("%f", &a);
	
	printf("The Square's Area is: %.2f\n", squareArea(a));
	printf("The Square's Perimeter is: %.2f", squarePerimeter(a));
}

float squareArea(float edge){
	return(edge*edge);
}

float squarePerimeter(float edge){
	return(edge*4);
}


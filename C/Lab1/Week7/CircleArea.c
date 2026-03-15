#include <stdio.h>
#define PI 3.14

void circleArea(float radius);

int main(void){
	
	float r;
	printf("Please enter the Radius of the Circle.\n");
	scanf("%f", &r);
	circleArea(r);

}


void circleArea(float radius){
	
	float area = radius*radius*PI;
	printf("The area of the circle is: %.2f", area);
}

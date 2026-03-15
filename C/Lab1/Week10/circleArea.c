#include <stdio.h>
#define PI 3.14159265358

void daireAlani(float *yaricap, float *alan) {
	*alan = PI * *yaricap * *yaricap;
}

int main(void) {
	
	float radius, area;
	float* yaricap = &radius;
	float* alan = &area;
	printf("Please enter the radius of the circle: ");
	scanf("%f", yaricap);
	
	daireAlani(yaricap, alan);
	
	printf("Radius is: %.2f, area is: %.2f", radius, area);
	return 0;
}

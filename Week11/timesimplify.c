#include <stdio.h>

void calculate(long long input);

int main(void)
{
	long long input;
	printf("Please enter how much time it take as seconds. We'll simplify it.\n");
	scanf("%lld", &input);
	calculate(input);
		
}

void calculate(long long input) {
	long long hour = 0, min = 0, sec = 0;
	
	hour = input/3600;
	input -= hour*3600;
	min = input/60;
	input -= min*60;
	sec = input;
	
	printf("There you go! %lld Hours %lld Mins and %lld Seconds.", hour, min, sec);
	
	
	
}

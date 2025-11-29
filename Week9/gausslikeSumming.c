#include <stdio.h>

int sum(int x) {
		
	if (x == 0)
		return x;
	return x + sum(x - 1);

}

int main(void){
	
	int x;
	printf("When should we stop summing? ");
	scanf("%d", &x);
	printf("Okay, There you go %d", sum(x));
	
}

#include <stdio.h>

int calculate(int x){
    if (x == 0){
        return x;
    }
    return ((x % 10) + calculate(x / 10));
}


int main(void){
    
    int y;
    printf("Please input");
    scanf("%d", &y);
    
    printf("%d is %d", y, calculate(y));
    
    
}
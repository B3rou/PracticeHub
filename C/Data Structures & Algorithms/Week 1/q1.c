//1. 1.	C kodunu yazınız. 

#include <stdio.h>

int main() {
    int n = 10;
    int arr[10];
    int i;

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

    2.	T(n) zaman maliyetini hesaplayınız. 
    3.	O(n) zaman karmaşıklığını bulunuz. 
    4.	Programın S(n) alan karmaşıklığını bulunuz. 
    
        T(n) = 6n + 5, O(n), Eğer array her zaman 10 ise S(1), Ama nottaki yazıya göre Array n'e bağlı olarak değişiyorsa S(n) 

*/
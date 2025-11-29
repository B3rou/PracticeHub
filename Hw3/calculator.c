#include <stdio.h>

int main(void){

    double ilk, ikinci;
    char islem;
    printf("Lutfen 2 sayi giriniz:\n");
    scanf("%lf%lf", &ilk, &ikinci);
    getchar();
    printf("Yapmak istediginiz islemi seciniz: (+, -, *, /)");
    scanf("%c", &islem);
    getchar();
    switch(islem){
        case('+'):
            printf("Isleminizin sonucu: %.2lf", ilk + ikinci);
            break;
        case('-'):
            printf("Isleminizin sonucu: %.2lf", ilk - ikinci);
            break;   
        case('*'):
            printf("Isleminizin sonucu: %.2lf", ilk * ikinci);
            break;
        case('/'):
            printf("Isleminizin sonucu: %.2lf", ilk / ikinci);
            break;   
    }

    getchar();
    getchar();
    return 0;
}

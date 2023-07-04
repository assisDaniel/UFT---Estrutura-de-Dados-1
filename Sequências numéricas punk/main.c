#include "punkNumbers.h"

int main(void){
    int num,x;
    tlist *li= listCreate();
    tlist *seps= listCreate();

    printf("\nDigite um numero inteiro positivo de 4 digitos: ");
    scanf("%d", &num);

    resolution(li, seps, num);
}
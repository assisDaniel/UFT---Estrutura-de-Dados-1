#include <stdio.h>
#include <stdlib.h>
#include "numBacana.h"

int main(void){
    int num, x;
    tList *solution= listCreate();
    tList *sepNums= listCreate();
    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);
    add(solution, num);
    
    int check= oneDigit(solution);
    while(check!=1){
        num= lastNum(solution);
        separeNum(sepNums, num);
        add(solution, powSum(sepNums));
        x= tamNum(num);
        for(int i=0; i<x; i++){
            listRemove(sepNums, lastNum(sepNums));
        }
        check= oneDigit(solution);
    }
    listPrint(solution);
    num= lastNum(solution);
    if(num==1){
        printf("\nBacana");
    }else{
        printf("\nNon-bacana");
    }
    
    putchar('\n');
    system("pause");
}
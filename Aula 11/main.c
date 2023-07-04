#include "bigint.h"

int main(void){
    char num[4097];
    fgets(num, 4096, stdin);
    dlist *li= addTransformed(num);
    fgets(num, 4096, stdin);
    dlist *lii= addTransformed(num);

    dlist *result= sum(li, lii);
    listPrint(li);
    listPrint(lii);
    listPrint(result);
}
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    tList *notasEd1= listCreate();

    for(int i=0; i<10; i++){
        int newValue= i*10;
        listAdd(notasEd1, newValue);
    }
    listPrint(notasEd1);
    putchar('\n');
    system("pause");
}

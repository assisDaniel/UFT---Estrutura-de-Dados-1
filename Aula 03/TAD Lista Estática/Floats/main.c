#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    tList *notasEd1= listCreate();

    for(float i=0; i<10; i++){
        float newValue= i*10;
        listAdd(notasEd1, newValue);
    }
    listPrint(notasEd1);
    putchar('\n');
    system("pause");
}

#include "duplinkedList.h"

int main(void){
    tlist *li= listCreate();

    addEnd(li, 10);
    addEnd(li, 11);
    addEnd(li, 12);
    listPrint(li);
    printReverse(li);

    listDelete(li, 11);
    listPrint(li);
    printReverse(li);
}
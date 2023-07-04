#include "circularList.h"

int main(void){
    tlist *l1= listCreate();
    
    add(l1, 10);
    add(l1, 25);
    add(l1, 35);
    listPrint(l1);
}
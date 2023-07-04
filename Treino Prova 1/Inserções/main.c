#include "insert.h"

int main(void){
    tlist *li= listCreate();
    int op;
    printf("Type: \n- [1]To add in the begin\n- [2]To add in the mid\n- [3]To add in the end\nChoice: ");
    scanf("%d", &op);

    switch(op){
        case 1:
        addBegin(li, 10);
        addBegin(li, 25);
        listPrint(li);
        removeElem(li, 25);
        listPrint(li);
        break;

        case 2:
        addMid(li, 25);
        addMid(li, 10);
        addMid(li, 35);
        listPrint(li);
        removeElem(li, 35);
        listPrint(li);
        break;

        case 3:
        addEnd(li, 10);
        addEnd(li, 25);
        listPrint(li);
        removeElem(li, 25);
        listPrint(li);
        break;
        
        default:
        puts("Option not available");
        break;
    }
}
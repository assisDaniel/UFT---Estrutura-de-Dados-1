#include "equal.h"

int main(void){
    clist *l1= listCreate();
    clist *l2= listCreate();
    
    int qty, qty2;
    scanf("%d%d", &qty, &qty2);
    int v[qty], v2[qty2];
    for(int i=0; i<qty; i++){
        scanf("%d", &v[i]);
        add(l1, v[i]);
    }
    for(int i=0; i<qty2; i++){
        scanf("%d", &v2[i]);
        add(l2, v2[i]);
    }
    listPrint(l1);
    listPrint(l2);
    printf("\nResultado da comparacao: %d", checkEqual(l1, l2));
}
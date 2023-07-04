#include "tad.h"

int main(void){
    int x,y;

    printf("\nType the value of X: ");
    scanf("%d", &x);
    printf("\nType the value of Y: ");
    scanf("%d", &y);

    tad *idk= createSmth(x, y);
    printSmth(idk);
    sum(idk);
    multi(idk);
}
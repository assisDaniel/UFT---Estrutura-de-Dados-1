#include "tad.h"

struct idk{
    int x, y;
};

tad *createSmth(int x, int y){
    tad *new= malloc(sizeof(tad));
    if(new!=NULL){
        new->x= x;
        new->y= y;
    }
    return new;
}

void printSmth(tad *lista){
    printf("\nValue of X: %d\nValue of Y: %d", lista->x, lista->y);
}

void sum(tad* lista){
    int soma= lista->x + lista->y;
    printf("\nValue of the sum of X & y: %d", soma);
}

void multi(tad *lista){
    int result= lista->x * lista->y;
    printf("\nValue of the multiplication of X & Y: %d", result);
}
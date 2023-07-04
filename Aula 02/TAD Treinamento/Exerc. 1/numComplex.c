#include <stdio.h>
#include "numComplex.h"

struct ponto{
    float x;
    float y;
};

Ponto* numCreate(float x, float y){
    struct ponto *num= (Ponto *) malloc(sizeof(Ponto));
    if(num!=NULL){
        num->x= x;
        num->y= y;
    }
}
void numDelete(Ponto *num){
    free(num);
}
float sumComplex(Ponto *cmplx, Ponto *cmplx2){
    float sum_x= cmplx->x + cmplx2->x;
    float sum_y= cmplx->y + cmplx2->y;

    float sum= printf("\n%.2f + %.2fi", sum_x, sum_y);
    return sum;
}
float diffComplex(Ponto *cmplx, Ponto *cmplx2){
    float diff_x= cmplx->x - cmplx2->x;
    float diff_y= cmplx->y - cmplx2->y;

    float diff= printf("\n%.2f + %.2fi", diff_x, diff_y);
    return diff;
}
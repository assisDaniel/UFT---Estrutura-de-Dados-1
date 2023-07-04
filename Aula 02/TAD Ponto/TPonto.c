#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TPonto.h"

struct ponto{
    float x, y;
};

struct ponto *TPonto_create(float x, float y){
    struct ponto *novoPonto= malloc(sizeof(struct ponto));
    if(novoPonto!= NULL){
        novoPonto->x= x;
        novoPonto->y= y;
    }
    return novoPonto;
}
void TPonto_print(TPonto *ponto){
    printf("(%.2f, %.2f)", ponto->x, ponto->y);
}
float TPonto_dist(TPonto *p1, TPonto *p2){
    float diff_x= p1->x - p2->x;
    float diff_y= p1->y - p2->y;
    float pwr2_x= pow(diff_x, 2);
    float pwr2_y= pow(diff_y, 2);

    return sqrtf(pwr2_x + pwr2_y);
}
void TPonto_set(TPonto *ponto, float x, float y){
    ponto->x= x;
    ponto->y= y;
}
#include <stdio.h>
#include "numComplex.h"

int main(void){
    Ponto *cmplx= numCreate(2.7, 5.57);
    Ponto *cmplx2= numCreate(2.5, 3.33);

    sumComplex(cmplx, cmplx2);
    diffComplex(cmplx, cmplx2);

    free(cmplx);
    free(cmplx2);

    printf("\n%.2f\n%.2f", cmplx, cmplx2);
    system("pause");
}
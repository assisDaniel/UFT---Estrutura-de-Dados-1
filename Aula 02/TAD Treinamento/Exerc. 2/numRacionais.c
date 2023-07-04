#include <stdio.h>
#include <stdlib.h>
#include "numRacionais.h"

struct ponto{
    int x, y;
};

Ponto* createNum(int x, int y){
    struct ponto *num= (Ponto *)malloc(sizeof(Ponto));
    if(num!=NULL){
        num->x= x;
        num->y= y;
    }
    return num;  
  }
void numPrint(Ponto* frac){
  printf("\n%d/%d", frac->x, frac->y);
}
Ponto* multNum(Ponto *frac, Ponto *frac2){
  int mult_x= frac->x * frac2->x;
  int mult_y= frac->y * frac2->y;

  return createNum(mult_x, mult_y);
}
Ponto* sumNum(Ponto *frac, Ponto *frac2){
  int novoNum= frac->x * frac2->y;
  int novoDen= frac2->x * frac->y;
  int multDen= frac->y * frac2->y;

  return createNum((novoNum + novoDen), multDen);
}
bool equal(Ponto* frac, Ponto* frac2){
  return ((float)frac->x/frac->y == (float)frac2->x/frac2->y);
}
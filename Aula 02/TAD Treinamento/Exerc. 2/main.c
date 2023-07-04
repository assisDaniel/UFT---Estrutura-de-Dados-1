#include <stdio.h>
#include "numRacionais.h"

int main(void){
  Ponto* frac1= createNum(1, 2);
  Ponto* frac2= createNum(3, 4);
  numPrint(frac1);
  numPrint(frac2);
  numPrint(sumNum(frac1, frac2));
  numPrint(multNum(frac1, frac2));
  if(equal(frac1, frac2)){
    printf("\nIguais");
  }else{
    printf("\nDiferentes");
  }
}
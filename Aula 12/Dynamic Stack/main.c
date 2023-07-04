#include "Stack.h"

int main(void) {
  int temp;
  stack *piula1 = stackCreate();
  for(int i=0; i<12; i++){
    if(!spush(piula1, i))
      printf("Stack overflow ao tentar inserir %d\n", i);
  }
  while(spop(piula1, &temp)) printf("Valor removido: %d\n", temp);
}
#include "Stack.h"

int main(void) {
  int temp;
  int V[] = {5, 6, 7, 1, 2, 4, 5, 9};
  stack *piula1 = stackCreate();
  for(int i=0; i<8; i++){
    if(!spush(piula1, V[i]))
      printf("Stack overflow ao tentar inserir %d\n", V[i]);
  }
  while(spop(piula1, &temp)) printf("Valor removido: %d\n", temp);
}
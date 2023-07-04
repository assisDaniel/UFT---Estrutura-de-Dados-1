#include "linkedList.h"
#include <stdio.h>

int main() {
  tList *l1 = listCreate();
  int V[] = {7, 2, 13, 5};
  for (int i = 0; i < 4; i++) {
    if (!listAdd(l1, V[i]))
      printf("Nao consegui inserir o elemento V[%d]=%d\n", i, V[i]);
  }
  listRemove(l1, 13);
  listPrint(l1);

  putchar('\n');
  system("pause");
}
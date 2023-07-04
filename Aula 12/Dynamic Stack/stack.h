#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no node;
typedef struct pilha stack;

stack *stackCreate();
node *nodeCreate(int);
bool spush(stack *p, int);
bool spop(stack*, int*);
// bool full(); não é necessário pois só fica cheia quando a memória ta cheia.
bool empty(stack*);
bool stackHead(stack*, int *);

#endif
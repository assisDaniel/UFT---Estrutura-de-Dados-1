#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no node;
typedef struct pilha stack;

stack *stackCreate();
bool spush(stack *p, int);
bool spop(stack*, int*);
bool full(stack*);
bool empty(stack*);

#endif
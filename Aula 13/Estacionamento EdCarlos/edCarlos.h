#ifndef EDCARLOS_H
#define EDCARLOS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct pilha stack;

stack *stackCreate();
bool full(stack*);
bool empty(stack*);
bool spush(stack*, int);
bool spop(stack*);
void stackPrint(stack*);
void transfer(stack *, int);
#endif
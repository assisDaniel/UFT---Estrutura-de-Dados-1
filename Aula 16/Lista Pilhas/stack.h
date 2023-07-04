#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 10

typedef struct no node;
typedef struct pilha stack;

stack *stackCreate();
node *nodeCreate(int);
bool empty(stack*);
bool full(stack*);
bool spush(stack*, int);
bool spop(stack*, int*);
void stackPrint(stack*);

#endif
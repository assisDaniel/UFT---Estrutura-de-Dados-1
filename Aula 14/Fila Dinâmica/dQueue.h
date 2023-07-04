#ifndef DQUEUE_H
#define DQUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no node;
typedef struct fila dQueue;

dQueue *queueCreate();
node *nodeCreate(int);
bool full(dQueue*);
bool empty(dQueue*);
bool enqueue(dQueue*, int);
bool dequeue(dQueue*, int*);
void queuePrint(dQueue*);

#endif
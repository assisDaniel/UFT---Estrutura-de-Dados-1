#ifndef QUEUE_H
#define QUEUE_H
#define max 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila queue;

queue* queueCreate();
bool full(queue*);
bool empty(queue*);
bool enqueue(queue*, int);
bool dequeue(queue*, int*);
void queuePrint(queue*);
#endif
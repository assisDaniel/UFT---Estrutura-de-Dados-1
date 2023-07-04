#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 10;

typedef struct fila queue;
typedef struct no node;

queue *queueCreate();
node *nodeCreate(int);
bool empty(queue*);
bool enqueue(queue*, int);
bool dequeue(queue*, int*);
void queuePrint(queue*);

#endif
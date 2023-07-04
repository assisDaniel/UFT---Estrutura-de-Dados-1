#ifndef BIGINT_H
#define BIGINT_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct no node;
typedef struct list dlist;

dlist *listCreate();
node *nodeCreate(int);
bool addEnd(dlist*, int);
bool addBegin(dlist*, int);
void listPrint(dlist*);
int transform(char );
dlist *addTransformed(char *);
dlist *sum(dlist*, dlist*);

#endif
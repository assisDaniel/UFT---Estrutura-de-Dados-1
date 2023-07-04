#ifndef DUPLINKEDLIST_H
#define DUPLINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list tlist;
typedef struct no node;

tlist *listCreate();
node *nodeCreate(int);
bool addBegin(tlist*, int);
bool addEnd(tlist*, int);
bool listDelete(tlist*, int);
void listPrint(tlist*);
void printReverse(tlist*);

#endif
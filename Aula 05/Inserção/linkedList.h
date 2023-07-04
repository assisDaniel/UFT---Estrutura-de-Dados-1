#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>
typedef struct list tList;
typedef struct no node;

tList *listCreate();
node *nodeCreate(int);
bool listAdd(tList*, int);
void listPrint(tList*);
void listDelete(tList*);

#endif
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>

typedef struct list tlist;
typedef struct no node;

tlist *listCreate();
node *nodeCreate(int);
bool add(tlist*, int);
void listPrint(tlist*);
void listDelete(tlist*);
bool listRemove(tlist*, int);

#endif
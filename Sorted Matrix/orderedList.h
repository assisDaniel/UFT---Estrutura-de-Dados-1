#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no node;
typedef struct list tlist;

tlist *listCreate(unsigned int m);
node *nodeCreate(int index, int *linha);
bool add(tlist* lista, int index, int *linha);
void listPrint(tlist *lista);

#endif
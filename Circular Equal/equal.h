#ifndef EQUAL_H
#define EQUAL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list clist;
typedef struct no node;

clist *listCreate();
node *nodeCreate(int);
bool add(clist*, int);
bool checkEqual(clist*, clist*);

#endif
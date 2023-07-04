#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct no node;
typedef struct list tlist;

tlist *listCreate();
node *nodeCreate(int**);
bool add(tlist*, int**);
void mPrint(tlist*, int, int);

#endif
#ifndef TAD_H
#define TAD_H
#include <stdio.h>
#include <stdlib.h>

typedef struct idk tad;

tad *createSmth(int, int);
void printSmth(tad*);
void sum(tad*);
void multi(tad*);
void removeElem(tad*);

#endif
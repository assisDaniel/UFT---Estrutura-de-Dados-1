#ifndef TADVECTOR_H
#define TADVECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct vector idk;

idk *createVector();
void add(idk*, int);
void removeElem(idk*, int);
void printVector(idk*);
bool checkNum(idk*, int);

#endif
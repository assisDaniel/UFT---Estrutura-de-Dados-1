#ifndef PUNKNUMBERS_H
#define PUNKNUMBERS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no node;
typedef struct list tlist;

node *nodeCreate(int info);
tlist *listCreate();
bool add(tlist *lista, int info);
bool isEven(int info);
int checkDigits(int info);
bool addBegin(tlist *lista2, int info);
void separeNum(tlist* lista, int info);
int lastNum(tlist *lista);
void listPrint(tlist *lista);
bool listRemove(tlist *lista, int info);
bool oneDigit(tlist* lista);
int firstpart(tlist* lista, tlist* seps);
int scndpart(tlist* lista, tlist* seps);
void merge(tlist* lista, tlist* seps);
void resolution(tlist* lista, tlist* seps, int info);
int qtyNodes(tlist* lista);

#endif
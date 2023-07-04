#ifndef NUMBACANA_H
#define NUMBACANA_H
#include <stdbool.h>

typedef struct no node;
typedef struct list tList;

tList *listCreate();
node *nodeCreate(int);
bool add(tList*, int);
bool listRemove(tList*, int);
void listPrint(tList*);
void listDelete(tList*);
void separeNum(tList*, int);
int powSum(tList*);
int oneDigit(tList*);
int tamNum(int num);
int lastNum(tList*);

#endif
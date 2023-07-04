#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct list tList;

tList *listCreate();
bool listAdd(tList*, char*, char*);
void listPrint(tList*);
void listRemove(tList*);

#endif
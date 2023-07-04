#ifndef SBSTRINGS_H
#define SBTRINGS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE_MAX 10000
typedef struct no node;
typedef struct list tlist;

tlist *listCreate(char);
node *nodeCreate(int, int);
bool add(tlist*, int, int);
bool listRemove(tlist*, int);
void listPrint(tlist*);
tlist *encoder(char*);
char *decoder(tlist*);


#endif
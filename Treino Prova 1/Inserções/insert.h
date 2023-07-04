#ifndef INSERT_H
#define INSERT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list tlist;
typedef struct no node;

/**
 * Função que cria a lista.
*/
tlist *listCreate();

/**
 * Função que cria os nós.
 * @param int se refere a informação que será adicionada no nó.
*/
node *nodeCreate(int);

/**
 * Função de inserção no início.
 * @param tlist* se refere a lista em que a operação será realizada.
 * @param int informação a ser adicionada.
*/
bool addBegin(tlist*, int);

/**
 * Função de inserção no fim.
 * @param tlist* se refere a lista em que a operação será realizada.
 * @param int informação a ser adicionada.
*/
bool addEnd(tlist*, int);

/**
 * Função de inserção no meio/ inserção ordenada.
 * @param tlist* se refere a lista em que a operação será realizada.
 * @param int informação a ser adicionada.
*/
bool addMid(tlist*, int);

/**
 * Função que remove um elemento específico da lista.
 * @param tlist* lista em que a operação será realizada.
 * @param int informação que será removida.
*/
bool removeElem(tlist*, int);

/**
 * Função que imprime a lista completa.
 * @param tlist* lista em que a operação será realizada.
*/
void listPrint(tlist*);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct no{
    int info;
    struct no *next;
}node;

struct list{
    node *inicio;
};

bool listAdd(tList *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio!=NULL)
        new->next= lista->inicio;
    lista->inicio= new;
    return true;
}                                  //Com a criação do arquivo "linkedList.c" podemos comentar as coisas que iriam se repitir.


/*
node *nodeCreate(int);
node *nodeCreate(int info){
    struct no *new= malloc(sizeof(node));
    if(new!=NULL){
        new->info= info;
        new->next= NULL;
    }
    return new;
}

tList *listCreate(){
    struct list *new= malloc(sizeof(tList));
    if(new!= NULL){
        new->inicio= NULL;
    }
    return new;
}

void listPrint(tList *lista){
    node *aux= lista->inicio;
    while(aux!=NULL){
        printf("[info: %d  prox: %p] ->", aux->info, aux->next);
        aux= aux->next; 
    }
}
*/
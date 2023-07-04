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

node *nodeCreate(int);
node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
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
    while(aux!= NULL){
        printf("[info: %d  prox: %p] -> ", aux->info, aux->next);
        aux= aux->next;
    }
}
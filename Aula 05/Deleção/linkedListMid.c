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
    if(lista->inicio== NULL){
        lista->inicio= new;
    }else{
        if(new->info < lista->inicio->info){
            new->next= lista->inicio;
            lista->inicio= new;
        }else{
            node *y= lista->inicio;
            while(y->next != NULL){
                if(y->next->info > new->info){
                    break;
                }
                y= y->next;
            }
            new->next= y->next;
            y->next= new;
        }
    }
    return true;
}                               //Com a criação do arquivo "linkedList.c" podemos comentar as coisas que iriam se repetir.

/* node *nodeCreate(int);
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
} */

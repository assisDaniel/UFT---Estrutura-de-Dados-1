#include "duplinkedList.h"

struct no{
    int info;
    node *next;
    node *ant;
};

struct list{
    node *inicio;
    node *fim;
};

tlist *listCreate(){
    tlist *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->inicio= NULL;
        new->fim= NULL;
    }
    return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->info= info;
        new->next= NULL;
        new->ant= NULL;
    }
    return new;
}

bool addBegin(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL && lista->fim==NULL){
        lista->inicio= new;
        lista->fim= new;
    }else{
        new->next = lista->inicio;
        lista->inicio->ant= new;
        lista->inicio= new;

    }
    return true;
}

bool addEnd(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL && lista->fim==NULL){
        lista->inicio= new;
        lista->fim= new;
    }else{
        new->ant= lista->fim;
        lista->fim= new;
        node* aux= lista->fim;
        aux= aux->ant;
        aux->next= lista->fim;
    }
    return true;
}

bool listDelete(tlist *lista, int info){
    node *ant= NULL;
    node *p= lista->inicio;

    while(p!=NULL && p->info!=info){
        ant= p;
        p= p->next;
    }
    if(p==NULL){
        return false;
    }
    if(ant==NULL){
        lista->inicio= p->next;
    }
    if(p==lista->fim){
        lista->fim= p->ant;
    }
    if(p->ant!=NULL){
        p->ant->next= p->next;
    }
    if(p->next!=NULL){
        p->next->ant= p->ant;
    }
    free(p);
    return true;
}


void listPrint(tlist *lista){
    node *aux= lista->inicio;
    putchar('\n');
    while(aux!=NULL){
        printf("%d%s", aux->info, (aux->next)? " -> ":"");
        aux= aux->next;
    }
}

void printReverse(tlist *lista){
    node *aux= lista->fim;
    putchar('\n');
    while(aux!=NULL){
        printf("%d%s", aux->info, (aux->ant)? " -> ":"");
        aux= aux->ant;
    }
}
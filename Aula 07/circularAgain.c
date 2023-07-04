#include "circularList.h"

struct no{
    node *next;
    int info;
};

struct list{
    node *inicio;
};

tlist *listCreate(){
    tlist *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->inicio= NULL;
    }
    return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->info= info;
        new->next= NULL;
    }
    return new;
}

bool add(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
        lista->inicio->next= lista->inicio;
    }else{
        node *aux= lista->inicio;
        while(aux->next!=lista->inicio){
            aux= aux->next;
        }
        aux->next= new;
        new->next= lista->inicio;
        lista->inicio= new;
    }
    return true;
}

void listPrint(tlist *lista){
    node *aux= lista->inicio;
    do{
        printf("%d%s", aux->info, (aux->next!=lista->inicio)? " -> ":"");
        aux= aux->next;
    }while(aux!=lista->inicio);
}
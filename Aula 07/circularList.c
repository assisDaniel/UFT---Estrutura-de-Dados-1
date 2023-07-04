#include "circularList.h"

typedef struct no{
    int info;
    struct no *next;
};

struct list{
    node *inicio;
};

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->info= info;
        new->next= NULL;
    }
    return new;
}

tlist *listCreate(){
    struct list *new= malloc(sizeof(tlist));
    if(new!= NULL){
        new->inicio= NULL;
    }
    return new;
}

void listPrint(tlist *lista){
    node *aux= lista->inicio;
    do{
        printf("%d%s", aux->info, (aux->next!=lista->inicio)? " -> " : "");
        aux= aux->next;
    }while(aux!= lista->inicio);
}

bool add(tlist* lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
        lista->inicio->next= lista->inicio;
    }else{
        node* aux= lista->inicio;
        while(aux->next!= lista->inicio){
            aux= aux->next;
        }
        aux->next= new;
        new->next= lista->inicio;
        lista->inicio= new;
    }
    return true;
}

bool listRemove(tlist *lista, int info){
    node *ant= NULL;
    node* p= lista->inicio;

    while(p!= NULL && p->info != info){
        ant= p;
        p= p->next;
    }
    if(p== NULL){
        return false;
    }
    if(ant == NULL){
        lista->inicio= p->next;
    }else{
        ant->next= p->next;
    }
    free(p);
    return true;
}

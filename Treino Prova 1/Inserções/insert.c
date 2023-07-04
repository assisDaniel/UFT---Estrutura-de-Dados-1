#include "insert.h"

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

void listPrint(tlist *lista){
    node *aux= lista->inicio;
    putchar('\n');
    while(aux!=NULL){
        printf("%d%s", aux->info, (aux->next)? " -> ":"");
        aux= aux->next;
    }
}

bool addBegin(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        new->next= lista->inicio;
        lista->inicio= new;
    }
    return true;
}

bool addEnd(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        node *aux= lista->inicio;
        while(aux->next!=NULL){
            aux= aux->next;
        }
        aux->next= new;
    }
    return true;
}

bool addMid(tlist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        if(lista->inicio->info > new->info){
            new->next= lista->inicio;
            lista->inicio= new;
        }else{
            node *aux= lista->inicio;
            while(aux->next!=NULL){
                if(aux->next->info > new->info){
                    break;
                }
                aux= aux->next;
            }
            new->next= aux->next;
            aux->next= new;
        }
    }
    return true;
}

bool removeElem(tlist *lista, int info){
    node *ant= NULL;
    node *p= lista->inicio;

    while(p!=NULL && p->info!= info){
        ant= p;
        p= p->next;
    }
    if(p==NULL){
        return false;
    }
    if(ant==NULL){
        lista->inicio= p->next;
    }else{
        ant->next= p->next;
    }
    free(p);
    return true;
}
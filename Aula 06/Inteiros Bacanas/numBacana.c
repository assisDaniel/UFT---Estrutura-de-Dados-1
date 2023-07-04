#include <stdio.h>
#include <stdlib.h>
#include "numBacana.h"

struct no{
    int info;
    struct no *next;
};

struct list{
    node *inicio;
    node *fim;
};

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
    if(new!=NULL){
        new->inicio= NULL;
    }
    return new;
}

bool add(tList* lista, int info){
    node* new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
        lista->fim= new;
    }else{
        node *aux= lista->inicio;
        while(aux->next!= NULL){
            aux= aux->next;
        }
        aux->next= new;
        lista->fim= new;
    }
    return true;
}

bool listRemove(tList *lista, int info){
    node *ant= NULL;
    node *p= lista->inicio;

    while(p!=NULL && p->info!= info){
        ant= p;
        p= p->next;
    }
    if(p == NULL){
        return false;
    }
    if(ant == NULL){
        lista->inicio= p->next;
        if(p->next==NULL){
            lista->fim= NULL;
        }
    }else{
        ant->next= p->next;
            if(p->next==NULL){
                lista->fim= ant;
            }
    }
    free(p);
    return true;
}

void listPrint(tList *lista){
    node *aux= lista->inicio;
    putchar('\n');
    while(aux!=NULL){
        printf(" %d,", aux->info);
        aux= aux->next;
    }
}

int tamNum(int num){
    int x= num;
    int cont= 1;
    while(x>=10){
        x/=10;
        cont++;
    }
    return cont;
}

void separeNum(tList *lista, int num){
    int cont= tamNum(num);
    int x= num;
    for(int i=0; i<cont; i++){
        num= x%10;
        x/=10;
        add(lista, num);
    }
}

int powSum(tList *lista){
    node *aux= lista->inicio;
    int result= 0;
    while(aux!= NULL){
        result+= (aux->info * aux->info);
        aux= aux->next;
    }
    return result;
}

int oneDigit(tList *lista){
    node *aux= lista->fim;

    if(aux->info <10){
        return 1;
    }
    return 0;
}

int lastNum(tList *lista){
    node *aux= lista->fim;
    int num= aux->info;

    return num;
}
#include "orderedList.h"

struct list{
    unsigned int m;
    node* inicio;
};

struct no{
    int index;
    int *linha;     
    node *next;
};

tlist *listCreate(unsigned int m){
    tlist *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->m= m;
        new->inicio=NULL;
    }
    return new;
}

node *nodeCreate(int index, int *linha){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->index= index;
        new->linha= linha;
        new->next= NULL;
    }
    return new;
}

bool add(tlist* lista, int index, int *linha){
    node *new= nodeCreate(index, linha);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        if(new->linha[0] < lista->inicio->linha[0]){
            new->next= lista->inicio;
            lista->inicio= new;
        }else{
            node *y= lista->inicio;
            while(y->next!=NULL){
                if(y->next->linha[0] > new->linha[0]){
                    break;
                }
                y= y->next;
            }
            new->next= y->next;
            y->next= new;
        }
    }
    return true;
}

void listPrint(tlist *lista){
    node *aux= lista->inicio;
    while(aux!=NULL){
        printf("Line: %u: ", aux->index);
        for(unsigned int i=0; i<lista->m; i++){
            printf("%d,", aux->linha[i]);
        }
        putchar('\n');
        aux= aux->next;
    }
}
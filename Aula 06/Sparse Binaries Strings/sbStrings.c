#include "sbStrings.h"

struct no{
    int qty;
    int index;
    node *next;
};

struct list{
    node *inicio;
    int total;
    char ref;
};

tlist *listCreate(char ref){
    struct list *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->inicio= NULL;
        new->total= 0;
        new->ref= ref;
    }
}

node *nodeCreate(int qty, int index){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->qty= qty;
        new->index= index;
        new->next= NULL;
    }
}

void listPrint(tlist *lista){
    printf("\n%c %d", lista->ref, lista->total);
    node *aux= lista->inicio;
    while(aux!=NULL){
        printf("\n%d %d", aux->qty, aux->index);
        aux= aux->next;
    }
}

bool add(tlist* lista, int qty, int index){
    node *new= nodeCreate(qty, index);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        node* aux= lista->inicio;
        while(aux->next!=NULL){
            aux= aux->next;
        }
        aux->next= new;
    }
    lista->total++;
    return true;
}

tlist *encoder(char line[LINE_MAX]){
    char current= line[0];
    char anterior= line[0];
    tlist *lista= listCreate(current);
    int counter=1;
    int markIndex= 0;
    
    for(int i=1; i<strlen(line); i++){
        current= line[i];
        if(anterior == lista->ref && current !=lista->ref){
            add(lista, counter, markIndex);
            counter=0;
        }
        if(current==lista->ref && anterior!=lista->ref){
            markIndex= i;
            counter= 0;
        }
        anterior= current;
        counter++;
    }
    if(counter>0){
        add(lista, counter, (current != lista->ref)? -1 : markIndex);
        return lista;
    }
}


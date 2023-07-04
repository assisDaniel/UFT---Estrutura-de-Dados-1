#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#define max 10

struct pessoa{
    char nome[128], telefone[30];
};

struct list{
    int qty;
    struct pessoa data[max];
};
bool full(tList*);
bool full(tList *lista){
    return lista->qty <max;
}

tList *listCreate(){
    struct list *new= malloc(sizeof(tList));
    if(new!=NULL){
        new->qty= 0;
    }
    return new;
}
bool listAdd(tList* lista, char *nome, char *telefone){
    if(full(lista)){
        strcpy(lista->data[lista->qty].nome, nome);
        strcpy(lista->data[lista->qty].telefone, telefone);
        lista->qty++;
        return true;
    }
    return false;
}
void listPrint(tList *lista){
    for(int i=0; i< lista->qty; i++){
        printf("\nNome: %s \nTelefone: %s", lista->data[i].nome, lista->data[i].telefone);
    }
}
void listRemove(tList *lista){
    free(lista);
}

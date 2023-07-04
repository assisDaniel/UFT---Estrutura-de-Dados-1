#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

#define max 10

struct list{
    int qty;
    int data[max];
};

tList *listCreate(){
    struct list *new= malloc(sizeof(tList));
    if(new!=NULL){
        new->qty=0;
    }
    return new;
}
bool listTemVaga(tList* lista){
    return (lista->qty < max);
}
bool listAdd(tList *lista, int dados){
    if(listTemVaga(lista)){
        lista->data[lista->qty]= dados;
        lista->qty++;
        return true;
    }else{
        return false;
    }
}
void listPrint(tList* lista){
        putchar('\n');
        for(int i=0; i<lista->qty; i++){
            printf("%d ", lista->data[i]);
        }
}
void listDelete(tList *lista){
    free(lista);
}

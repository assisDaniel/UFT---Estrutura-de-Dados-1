#include "equal.h"

struct list{
    node *inicio;
    int qty;
};

struct no{
    node *next;
    int info;
};

clist *listCreate(){
    clist *new= malloc(sizeof(clist));
    if(new!=NULL){
        new->inicio=NULL;
        new->qty=0;
    }
    return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->next= NULL;
        new->info= info;
    }
    return new;
}

bool add(clist *lista, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
        lista->inicio->next= lista->inicio;
        lista->qty++;
    }else{
        node *aux= lista->inicio;
        while(aux->next!=lista->inicio){
            aux= aux->next;
        }
        aux->next= new;
        new->next= lista->inicio;
        lista->qty++;
    }
    return true;
}

bool checkEqual(clist* lista, clist* lista2){
    if(lista->qty!= lista2->qty){
        return false;
    }else{
        node *aux2= lista2->inicio;
        while(aux2->next!=lista2->inicio){
            if(lista->inicio->info == aux2->info){
                break;
            }
            aux2= aux2->next;
        }
        if(lista->inicio->info != aux2->info){
            return false;
        }else{
            node *aux= lista->inicio;
            int cont=0;
            while(aux!=lista->inicio){
                for(int i=0; i<lista->qty; i++){
                    if(aux->info == aux2->info){
                        cont++;
                    }
                    aux2= aux2->next;
                }
                aux= aux->next;
            }
            if(cont == lista->qty){
                return true;
            }
        }
    }
    return false;
}

void listPrint(clist *lista){
    node *aux= lista->inicio;
    putchar('\n');
    do{
        printf("%d%s", aux->info, (aux->next)? " -> ":"");
        aux= aux->next;
    }while(aux!= lista->inicio);
}
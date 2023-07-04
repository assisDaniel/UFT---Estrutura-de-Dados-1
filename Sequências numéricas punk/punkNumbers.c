#include "punkNumbers.h"

struct no{
    int info;
    node *next;
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
    tlist *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->inicio=NULL;
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
    }else{
        node *aux= lista->inicio;
        while(aux->next!=NULL){
            aux= aux->next;
        }
        aux->next= new;
    }
    return true;
}

bool addBegin(tlist *lista2, int info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista2->inicio!=NULL){
        new->next= lista2->inicio;
    }
    lista2->inicio= new;
    return true;
}

bool isEven(int info){
    if(info%2==0){
        return true;
    }else{
        return false;
    }
}

int checkDigits(int info){
    int cont=1;
    while(info>=10){
        info/=10;
        cont++;
    }
    return cont;
}


void separeNum(tlist* lista, int info){
    int cont= checkDigits(info);
    int x= info;
    if(cont>2){
        for(int i=0; i<2; i++){
            info= x%100;
            x/=100;
            addBegin(lista, info);
        }
    }else{
        addBegin(lista, x);
    }
}

int lastNum(tlist *lista){
    node *aux= lista->inicio;
    while(aux->next!=NULL){
        aux= aux->next;
    }
    return aux->info;
}

void listPrint(tlist *lista){
    node *aux= lista->inicio;
    putchar('\n');
    while(aux!=NULL){
        printf(" %d%s", aux->info, (aux->next)? " -> ": "");
        aux= aux->next;
    }
}

bool listRemove(tlist *lista, int info){
    node* ant= NULL;
    node* p= lista->inicio;

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

bool oneDigit(tlist* lista){
    int x= lastNum(lista);
    if(x<10){
        return true;
    }
    return false;
}

int firstpart(tlist* lista, tlist* seps){
    node *aux= seps->inicio;  
    int result=0, x;
    if(seps->inicio->next != NULL){
        if(isEven(aux->info)){
            x= aux->info;
            x/=2;
        }else{
            x= aux->info;
            x++;
        }
        
        int idk= checkDigits(lastNum(lista));
        if(idk==4){
            if(x<10){
                result= x*100;
            }else{
                result=x*10;
            }
            return result;
        }else if(idk==3){
            if(x<10){
                result= x*10;
            }else{
                result= x;
            }
            return result;
        }

    }else{
        if(isEven(aux->info)){
            x= aux->info;
            x/=2;
        }else{
            x= aux->info;
            x++;
        }
        result= x;
        return result;
    }
}
int scndpart(tlist* lista, tlist* seps){
    node *aux= seps->inicio->next;
    int result=0, x;
    if(aux!=NULL){
        if(isEven(aux->info)){
            x= aux->info;
            x/=2;
        }else{
            x=aux->info;
            x++;
        }
        result= x;
        return result;

    }else{
        return result;
    }
}
void merge(tlist* lista, tlist* seps){
    if(seps->inicio->next !=NULL){
        int x= firstpart(lista, seps);
        int y= scndpart(lista, seps);
        int info= x+y;
        add(lista, info);
    }else{
        int x= firstpart(lista, seps);
        int info= x;
        add(lista, info);
    }
}

void resolution(tlist* lista, tlist* seps, int info){
    int x= info;
    add(lista, info);

    x= lastNum(lista);
    while(x >= 10){
        separeNum(seps, x);
        merge(lista, seps);
        x= qtyNodes(seps);
        for(int i=0; i<x; i++){
            listRemove(seps, lastNum(seps));
        }
        x= lastNum(lista);
    }
    putchar('\n');
    listPrint(lista);
}

int qtyNodes(tlist *lista){
    node *aux= lista->inicio;
    if(lista->inicio->next != NULL){
        return 2;
    }else{
        return 1;
    }
}
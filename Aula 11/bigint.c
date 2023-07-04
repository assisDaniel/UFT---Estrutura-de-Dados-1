#include "bigint.h"

struct no{
    int num;
    node *next;
    node *ant;
};

struct list{
    node *inicio;
    node *fim;
};

dlist *listCreate(){
    dlist *new= malloc(sizeof(dlist));
    if(new!=NULL){
        new->inicio= NULL;
        new->fim= NULL;
    }
    return new;
}

node *nodeCreate(int num){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->num= num; 
        new->next= NULL;
        new->ant= NULL;
    }
    return new;
}

bool addBegin(dlist* lista, int num){
    node *new= nodeCreate(num);
    if(new==NULL) return false;
    if(lista->inicio ==NULL && lista->fim==NULL){
        lista->inicio= new;
        lista->fim= new;
    }else{
        new->next= lista->inicio;
        lista->inicio->ant= new;
        lista->inicio= new;
    }
    return true;
}

bool addEnd(dlist *lista, int num){
    node *new= nodeCreate(num);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL && lista->fim==NULL){
        lista->inicio= new;
        lista->fim= new;
    }else{
        new->ant= lista->fim;
        lista->fim= new;
        node *aux= lista->fim;
        aux= aux->ant;
        aux->next= lista->fim;
    }
    return true;
}

void listPrint(dlist *lista){
    node *aux= lista->inicio;
    putchar('\n');
    while(aux!=NULL){
        printf("%d", aux->num);
        aux= aux->next;
    }
}

int transform(char num){
    if(num>='0' && num<='9') return num-48;
    else return -1;
}

dlist *addTransformed(char *num){
    dlist *list= listCreate();
    for(int i=0; i<strlen(num); i++){
        int k= transform(num[i]);
        if(k>=0) addEnd(list, k);
    }
    return list;
}

dlist* sum(dlist *lista, dlist* lista2){
    dlist* result= listCreate();
    node *aux= lista->fim; node *aux2= lista2->fim;
    int carry=0;
    
    while(aux!=NULL || aux2!=NULL || carry){
        int digito1= (aux!=NULL) ? aux->num : 0;
        int digito2= (aux2!=NULL) ? aux2->num : 0;
        int somaDigitos= digito1 + digito2 + carry;

        carry= somaDigitos>9;
        addBegin(result, somaDigitos%10);
        aux= (aux!=NULL) ? aux->ant : NULL;
        aux2= (aux2!=NULL) ? aux2->ant : NULL;
    }
    return result;
}
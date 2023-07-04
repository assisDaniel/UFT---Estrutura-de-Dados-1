#include "stack.h"

struct no{
    int info;
    node *next;
};

struct pilha{
    int qty;
    node *top;
};

stack *stackCreate(){
    stack *new= calloc(1, sizeof(stack));
    return new;
}

node *nodeCreate(int info){
    node *new= calloc(1, sizeof(node));
    return new;
}

bool empty(stack *idk){
    return idk->qty==0;
}

bool spush(stack *idk, int info){
    node *new= nodeCreate(info);
    if(new!=NULL){
        new->info= info;
        new->next= idk->top;
        idk->top= new;
        idk->qty++;
        return true;
    }
    return false;
}

bool spop(stack *idk, int *info){
    if(!empty(idk)){
        node *aux= idk->top;
        *info= aux->info;
        idk->qty--;
        idk->top= aux->next;
        free(aux);
        return true;
    }
    return false;
}

bool stackHead(stack *idk, int *info){
    if(!empty(idk)){
        int topo= idk->top->info;
        *info= topo;
        return true;
    }
    return false;
}
#include "stack.h"

struct no{
    int info, qty;
    node *next;
};

struct pilha{
    node *top;
};

stack *stackCreate(){
    stack *new= malloc(sizeof(stack));
    if(new) new->top= NULL;
    return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new){
        new->qty=0;
        new->info= info;
        new->next= NULL;
    }
    return new;
}

bool empty(stack *st){
    return st->top==NULL;
}

bool spush(stack *st, int info){
    node *new= nodeCreate(info);
    if(new){
        new->next= st->top;
        st->top= new;
        new->qty++;
        return true;
    }
    return false;
}

void stackPrint(stack *st){
    node *aux= st->top;
    while(aux){
        printf("%d%s", aux->info, (aux->next)? " -- ":"");
        aux= aux->next;
    }
    putchar('\n');
}

bool isEqual(stack *st, stack *st2){
    node *aux= st->top;
    node *aux2= st2->top;

    while(aux && aux2){
        if(aux->info == aux2->info){
            aux= aux->next;
            aux2= aux2->next;
        }
        else if(aux->qty != aux2->qty) return false;
        else return false;
    }
    return true;
}

int main(void){
    stack *pi= stackCreate();
    stack *pii= stackCreate();

    for(int i=1; i<11; i++){
        spush(pi, i);
    }
    for(int i=0; i<10; i++) spush(pii, i);
    if(isEqual(pi, pii)) printf("Pilhas sao iguais.");
    else printf("Pilhas sao diferentes.");
}
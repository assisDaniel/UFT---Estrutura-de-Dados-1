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

stack *copy(stack *st){
    stack *new= st;
    return new;
}

int main(void){
    stack *pi= stackCreate();
    for(int i=1; i<11; i++) spush(pi, i);
    stack *pii= copy(pi);

    stackPrint(pi);
    stackPrint(pii);
}
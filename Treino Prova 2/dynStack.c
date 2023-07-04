#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *next;
}node;

typedef struct pilha{
    node *top;
}stack;

stack *stackCreate(){
    stack *new= malloc(sizeof(stack));
    if(new) new->top= NULL;
    return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new){
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
        return true;
    }return false;
}

bool spop(stack *st, int *info){
    if(!empty(st)){
        node *aux= st->top;
        *info= st->top->info;
        st->top= st->top->next;
        free(aux);
        return true;
    }return false;
}

void stackPrint(stack *st){
    node *aux= st->top;
    while(aux){
        printf("%d%s", aux->info, aux->next? " -- ":"");
        aux= aux->next;
    }
    putchar('\n');
}

int main(void){
    int temp;
    stack *st= stackCreate();

    for(int i=1; i<11; i++) spush(st, i);
    stackPrint(st);
    for(int i=0; i<7; i++){
        spop(st, &temp);
        printf("Removed element: %d\n", temp);
    }
}
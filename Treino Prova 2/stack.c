#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct pilha{
    int qty, data[max];
}stack;

stack *stackCreate(){
    stack* new= malloc(sizeof(stack));
    if(new) new->qty=0;
    return new;
}

bool empty(stack *st){
    return st->qty==0;
}

bool full(stack *st){
    return st->qty==max;
}

bool spush(stack* st, int info){
    if(!full(st)){
        st->data[st->qty]= info;
        st->qty++;
        return true;
    }return false;
}

bool spop(stack *st, int *info){
    if(!empty(st)){
        st->qty--;
        *info= st->data[st->qty];
        st->data[st->qty]= 0;
        return true;
    }return false;
}

void stackPrint(stack *st){
    for(int i=0; i<st->qty; i++){
        printf("%d, ", st->data[i]);
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
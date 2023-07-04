#include "stack.h"

struct no{
    int info;
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

stack* invertStack(stack *st){
    stack *new= stackCreate();
    node *aux= st->top;
    while(aux){
        spush(new, aux->info);
        aux= aux->next;
    }
    return new;
}

int main(void){
    stack *normalStack= stackCreate();
    
    for(int i=1; i<11; i++){
        spush(normalStack, i);
    }
    stack* inverted= invertStack(normalStack);
    printf("Stack principal: "); 
    stackPrint(normalStack);
    printf("Stack invertida: ");
     stackPrint(inverted);
}
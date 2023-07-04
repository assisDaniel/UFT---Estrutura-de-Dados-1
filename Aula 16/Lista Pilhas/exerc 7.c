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
    stack *new= malloc(sizeof(stack));
    if(new){
        new->top= NULL;
        new->qty=0;
    }
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
        st->qty++;
        return true;
    }
    return false;
}

bool spop(stack *st, int* info){
    if(!empty(st)){
        *info= st->top->info;
        st->qty--;
        st->top= st->top->next;
        return true;
    }return false;
}

void stackPrint(stack *st){
    node *aux= st->top;
    while(aux){
        printf("%d%s", aux->info, (aux->next)? " -- ":"");
        aux= aux->next;
    }
    putchar('\n');
}

stack *popZig(stack *par, stack *impar){
    stack *new= stackCreate();
    int soma= par->qty + impar->qty;
    int temp;
    for(int i=1; i<=soma; i++){
        if(i%2==0){
            spop(par, &temp);
            if(temp>0) spush(new, temp);
            else spop(new, &temp);
        }else{
            spop(impar, &temp);
            if(temp>0) spush(new, temp);
            else spop(new, &temp);
        }
    }
    return new;
}

int main(void){
    stack *par= stackCreate();
    stack *impar= stackCreate();
    int x;

    scanf("%d", &x);
    while(x!= 0){
        if(x%2==0) spush(par, x);
        else spush(impar, x);
        scanf("%d", &x);
    }
    stack *pilha= popZig(par, impar);
    stackPrint(par);
    stackPrint(impar);
    stackPrint(pilha);
}
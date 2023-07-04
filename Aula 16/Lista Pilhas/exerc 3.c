#include "stack.h"

struct no{
    char c[50];
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

node *nodeCreate(char* c){
    node *new= malloc(sizeof(node));
    if(new){
        for(int i=0; i<strlen(c); i++) new->c[i]= c[i];
        new->next= NULL;
    }
    return new;
}

bool empty(stack *st){
    return st->top==NULL;
}

bool spush(stack *st, char *c){
    node *new= nodeCreate(c);
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
        printf("%s ", aux->c);
        aux= aux->next;
    }
}

bool check(stack *st){
    int soma1=0, soma2=0;
    node *aux= st->top;
    while(aux){
        for(int i=0; i<strlen(aux->c); i++){
            if(aux->c[i]=='(') soma1++;
            else if(aux->c[i]==')') soma2++;
        }
        if(soma1!=soma2) return false;
        else{
            soma1=0; soma2=0;
            aux= aux->next;
        }
    }
    return true;
}

int main(void){
    stack *pi= stackCreate();
    char c[50];

    scanf("%[^\n]%*c", c);
    spush(pi, c);
    if(check(pi)) printf("Parentizacao correta\n");
    else printf("Parentizacao incorreta\n");
}
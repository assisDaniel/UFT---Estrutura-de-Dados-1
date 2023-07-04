#include "stack.h"

struct no{
    node *next;
    char m[50];
};

struct pilha{
    node* top;
};

stack *stackCreate(){
    stack *new= malloc(sizeof(stack));
    if(new){
        new->top= NULL;
    }
    return new;
}

node *nodeCreate(char *m){
    node *new= malloc(sizeof(node));
    if(new){
        new->next= NULL;
        for(int i=0; i<strlen(m); i++) new->m[i]= m[i];
    }
    return new;
}

bool spush(stack *st, char *m){
    node *new= nodeCreate(m);
    if(new){
        new->next= st->top;
        st->top= new;
        return true;
    }return false;
}

void stackPrint(stack *st){
    node *aux= st->top;
    while(aux){
        printf("%s ", aux->m);
        aux= aux->next;
    }
}

void invertSentence(stack *st, char *m){
    int size= strlen(m);
    char m2[size+1];
    for(int i=0; i<size; i++){
        m2[i]= m[size- i- 1];
    }
    m2[size]= '\0';
    spush(st, m2);
}

int main(void){
    char phrase[500];

    while(scanf("%s", phrase) == 1){
        stack *pi= stackCreate();
        invertSentence(pi, phrase);
        stackPrint(pi);
        free(pi);
    }
}
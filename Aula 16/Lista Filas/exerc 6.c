#include "queue.h"

struct no{
    int info;
    node *next;
};

struct fila{
    node *head;
    node *tail;
};

typedef struct pilha{
    node *top;
}stack;

stack *stackCreate(){
    stack *new= malloc(sizeof(stack));
    if(new) new->top= NULL;
    return new;
}
queue *queueCreate(){
    queue *new= malloc(sizeof(queue));
    if(new){
        new->head= NULL;
        new->tail= NULL;
    }return new;
}

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new){
        new->info= info;
        new->next= NULL;
    }return new;
}

bool empty(queue *q){
    return q->head== NULL;
}

bool sempty(stack *st){
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
    if(!sempty(st)){
        node *aux= st->top;
        *info= st->top->info;
        st->top= st->top->next;
        free(aux);
        return true;
    }return false;
}

bool enqueue(queue *q, int info){
    node *new= nodeCreate(info);
    if(q->head==NULL) q->head= new;
    else q->tail->next= new;
    q->tail= new;
    return true;
}

bool dequeue(queue *q, int *info){
    if(!empty(q)){
        *info= q->head->info;
        q->head= q->head->next;
        if(q->head== NULL) q->tail=NULL;
        return true;
    }return false;
}

void queuePrint(queue *q){
    node *aux= q->head;
    while(aux){
        printf("%d%s", aux->info, (aux->next)?" -- ":"");
        aux= aux->next;
    }
    putchar('\n');
}

queue *invertQueue(queue *q){
    stack *st= stackCreate();
    queue *temp= queueCreate();
    node *aux= q->head;
    int idk;
    while(aux){
        enqueue(temp, aux->info);
        aux= aux->next;
    }
    while(!empty(temp)){
        dequeue(temp, &idk);
        spush(st, idk);
    }
    free(temp);
    queue *invert= queueCreate();
    while(!sempty(st)){
        spop(st, &idk);
        enqueue(invert, idk);
    }
    return invert;
}

int main(void){
    queue *q= queueCreate();
    for(int i=1; i<11; i++) enqueue(q, i);
    queue *inverted= invertQueue(q);

    printf("Queue normal: ");   queuePrint(q);
    printf("Queue invertida: "); queuePrint(inverted);
}
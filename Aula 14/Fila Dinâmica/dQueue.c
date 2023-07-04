#include "dQueue.h"

struct no{
    int info;
    node* next;
};

struct fila{
    node *head;
    node *tail;
};

node *nodeCreate(int info){
    node *new= malloc(sizeof(node));
    if(new){
        new->info= info;
        new->next= NULL;
    }
    return new;
}

dQueue *queueCreate(){
    dQueue *new= malloc(sizeof(dQueue));
    if(new){
        new->head= NULL;
        new->tail= NULL;
    }
    return new;
}

bool empty(dQueue *q){
    return q->head==NULL;
}

bool enqueue(dQueue *q, int info){
    node *new= nodeCreate(info);
    if(q->head==NULL) q->head= new;
    else q->tail->next= new;
    q->tail= new;
    return true;
}

bool dequeue(dQueue* q, int *info){
    if(!empty(q)){
        *info= q->head->info;
        q->head= q->head->next;
        if(q->head==NULL) q->tail= NULL;
        return true;
    }
    return false;
}

void queuePrint(dQueue *q){
    node *aux= q->head;
    putchar('\n');
    while(aux!=NULL){
        printf("%d, ", aux->info);
        aux= aux->next;
    }
}
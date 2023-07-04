#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *next;
}node;

typedef struct fila{
    node *head;
    node *tail;
}queue;

queue *queueCreate(){
    queue *new= malloc(sizeof(queue));
    if(new){
        new->head= NULL;
        new->tail= NULL;
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

bool empty(queue *q){
    return q->head==NULL;
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
        node *aux= q->head;
        *info= q->head->info;
        q->head= q->head->next;
        if(q->head==NULL) q->tail=NULL;
        free(aux);
        return true;
    }return false;
}

void queuePrint(queue *q){
    node *aux= q->head;
    while(aux){
        printf("%d%s", aux->info, aux->next? " -- ":"");
        aux= aux->next;
    }
    putchar('\n');
}

int main(void){
    queue *q= queueCreate();
    int temp;

    for(int i=1; i<11; i++) enqueue(q, i);
    queuePrint(q);
    for(int i=0; i<7; i++){
        dequeue(q, &temp);
        printf("Removed element: %d\n", temp);
    }
}
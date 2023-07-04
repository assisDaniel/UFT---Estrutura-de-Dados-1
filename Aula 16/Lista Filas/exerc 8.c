#include "queue.h"

struct no{
    int info;
    node *next;
};

struct fila{
    node *head;
    node *tail;
};

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

int qtyEven(queue *q){
    node *aux= q->head;
    int qty=0;
    while(aux){
        if(aux->info%2==0) qty++;
        aux= aux->next;
    }
    return qty;
}

int main(void){
    queue *q= queueCreate();
    for(int i=1; i<11; i++) enqueue(q, i);
    int qty= qtyEven(q);
    printf("Quantidade de numeros impares: %d", qty);
}
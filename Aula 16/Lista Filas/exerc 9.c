#include "queue.h"

struct no{
    int info;
    node *next;
};

struct fila{
    int qty;
    node *head;
    node *tail;
};

queue *queueCreate(){
    queue *new= malloc(sizeof(queue));
    if(new){
        new->qty=0;
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
    q->qty++;
    return true;
}

bool dequeue(queue *q, int *info){
    if(!empty(q)){
        *info= q->head->info;
        q->head= q->head->next;
        if(q->head== NULL) q->tail=NULL;
        q->qty--;
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

queue *altenar(queue *q, queue *q2){
    queue *new= queueCreate();
    int soma= q->qty + q2->qty;
    int temp;
    node *aux= q->head; node *aux2= q2->head;
    for(int i=0; i<soma; i++){
        if(i%2==0){
            dequeue(q, &temp);
            enqueue(new, temp);
        }else{
            dequeue(q2, &temp);
            enqueue(new, temp);
        }
        aux= aux->next;
        aux2= aux2->next;
    }
    return new;
}

int main(void){
    queue *fi= queueCreate();
    queue *fii= queueCreate();
    for(int i=1; i<21; i++){
        if(i<=10) enqueue(fi, i);
        else enqueue(fii, i);
    }
    queue *alternada= altenar(fi, fii);
    queuePrint(alternada);
}
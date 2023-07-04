#include "queue.h"

struct fila{
    int head, tail, data[max];
};

queue *queueCreate(){
    queue *new=malloc(sizeof(queue));
    if(new!=NULL){
        new->head=0;
        new->tail=0;
    }
    return new;
}

bool full(queue* q){
    return q->tail - q->head==max;
}

bool empty(queue *q){
    return q->tail==q->head;
}

bool enqueue(queue *q, int info){
    if(!full(q)){
        q->data[q->tail%max]= info;
        q->tail++;
        return true;
    }
    return false;
}

bool dequeue(queue *q, int* info){
    if(!empty(q)){
        q->head++;
        *info= q->data[(q->head-1)%max];
        return true;
    }
    return false;
}

void queuePrint(queue *q){
    for(int i=q->head; i<q->tail; i++){
        printf("%d, ", q->data[i%max]);
    }
}
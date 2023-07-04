#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct fila{
    int head, tail, data[max];
}queue;

queue *queueCreate(){
    queue *new= malloc(sizeof(queue));
    if(new){
        new->head=0;
        new->tail=0;
    }
    return new;
}

bool empty(queue *q){
    return q->head==q->tail;
}

bool full(queue *q){
    return q->tail - q->head == max;
}

bool enqueue(queue *q, int info){
    if(!full(q)){
        q->data[q->tail%max]= info;
        q->tail++;
        return true;
    }return false;
}

bool dequeue(queue *q, int *info){
    if(!empty(q)){
        *info= q->data[q->head%max];
        q->data[q->head%max]= 0;
        q->head++;
        return true;
    }return false;
}

void queuePrint(queue *q){
    for(int i=q->head; i<q->tail; i++){
        printf("%d, ", q->data[i%max]);
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

#include "dQueue.h"

int main(void){
    int temp;
    dQueue* fi= queueCreate();

    for(int i=0; i<10; i++){
        enqueue(fi, i*2);
    }
    queuePrint(fi);
    for(int i=0; i<9; i++){
        dequeue(fi, &temp);
        printf("\nRemoved element: %d", temp);
    }
    queuePrint(fi);
}
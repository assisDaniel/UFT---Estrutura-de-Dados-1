#include "queue.h"

int main(void){
    int temp;
    queue* f1= queueCreate();

    for(int i=0; i<10; i++){
        enqueue(f1, i);
    }
    queuePrint(f1);
    putchar('\n');
    for(int i=0; i<9; i++){
        dequeue(f1, &temp);
        printf("Removed element: %d\n", temp);
    }
    putchar('\n');
    queuePrint(f1);
}
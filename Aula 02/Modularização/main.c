#include <stdio.h>
#include "mylib1.h"

int main(void){
    unsigned int size, temp;

    printf("\nVector's size: ");
    temp= scanf("%u", &size);

    int* v= vector_create_n_fill(size, 100);
    for(int i=0; i<size; i++){
        printf("%2d ", v[i]);
    }
}
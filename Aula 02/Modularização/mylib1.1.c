#include <stdlib.h>
#include <stdio.h>
#include "mylib1.h"

int* vector_create_n_fill(unsigned int size, unsigned int max){
    int *v= (int*)calloc(size, sizeof(int));
    if(v!=NULL){
        for(int i=0; i<size; i++){
            v[i]= rand()% max;
        }
    }
    puts("Ola, eu sou o mylib1.1");
    return v;
}

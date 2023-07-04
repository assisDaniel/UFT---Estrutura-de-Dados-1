#include <stdlib.h>
#include "mylib1.h"

int* vector_create_n_fill(unsigned int size, unsigned int max){
    int* v= (int*)malloc(sizeof(int)*size);
    if(v!=NULL){
        for(int i=0; i<size; i++){
            v[i]= rand()% max;
        }
    }
    return v;
}
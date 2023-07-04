#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillVector(int *v, unsigned int size){
    for(int i=0; i<size; i++){
        v[i]= rand() % size*2;
    }
}

void printVector(int *v, unsigned int size){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        printf("%02d ", v[i]);
    }
    putchar('\n');
}

int main(void){
    int **m;
    unsigned int size= 10;

    m= (int **)malloc(sizeof(int*)* size);
    if(m!=NULL){
        for(int i=0; i<size; i++){
            srand(time(NULL) + 1);
            m[i]= (int *)malloc(sizeof(int)* size);
            if(m==NULL){
                printf("\nProblema ao alocar o vetor num %d", i+1);
                return -1;
            }
            fillVector(m[i], size);
            printVector(m[i], size);
        }
    }else{
        puts("Nao pude alocar o vetor de ponteiros.");
    }
}
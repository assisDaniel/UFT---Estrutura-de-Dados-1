#include "tadVector.h"

struct vector{
    int qty, marked;
    int *v;
};

idk *createVector(){
    idk *sla= malloc(sizeof(idk));
    if(sla!=NULL){
        sla->qty=0;
        sla->marked= 0;
        sla->v= (int*)malloc(sizeof(int)*max);
    }
    return sla;
}

bool checkNum(idk *sla, int x){
    for(int i=0; i<sla->qty; i++){
        if(sla->v[i]==x){
            sla->marked= i;
            printf("\nNumber, %d, already exists in the vector!", x);
            return true;
        }
    }
    return false;
}
void add(idk *sla, int x){
    if(sla->qty < max){
        if(!checkNum(sla, x)){
            sla->v[sla->qty]= x;
            sla->qty++;
        }
    }else{
        printf("\nVector is full!");
    }
    
}

void removeElem(idk *sla, int x){
    if(checkNum(sla, x)){
        printf("\nElement does not exist!");
    }else{

    }
}

void printVector(idk *sla){
    printf("\nVector: [");
    for(int i=0; i<sla->qty; i++){
        printf(" %d ", sla->v[i]);
    }
    printf("]");
}
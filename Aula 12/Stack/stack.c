#include "stack.h"
#define max 10

struct pilha{
    int qty;
    int data[max];
};

stack *stackCreate(){
    stack *new= calloc(1, sizeof(stack));
    if(new!=NULL) return new;
}

bool full(stack *idk){
    return idk->qty==max;
}

bool empty(stack *idk){
    return idk->qty==0;
}

bool spush(stack *idk, int info){
    if(!full(idk)){
        idk->data[idk->qty]= info;
        idk->qty++;
        return true;
    }else return false;
}

bool spop(stack *idk, int *info){
    if(!empty(idk)){
        idk->qty--;
        *info= idk->data[idk->qty];
        idk->data[idk->qty]=0;  
        return true;
    }else return false;
}


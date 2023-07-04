#include "edCarlos.h"

struct pilha{
    int qty, data[max];
};

stack *stackCreate(){
    stack *new= malloc(sizeof(stack));
    if(new){
        new->qty=0;
    }
    return new;
}

bool full(stack *st){
    return st->qty==max;
}
bool empty(stack *st){
    return st->qty==0;
}

bool spush(stack *st, int info){
    if(full(st)){
        printf("overflow\n");
        return false;
    }else{
        st->data[st->qty]= info;
        st->qty++;
        return true;
    }
}

bool spop(stack *st){
    if(!empty(st)){
        st->qty--;
        st->data[st->qty]=0;
        return true;
    }
    return false;
}

void stackPrint(stack *st){
    for(int i=0; i<st->qty; i++){
        printf("%d, ", st->data[i]);
    }
    putchar('\n');
}

// void transfer(stack *st, int info){
//     stack *st2= stackCreate();
//     int aux= st->qty;
//     int cont=0;

//     while(st->data[aux-1]!= info){
//         spush(st2, st->data[aux-1]);
//         spop(st);
//         aux--;
//         if(st->data[aux-1]== info){
//             spush(st2, st->data[aux-1]);
//             spop(st);
//             break;
//         }
//         cont++;
//     }
//     stackPrint(st2);
//     spop(st2);
//     for(int i=cont; i>=0; i--){
//         spush(st, st2->data[i]);
//         spop(st2);
//     }
// }
void transfer(stack *st, int info){
    stack *st2= stackCreate();
    int id = -1, aux= st->qty, lps= 0;
    for(int i=0; i<st->qty; i++){
        if(info== st->data[i]){
            id= st->data[i];
            break;
        }
    }
    if(id== -1) printf("underflow");
    else{
        while(!empty(st)){
            spush(st2, st->data[aux-1]);
            spop(st);
            aux--;
            if(id== st2->data[lps]) break;
            lps++;
        }
        stackPrint(st2);
        spop(st2);
        for(int i=0; i<st2->qty; i++){
            spush(st, st2->data[i]);
            spop(st2);
        }
    }
}
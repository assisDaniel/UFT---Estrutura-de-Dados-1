#include "matrix.h"

struct no{
    node *next;
    int **m;
};

struct list{
    node* inicio;
};

tlist *listCreate(){
    tlist *new= malloc(sizeof(tlist));
    if(new!=NULL){
        new->inicio= NULL;
    }
    return new;
}

node *nodeCreate(int **m){
    node *new= malloc(sizeof(node));
    if(new!=NULL){
        new->next=NULL;
        new->m= m;
    }
    return new;
}

bool add(tlist *lista, int **info){
    node *new= nodeCreate(info);
    if(new==NULL){
        return false;
    }
    if(lista->inicio==NULL){
        lista->inicio= new;
    }else{
        node *aux= lista->inicio;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next= new;
    }
    return true;
}

void mPrint(tlist *lista, int row, int col){
    node *aux= lista->inicio;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%02d, ", aux->m[i][j]);
        }
        putchar('\n');
    }
}

// void printTransp(tlist *lista, int **m, int row, int col){
//     node *aux= lista->inicio;

//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             m[j][i]= aux->m[i][j];
//         }
//     }
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             printf("%d, ", m[j][i]);
//         }
//         putchar('\n');
//     }
// }
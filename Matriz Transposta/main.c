#include "matrix.h"

int main(void){
    tlist *li= listCreate();
    tlist *transposta= listCreate();

    int n, m;
    scanf("%d%d", &n, &m);

    int **matrix;
    int **mTransp;

    matrix= (int**)malloc(sizeof(int*)*n);
    if(matrix!=NULL){
        for(int i=0; i<m; i++){
            matrix[i]=(int*)malloc(sizeof(int)*m);
        }
    }

    mTransp= (int**)malloc(sizeof(int*)*n);
    if(mTransp!=NULL){
        for(int i=0; i<m; i++){
            mTransp[i]= (int*)malloc(sizeof(int)*m);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
            scanf("%d", &mTransp[j][i]);
        }
    }
    add(li, matrix);
    add(transposta, mTransp);
    
    printf("Matrix Principal:\n");
    mPrint(li, n, m);
    printf("Matrix Transposta:\n");
    mPrint(transposta, n, m);
}
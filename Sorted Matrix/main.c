#include "orderedList.h"

int main(void){
    unsigned int n, m;
    scanf("%u %u", &n, &m);

    int matrix[n][m];
    tlist *li= listCreate(m);

    for(unsigned int i=0; i<n; i++){
        for(unsigned int j=0; j<m; j++){
            scanf("%d ", &matrix[i][j]);
        }
        add(li, i+1, matrix[i]);
    }
    listPrint(li);
}
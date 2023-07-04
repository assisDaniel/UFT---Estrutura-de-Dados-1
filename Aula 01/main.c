#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    unsigned int size;
    float* v;

    scanf("%d ", &size);

    v= (float*)malloc(size* sizeof(float));
    if(v!= NULL){
        for(int i=0; i<size; i++){
            scanf("%f ", &v[i]);
        }
        for(int i=0; i<size; i++){
            printf("%.1f ", pow(v[i], 2));
        }
    }
}
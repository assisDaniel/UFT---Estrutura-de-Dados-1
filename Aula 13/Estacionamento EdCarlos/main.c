#include "edCarlos.h"

int main(void){
    stack *pi= stackCreate();
    char opt;
    int info;
    
    scanf("%c %d", &opt, &info);
    while(opt != '0'){
        switch(opt){
            case 'i':
            spush(pi, info);
            break;

            case 'r':
            transfer(pi, info);
            break;
        }
        scanf("%c %d", &opt, &info);
    }
}
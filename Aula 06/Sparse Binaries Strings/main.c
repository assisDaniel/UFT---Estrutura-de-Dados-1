#include "sbStrings.h"

tlist *run_encoder(){
    char line[LINE_MAX];
    fgets(line, 10000, stdin);
    puts(line);
    tlist *lista= encoder(line); 
    listPrint(lista);
    return lista;
}

char *run_decoder(){
    return NULL;
}


int main(void){
    char comando;
    comando= getchar();
    getchar();

    switch(comando){
        case 'c':
            run_encoder();
            break;

        case 'd':
            run_decoder();
            break;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void addAgendaUI(tList *agenda){
    char nome[128], telefone[30];

    printf("\nDigite seu nome: ");
    scanf("%[^\n]", nome);
    scanf("%*c"); //limpa o buffer.
    printf("\nDigite o seu telefone: ");
    scanf("%[^\n]", telefone);

    listAdd(agenda, nome, telefone);
}
int menuUI(){
    int opt;
    printf("\n\tAGENDA: \n");
    puts("Digite 0 para fechar o programa.");
    puts("Digite 1 para inserir um elemento.");
    puts("Digite 2 para printar a agenda.");
    printf("Opcao: ");
    scanf("%d", &opt);

    scanf("%*c");

    return opt;
}

int main(void){
    tList *agenda= listCreate();
    int opt= 1;
    while(opt!=0){
        opt= menuUI();
        switch(opt){
            case 0:
            printf("\nBye!");
            break;
            
            case 1:
            addAgendaUI(agenda);    
            break;

            case 2:
            listPrint(agenda);
            break;

            default:
            printf("\n Opcao invalida!");
        }
    }
}
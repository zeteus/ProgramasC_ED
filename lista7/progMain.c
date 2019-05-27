/*
 *  LISTA EXTRA REFERENTE A PILHA
 */

#include <stdio.h>
#include <stdlib.h>
#include "progCalculadora.h"

int main(){
    int leitura;
    tPilha *pilha = criaPilha();
    
    printf("DIGITE AQUI AS OPERACOES\n>>> ");
    scanf("%d", &leitura);
    while(leitura != -1){
        switch(leitura){
            case 43:
                add(pilha);
                printf("soma\n");
                break;
            case 45:
                sub(pilha);
                printf("subt\n");
                break;
            case 42:
                mult(pilha);
                printf("mult\n");
                break;
            case 47:
                divisao(pilha);
                printf("divide\n");
                break;
            default:
                
                push(leitura, pilha);
                printf("empilha\n");
                break;
        }
        scanf("%d", &leitura);
        printf("leit - %d\n", leitura);
    }
/*
    push(4, pilha);
    push(2, pilha);
    push(5, pilha);
    push(10, pilha);
    add(pilha);
    push(1, pilha);
    push(3, pilha);
    mult(pilha);
    divisao(pilha);
    sub(pilha);
    add(pilha);*/
    imprimeResultado(pilha);
    destroiPilha(pilha);
    return 0;
}
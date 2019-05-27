#include <stdio.h>
#include <stdlib.h>
#include "progCalculadora.h"

/*
    OBJETIVO: Cria uma pilha e retorna a mesma
    IMPUTS: Nenhum
    OUTPUTS: Ponteiro pra Pilha
    PRE COND.: Nenhuma
    POS COND.: Pilha devidamente alocada
*/
tPilha* criaPilha(){
    tPilha *p = (tPilha*) malloc(sizeof(tPilha));
    p -> Topo = NULL;
    return p;
}

/*
    OBJETIVO: Verifica se a pilha eh vazia
    IMPUTS: Ponteiro do tipo tPilha
    OUTPUTS: Inteiro indicando 1 para True e 0 para False
    PRE COND.: Nenhum
    POS COND.: Verificacao feita
*/
int pilhaVazia(tPilha *p){
    if(p -> Topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/*
    OBJETIVO: Empilha uma Celula
    IMPUTS: Uma variavel inteira 'v' e um ponteiro do tipo tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Valor empilhado
*/
void push(float v, tPilha *p){    
    tCelula *aux = (tCelula*) malloc(sizeof(tCelula));
    aux -> Valor = v;
    aux -> Proximo = p -> Topo;
    p -> Topo = aux;
}

/*
    OBJETIVO: Desempilha uma celula
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Celula desempilhada
*/
void pop(tPilha *p){
    if(pilhaVazia(p)){
        printf("\nPILHA VAZIA\n");
    }else{
        tCelula *aux = p -> Topo;
        p -> Topo = aux -> Proximo;
        free(aux);
    }
}

/*
    OBJETIVO: Soma os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas somada e topo - 1
*/
void add(tPilha *p){
    if(p -> Topo == NULL || p -> Topo -> Proximo == NULL){
        printf("\nNAO FOI POSSIVEL FAZER A SOMA\n");
    }else{
        float soma;
        soma = p -> Topo -> Valor + p -> Topo -> Proximo -> Valor;
        p -> Topo -> Proximo -> Valor = soma;
        pop(p);
    }
}

/*
    OBJETIVO: Subtrai os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas subtraidas e topo - 1
*/
void sub(tPilha *p){
    if(p -> Topo == NULL || p -> Topo -> Proximo == NULL){
        printf("\nNAO FOI POSSIVEL FAZER A SUBTRACAO\n");
    }else{
        float sub;
        sub = p -> Topo -> Valor - p -> Topo -> Proximo -> Valor;
        p -> Topo -> Proximo -> Valor = sub;
        pop(p);
    }
}

/*
    OBJETIVO: Multiplica os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas multiplicadas e topo - 1
*/
void mult(tPilha *p){
    if(p -> Topo == NULL || p -> Topo -> Proximo == NULL){
        printf("\nNAO FOI POSSIVEL FAZER A MULTIPLICACAO\n");
    }else{
        float mult;
        mult = p -> Topo -> Valor * p -> Topo -> Proximo -> Valor;
        p -> Topo -> Proximo -> Valor = mult;
        pop(p);
    }
}

/*
    OBJETIVO: Divide os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas divididas e topo - 1
*/
void divisao(tPilha *p){
    if(p -> Topo == NULL || p -> Topo -> Proximo == NULL){
        printf("\nNAO FOI POSSIVEL FAZER A DIVISAO\n");
    }else{
        float divisao;
        if(p -> Topo -> Proximo -> Valor == 0){
            printf("\nVOCE ESTA TENTANDO DIVIDIR POR ZERO, TEM CTZ DISSO???\n");
        }else{
            divisao = p -> Topo -> Valor / p -> Topo -> Proximo -> Valor;
            p -> Topo -> Proximo -> Valor = divisao;
        }
        pop(p);
    }
}

/*
    OBJETIVO: Imprime o topo da pilha, Suposto resultado
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Nada alterado
*/
void imprimeResultado(tPilha *p){
    printf("\nValor: %.2f\n", p -> Topo -> Valor);
}

/*
    OBJETIVO: Destroi a pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Pilha desalocada da memoria
*/
void destroiPilha(tPilha *p){
    while(p -> Topo != NULL){
        pop(p);
    }
    free(p);
}
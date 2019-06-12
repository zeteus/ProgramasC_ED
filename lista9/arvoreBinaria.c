#include "ArvoreBinaria.h"
#include "stdio.h"
#include "stdlib.h"

/**
Contem um inteiro e dois apontadores (esquerda/direita)
*/
typedef struct tNO{
    int num;
    struct tNO *pEsq, *pDir;
}NO;

/**
Inicializa a árvore e deixa a raiz NULL
retorna: Raiz alocada e apontada para NULL
*/
ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    // raiz -> pEsq = NULL;
    // raiz -> pDir = NULL;
    *raiz = NULL;

    return raiz;
}

/**
Inicializa um NO com sua Esq e Dir igual a NULL
retorna: No criado
*/
ArvBin cria_NO(int valor){
    ArvBin noAux =(ArvBin) malloc(sizeof(NO));
    noAux -> pEsq = NULL;
    noAux -> pDir = NULL;
    noAux -> num = valor;
    
    return noAux;
}

/**
Insere 'valor' na árvore utilizando a regra que o filho esquerdo é menor que a raiz que é menor o filho direito.

Retorna: 1 em caso de sucesso. 
*/
int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    if(estaVazia_ArvBin(*raiz)){
        *raiz = cria_NO(valor);
        return 1;
    }

    if((*raiz) -> num > valor) return insere_ArvBin(&(*raiz) -> pEsq, valor);
    if((*raiz) -> num < valor) return insere_ArvBin(&(*raiz) -> pDir, valor);
    
    return 0;
}

/**
Pesquisa um valor a partir da árvore raiz
retorna 1 se encontrar o valor e 0 caso não encontre
*/
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(estaVazia_ArvBin(*raiz)){
        return 0;
    }
    if((*raiz) -> num > valor) return consulta_ArvBin(&(*raiz) -> pEsq, valor);
    if((*raiz) -> num < valor) return consulta_ArvBin(&(*raiz) -> pDir, valor);
    return (*raiz) -> num;
}

/**
Verifica se a árvore está vazia
*/
int estaVazia_ArvBin(ArvBin raiz){
    if(raiz == NULL)
        return 1;
    else{
        return 0;
    }
}

/* 
Conta o número de nós não-folha de uma árvore binária 
retorna: Numero de nós não folha
*/
int totalNaoFolha_ArvBin(ArvBin *raiz){
    if(estaVazia_ArvBin(*raiz)) return 0;
    return totalNO_ArvBin(raiz) - totalFolha_ArvBin(raiz);
}

/** 
Conta o número de folhas de uma árvore binária.
retorna: Numero de nós folhas
*/
int totalFolha_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    
    if(estaVazia_ArvBin(*raiz)) return 0;
    if(((*raiz) -> pEsq == NULL) && ((*raiz) -> pDir == NULL)){
        return 1;
    }else{
        return totalFolha_ArvBin(&(*raiz) -> pEsq) + totalFolha_ArvBin(&(*raiz) -> pDir);
    }
}

/*conta o número de nós de uma árvore binária. */
int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    
    if(estaVazia_ArvBin(*raiz)) return 0;

    return totalNO_ArvBin(&(*raiz) -> pEsq) + 1 + totalNO_ArvBin(&(*raiz) -> pDir);
}

/** Imprime em pre-ordem */ 
void preOrdem_ArvBin(ArvBin *raiz){
    if(estaVazia_ArvBin(*raiz)) return;
    if((*raiz) == NULL) return;
    printf("%d\n", (*raiz) -> num);
    preOrdem_ArvBin(&(*raiz) -> pEsq);
    preOrdem_ArvBin(&(*raiz) -> pDir);
}

/** Imprime em-ordem */ 
void emOrdem_ArvBin(ArvBin *raiz){
    if(estaVazia_ArvBin(*raiz)) return;
    if((*raiz) == NULL) return;
    preOrdem_ArvBin(&(*raiz) -> pEsq);
    printf("%d\n", (*raiz) -> num);
    preOrdem_ArvBin(&(*raiz) -> pDir);
}

/** Imprime em pós-ordem */ 
void posOrdem_ArvBin(ArvBin *raiz){
    if(estaVazia_ArvBin(*raiz)) return;
    if((*raiz) == NULL) return;
    preOrdem_ArvBin(&(*raiz) -> pEsq);
    preOrdem_ArvBin(&(*raiz) -> pDir);
    printf("%d\n", (*raiz) -> num);
}

/**
Libera um NO da memória
*/
void libera_secretaco(ArvBin *raiz){
    if(!estaVazia_ArvBin(*raiz)){
        if(!(*raiz) -> pEsq == NULL){
        libera_ArvBin(&(*raiz) -> pEsq);
        }
        if(!(*raiz) -> pEsq == NULL){
        libera_ArvBin(&(*raiz) -> pDir);
        }
    }
    free(*raiz);
}
/**
Libera a árvore binária da memória
*/
void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;
    
    libera_secretaco(raiz);

    // free(raiz);
}


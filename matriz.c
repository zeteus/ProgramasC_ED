#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz {
    int nLinhas, nColunas;
    int** mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat = (Matriz *) malloc(sizeof(Matriz));
    mat->nLinhas = nlinhas;
    mat->nColunas = ncolunas;
    mat->mat = (int **) malloc(nlinhas * sizeof(int*));

    for(int i = 0; i < nlinhas; i++){
        mat->mat[i] = (int *) malloc(ncolunas * sizeof(int));
    }

    return mat;
}

/*Verifica se o elemento mat esta definido e verifica se as posicoes sao validas
* inputs: a matriz, a linha, a coluna
* output: 1 para esta definida e 0 para nao esta definida ou as posicoes sejam invalidas
* pre-condicao: nenhuma
* pos-condicao: mat verificado
*/
int matDefinida(Matriz* mat){
    if(mat != NULL){
        if(mat->mat != NULL){
            if(mat->mat[0] != NULL){
                return 1;
            } else{
                printf("Algo errado ae fera!!\n");
            }
        }else{
            printf("Algo errado ae fera!!\n");
        }
    } else{
        printf("Algo errado ae fera!!\n");
    }

    return 0;
}
/*Modifica o elemento [linha][coluna] da matriz mat
* inputs: a matriz, a linha, a coluna, e o novo elemento
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos na matriz
* pos-condicao: elemento [linha][coluna] da matriz modificado
*/
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(matDefinida(mat))
        if(mat->nLinhas >= linha && mat->nColunas >= coluna)
            mat->mat[linha][coluna] = elem;
        else {
            printf("Esta posicao esta fora da matriz!!\n");
            EXIT_FAILURE;
        }
}

/*Retorna o elemento mat[linha][coluna]
* inputs: a matriz, a linha e a coluna
* output: elemento mat[linha][coluna]
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos na matriz
* pos-condicao: mat n�o � modificada
*/
int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(matDefinida(mat)) 
        if(mat->nLinhas >= linha && mat->nColunas >= coluna)
            return mat->mat[linha][coluna];
        else {
            printf("Esta posicao esta fora da matriz!!\n");
            EXIT_FAILURE;
        }
}

/*Retorna o n�mero de colunas da matriz mat
* inputs: a matriz
* output: o n�mero de colunas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNColunas (Matriz* mat){
    if(matDefinida(mat))
        return mat->nColunas;
    else
        EXIT_FAILURE;
}

int recuperaNLinhas (Matriz* mat){
    if(matDefinida(mat))
        return mat->nLinhas;
    else
        EXIT_FAILURE;
}

Matriz* transposta (Matriz* mat){

    return NULL;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){

    return NULL;
}

void imprimeMatriz(Matriz* mat){

}

void destroiMatriz(Matriz* mat){

}

void giraMatriz(Matriz* mat){

}

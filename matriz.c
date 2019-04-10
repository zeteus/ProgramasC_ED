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

/*Retorna o n�mero de linhas da matriz mat
* inputs: a matriz
* output: o n�mero de linhas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNLinhas (Matriz* mat){
    if(matDefinida(mat))
        return mat->nLinhas;
    else
        EXIT_FAILURE;
}

/*Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada e matriz transposta existe
*/
Matriz* transposta (Matriz* mat){
    Matriz* mTransposta;

    mTransposta = inicializaMatriz(mat->nColunas, mat->nLinhas);

    if(matDefinida(mat)){
        for(int i = 0; i <= mat->nLinhas; i++){
            for(int j = mat->nColunas - 1; j >= 0; j--){
                mTransposta->mat[i][j] = mat->mat[j][i];
            }
        }
    } else{
        EXIT_FAILURE;
    }

    return mTransposta;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
* inputs: as matrizes mat1 e mat2
* output: a matriz multiplica��o
* pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 
* correponde ao numero de linhas de mat2 
* pos-condicao: mat1 e mat2 n�o s�o modificadas e a matriz multiplicacao existe
*/
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if((matDefinida(mat1) != 1) || (matDefinida(mat2) != 1) || mat1->nColunas != mat2->nLinhas)
        EXIT_FAILURE;
    else
        Matriz *matMult = inicializaMatriz(mat1->nLinhas, mat2->nColunas);
        
        for(int i = 0; i < mat1->nLinhas, i ++){
            for(int j = 0; j < mat2->nColunas, i++){

                matMult->mat[i][j] = 0;
                for(int k = 0; k < mat1->nColunas; k++){
                    matMult->mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
                }
            }
        }

        return matMult;
}

/*Imprime a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: nenhuma
*/
void imprimeMatriz(Matriz* mat){
    if(matDefinida(mat)){
        for(int i = 0; i < mat->nLinhas; i++){
            for(int j = 0; j < mat->nColunas; j++){
                printf("[%d]", mat->mat[i][j]);
            }
            printf("\n");
        }
    } else{
        EXIT_FAILURE;
    }
}

/*Libera mem�ria alocada para a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: toda a mem�ria alocada para matriz foi liberada
*/
void destroiMatriz(Matriz* mat){
    if(matDefinida(mat)){
        for(int i = 0; i <= mat->nColunas; i++){
            free(mat->mat[i]);
        }
        
        free(mat->mat);
        free(mat);
    } else{
        EXIT_FAILURE;
    }
}

/*  BONUS
 *
 * Rotaciona os valores da matriz NxN em 90� (como se fosse uma imagem)
 * A rota��o deve ocorrer localmente, isto �, sem uso de matrizes auxiliares
* inputs: a matriz
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos e iguais
* pos-condicao: mat � rotacionada 90�
*/
void giraMatriz(Matriz* mat){

}

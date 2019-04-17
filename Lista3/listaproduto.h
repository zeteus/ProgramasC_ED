#ifndef LISTAPROD_H_
#define LISTAPROD_H_

#include <stdio.h>
#include <stdlib.h>
#define MAX     100
#define INICIO  1

typedef int Posicao;

typedef struct {
int codigo;
char nome[30];
float preco;
int qtd;
} tProduto;

typedef struct {
    tProduto prod[MAX];
    Posicao Primeiro, Ultimo;
} tLista;
/*--------------------------------------------------------*/
/*_________Funcoes para manipulacao dos produtos__________*/
void criaProduto(tProduto* p);
/*--------------------------------------------------------*/



/*--------------------------------------------------------*/
/*_________Funcoes para manipulacao de listas_____________*/

/*Faz a lista se tornar vazia*/
void FazVazia(tLista *l); // ok

/*Verifica se a lista esta vazia*/
int Vazia(tLista l); // ok

/* Insere x apos o ultimo elemento da lista */
void Insere(tProduto p, tLista *l);

// /*Opcao que nao modifica o lista.h */
// void Retira(Posicao p, tLista *l, tProduto *p);

/*Imprime a lista*/
void ImprimeLista(tLista l);

/*Quantidade de elementos na lista*/
int Quantidade(tLista l);

// /*De acordo com o codigo do produto retorna o mesmo*/
// tProduto buscacodigo(tLista *l, int cod);
/*--------------------------------------------------------*/

#endif /*LISTAPROD_H_*/

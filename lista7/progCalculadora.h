#ifndef _PROG_CALCULADORA_
#define _PROG_CALCULADORA_

/*            *
 * ESTRUTURAS *
 *            */

/* ESTRUTURA DE CELULA DA PILHA */
typedef struct celula{
    float Valor;
    struct celula *Proximo;
}tCelula;

/* ESTRUTURA DA PILHA */
typedef struct pilha{
    tCelula *Topo;
}tPilha;

/*
    OBJETIVO: Cria uma pilha e retorna a mesma
    IMPUTS: Nenhum
    OUTPUTS: Ponteiro pra Pilha
    PRE COND.: Nenhuma
    POS COND.: Pilha devidamente alocada
*/
tPilha* criaPilha();

/*
    OBJETIVO: Verifica se a pilha eh vazia
    IMPUTS: Ponteiro do tipo tPilha
    OUTPUTS: Inteiro indicando 1 para True e 0 para False
    PRE COND.: Nenhum
    POS COND.: Verificacao feita
*/
int pilhaVazia(tPilha *p);

/*
    OBJETIVO: Empilha uma Celula
    IMPUTS: Uma variavel inteira 'v' e um ponteiro do tipo tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Valor empilhado
*/
void push(float v, tPilha *p);

/*
    OBJETIVO: Desempilha uma celula
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Celula desempilhada
*/
void pop(tPilha *p);

/*
    OBJETIVO: Soma os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas somada e topo - 1
*/
void add(tPilha *p);

/*
    OBJETIVO: Subtrai os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas subtraidas e topo - 1
*/
void sub(tPilha *p);

/*
    OBJETIVO: Multiplica os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas multiplicadas e topo - 1
*/
void mult(tPilha *p);

/*
    OBJETIVO: Divide os dois primeiros valores da pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Duas primeiras celulas divididas e topo - 1
*/
void divisao(tPilha *p);

/*
    OBJETIVO: Imprime os valores de uma pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Nada alterado
*/
void imprimeResultado(tPilha *p);

/*
    OBJETIVO: Destroi a pilha
    IMPUTS: um ponteiro tPilha 'p' para pilha
    OUTPUTS: Nenhum
    PRE COND.: Pilha existente
    POS COND.: Pilha desalocada da memoria
*/
void destroiPilha(tPilha *p);

#endif
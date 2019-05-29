#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"
#include "fila.h"

/*Tipo que define a fila (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Usar como base o TAD Pilha (pilha.h) - n�o usar outra estrutura de dados
  */
typedef struct fila{
    Pilha* pMain;
    Pilha* pAux;
} Fila;

/*Cria uma fila vazia, usando pilha
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
Fila* cria_fila(void){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f -> pMain = cria_pilha();
    f -> pAux = cria_pilha();
    return f;
}

/*Insere uma pessoa na fila de Pessoas (lembre-se, fila e' FIFO). Imprime mensagem de erro caso a fila esteja cheia.
* inputs: pessoa a ser inserida na fila (do tipo pessoa) e a fila
* output: nenhum 
* pre-condicao: pessoa e fila n�o s�o nulos
* pos-condicao: fila cont�m a pessoa inserida na ultima posi��o*/
void insere (Pessoa* pessoa, Fila* f){
    push(pessoa, f -> pMain);
}

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da Fila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila n�o � nula
* pos-condicao: fila n�o cont�m a pessoa que estava na primeira posicao */
Pessoa* retira (Fila* f){
    while(!vazia_pilha(f -> pMain)){
        push(pop(f -> pMain), f -> pAux);
    }
    
    Pessoa *p = pop(f -> pAux);

    while(!vazia_pilha(f -> pAux)){
        push(pop(f -> pAux), f -> pMain);
    }

    return p;
}


/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila n�o � nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprime_fila (Fila* f){
    while(!vazia_pilha(f -> pMain)){
        push(pop(f -> pMain), f -> pAux);
    }
    
    imprime_pilha(f -> pAux);

    while(!vazia_pilha(f -> pAux)){
        push(pop(f -> pAux), f -> pMain);
    }
}


/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila n�o � nula
* pos-condicao: nenhuma
*/
int Vazia_fila (Fila* f){
    return vazia_pilha(f -> pMain);
}


/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
    while(!vazia_pilha(f -> pMain)){
        push(pop(f -> pMain), f -> pAux);
    }
    while(!vazia_pilha(f -> pAux)){
        Pessoa *pAvalia = pop(f -> pAux);
        if(retorna_idade(pAvalia) > 60)
            push(pAvalia, f_maiores -> pMain);
        else
            push(pAvalia, f_menores -> pMain);
    }
}

/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
Fila* destroi_fila (Fila* f){
    f -> pAux = destroi_pilha(f -> pAux);
    f -> pMain = destroi_pilha(f -> pMain);

    return NULL;
}

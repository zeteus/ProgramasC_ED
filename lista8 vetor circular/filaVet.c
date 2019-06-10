#include "stdio.h"
#include "stdlib.h"
#include "filaVet.h"
#include "pilha.c"
#define MaxTam 10

/*Tipo que define a fila (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Usar como base o TAD Pilha (pilha.h) - n�o usar outra estrutura de dados
  */
typedef struct fila{
    Pessoa *pessoa[MaxTam];
    int first, last;
    int quant;
} Fila;

/*Cria uma fila vazia, usando pilha
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
Fila* cria_fila(void){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f -> first = 0;
    f -> last = 0;
    f -> quant = 0;
    return f;
}


/*Insere uma pessoa na fila de Pessoas (lembre-se, fila e' FIFO). Imprime mensagem de erro caso a fila esteja cheia.
* inputs: pessoa a ser inserida na fila (do tipo pessoa) e a fila
* output: nenhum 
* pre-condicao: pessoa e fila n�o s�o nulos
* pos-condicao: fila cont�m a pessoa inserida na ultima posi��o*/
void insere (Pessoa* pessoa, Fila* f){
    if(f == NULL)
        return;
    else{
        if(f -> quant == MaxTam){
            // printf("\nFILA CHEIA\n");
            return;
        } else{
        f -> pessoa[f -> last] = pessoa;
        f -> last = (f -> last + 1) % MaxTam;
        f -> quant++;
        }
    }
}

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da Fila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila n�o � nula
* pos-condicao: fila n�o cont�m a pessoa que estava na primeira posicao */
Pessoa* retira (Fila* f){
    if(f == NULL)
        return NULL;
    else{
        if(Vazia_fila(f)){
            printf("\nFILA VAZIA\n");
            return NULL;
        }else{
        Pessoa* pAux = f -> pessoa[f -> first];
        f -> first = (f -> first + 1) % MaxTam;
        f -> quant--;
        return pAux;
        }
    }
}

/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila n�o � nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprime_fila (Fila* f){
    int i = f -> first;
    int j = 0;
    for(j = 0; j < f -> quant; j++){
        printf ("Pessoa: %s\n", f -> pessoa[i] -> nome);
		printf ("Idade: %d\n", f -> pessoa[i] -> idade);
		printf ("Endereco: %s\n", f -> pessoa[i] ->end);
		printf ("\n");

        i = (i + 1) % MaxTam;
    }
}


/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila n�o � nula
* pos-condicao: nenhuma
*/
int Vazia_fila(Fila* f){
    return (f -> quant == 0);
}


/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
    while(!Vazia_fila(f)){
        Pessoa *pAvalia = retira(f);
        if(retorna_idade(pAvalia) > 60)
            insere(pAvalia, f_maiores);
        else
            insere(pAvalia, f_menores);
    }
}

/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
Fila* destroi_fila (Fila* f){
    Pessoa * p;

    while(!Vazia_fila(f)){
        p = retira(f);

        free(p -> nome);
        free(p -> end);
        free(p);
    }
    free(f);

    return NULL;
}

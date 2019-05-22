#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
typedef struct pessoa{
    char *nome;
    char *endereco;
    int idade;
}Pessoa;


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
typedef struct pilha{
    Pessoa *vetPessoas[10];
    int Topo;
} Pilha;


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
Pilha* cria_pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p -> Topo = 0;
    return p;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* pilha){
    if(pilha -> Topo == 10)
    {
        printf("Esta pilha esta cheia!!");
        return;
    }
    else
    {
        pilha -> vetPessoas[pilha -> Topo] = pessoa;
        pilha -> Topo ++;
    }
}


/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
Pessoa* pop(Pilha* pilha){
    if(pilha -> Topo == 0)
    {
        printf("Esta pilha esta vazia!!");
        return NULL;
    }
    else
    {
        pilha -> Topo = pilha -> Topo - 1;
        return pilha -> vetPessoas[pilha -> Topo];
    }
}


/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* pilha){
    // if(pilha -> Topo == 0){
    //     return;
    // }
    for(int i = 0; i < pilha -> Topo; i++){
        imprime_pessoa(pilha -> vetPessoas[i]);
        printf("============================\n");
    }
}

/*Imprime uma pessoa da pilha
 * inputs: uma pessoa
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: Pessoa permanece inalterada
 */
void imprime_pessoa(Pessoa *p){
    printf("______________________________\n");
    printf("Nome: %s\n", p -> nome);
    printf("Idade: %d\n", p -> idade);
    printf("Endereco: %s\n", p -> endereco);
}

/*Libera a memoria ocupada pela pessoa
* inputs: uma pessoa
* output: NULL
* pre-condicao: Pessoa nao nula
* pos-condicao: Toda memoria eh liberada
*/
void destroi_pessoa(Pessoa* p){
    free(p -> nome);
    free(p -> endereco);
    free(p);
}

/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* pilha){
    for(int i = 0; i < pilha -> Topo; i++){
        destroi_pessoa(pilha -> vetPessoas[i]);
    }
    free(pilha);

    return NULL;
}


/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){
    // aloca e atribui o nome da pessoa
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    p -> nome = (char*) malloc(sizeof(char) * (strlen (nome) + 1));
    strcpy(p -> nome, nome);
    
    // atribui a idade da pessoa
    p -> idade = idade;

    // aloca e atribui o endereco da pessoa
    p -> endereco = (char*) malloc(sizeof(char) * (strlen (endereco) + 1));
    strcpy(p -> endereco, endereco);

    return p;
}
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

#define I_ 1;
#define M_ 0;

/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet* cria (){
    ListaHet *Lista = (ListaHet*) malloc(sizeof(ListaHet));
    Lista -> Prox = NULL;
    return Lista;
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endere�o da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id){
    if(nome == NULL) return NULL;

    Cliente *pessoa = (Cliente*) malloc(sizeof(Cliente));
    
    char* pessoa -> nome = (char*) malloc(sizeof(char)  + 1);
    strcpy(pessoa -> nome, nome);
    pessoa -> id = id;
    return pessoa;
}

/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel 
* output: Endere�o da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor){
    Movel* veiculo = (Movel*) malloc(sizeof(Movel));

    veiculo -> placa = placa;
    veiculo -> ano = ano;
    veiculo -> valor = valor;
    return veiculo;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endere�o da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor){
    Imovel* home = (Imovel*) malloc(sizeof(Imovel));;

    home -> id = id;
    home -> ano = ano;
    home -> valor = valor;
    return home;
}

/*Insere um item (do tipo Movel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
    ListaHet* Celula = cria();
    
    if(lista == NULL)
    {
        return Celula;
    }
    else
    {

    }
    return Lista;
}

/*Insere um item (do tipo Imovel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
    
    return Lista;
}


/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista){

}

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
    return Lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
    return 0;
}
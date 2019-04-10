#include "listaproduto.h"

int main(){
    tProduto prod;
    tLista lista;

    prod.codigo = 15;
    prod.nome[0] = 'A';
    prod.nome[1] = '\0';
    prod.preco = 1;
    prod.qtd = 5;

    /*Cria a lista*/
    FazVazia(&lista);

    /*Insere um produto na lista*/
    Insere(prod, &lista);

    /*mostra a quantidade de elementos na lista*/
    int qtd = Quantidade(lista);
    printf("Numero de produtos = %d\n", qtd);

    /*Imprime a lista*/
    ImprimeLista(lista);

    return 0;
}
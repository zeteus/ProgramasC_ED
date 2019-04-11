#include "listaproduto.h"

int main(){
    tProduto prod;
    tLista lista;
    int continua;

    do{
        criaProduto(&prod); /*Cria um produto*/
        printf("\nDESEJA INCLUIR OUTRO PRODUTO?\n(1 - PARA CONTINUAR, 0 - PARA PARAR)");
        scanf(" %c", &continua);
    } while(continua == 1);

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
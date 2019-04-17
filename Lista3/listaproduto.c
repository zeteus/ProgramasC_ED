#include "listaproduto.h"

void criaProduto(tProduto* p)
{
    printf("CODIGO DO PRODUTO:");
    scanf("%d", &p -> codigo);
    printf("\nNOME DO PRODUTO:");
    scanf(" %29[^\n]", p -> nome);
    printf("\nPRECO DO PRODUTO:");
    scanf("%f", &p -> preco);
    printf("\nQUANTIDADE DE PRODUTOS:");
    scanf("%d", &p -> qtd);
}

/*Faz a lista se tornar vazia*/
void FazVazia(tLista *l)
{
    l -> Primeiro = INICIO;
    l -> Ultimo = l -> Primeiro;
}

/*Verifica se a lista esta vazia*/
int Vazia(tLista l)
{
    return (l.Primeiro == l.Ultimo);
}

/* Insere x apos o ultimo elemento da lista */
void Insere(tProduto p, tLista *l)
{
    if(l -> Ultimo > MAX)
        printf("\nLISTA CHEIA!!n\n");
    else{
        l -> prod[l -> Ultimo - 1] = p;
        l -> Ultimo++;
        }
}

// /*Opcao que nao modifica o lista.h */
// void Retira(Posicao p, tLista *l, tProduto *p);

/*Imprime a lista*/
void ImprimeLista(tLista l)
{ 
    int Aux;

    for (Aux = l.Primeiro - 1; Aux < l.Ultimo; Aux++)
        printf("cod = %d\nnome = %s\npreco = %.2f\nqtd = %d\n", l.prod[Aux].codigo, l.prod[Aux].nome, l.prod[Aux].preco, l.prod[Aux].qtd);
}

/*Quantidade de elementos na lista*/
int Quantidade(tLista l)
{
    if(Vazia(l))
    {
        return 0;
    }

    return l.Ultimo - 1;
}

// /*De acordo com o codigo do produto retorna o mesmo*/
// tProduto buscacodigo(tLista *l, int cod){
//     return p;
// }
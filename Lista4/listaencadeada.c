#include "listaencadeada.h"

/* Faz a lista ficar vazia */
void FLVazia(TipoLista *Lista)
{
    Lista -> Primeiro = NULL;
    Lista -> Ultimo = NULL;
}

/*Verifica se a lista esta vazia*/
int Vazia(TipoLista Lista){
    if(Lista -> Primeiro != NULL && Lista -> Ultimo != Lista -> Primeiro)   return 0;
    else return 1;
}

/* Insere x apos o ultimo elemento da lista */
void Insere(Produto x, TipoLista *Lista){
    if(Vazia(Lista)){
        Lista -> Primeiro = Lista -> Ultimo = (TipoApontador) malloc(sizeof(TipoCelula));
        Lista -> Primeiro -> Item = x;
        Lista -> Primeiro -> Prox = NULL;
    } else{
        Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
        Lista -> Ultimo = Lista -> Ultimo -> Prox;
        Lista -> Ultimo -> Item = x;
        Lista -> Ultimo -> Prox = NULL;
    }
}

/** Busca um produto pelo codigo - retornando a celula inteira*/
TipoApontador BuscaCodigo(int codigo, TipoLista *Lista){
    return produto;
}

/*Retira um elemento da lista */
void Retira(int codigo, TipoLista *Lista, Produto *Item){
    TipoApontador celula = Lista -> Primeiro;
    
    if(Vazia(Lista) == 0)
    {
        while(celula -> Prox != NULL)
        {
            if(celula -> item.codigo == codigo)
            {
                
            }
        }
    }
}


/*Imprime a lista */
void ImprimeLista(TipoLista Lista){
    if(Vazia(Lista))
    {
        printf("LISTA VAZIA\n");
    } else{
        TipoApontador celula = Lista -> Primeiro;
    
        while(celula -> Prox != NULL)
        {
            ImprimeProduto(celula -> Item);
            celula = celula -> Prox;
        }
    }
}

/*Quantidade de elementos na lista*/
int Quantidade(TipoLista Lista){
    if(Vazia(Lista)) return 0;
    
    int cont = 1;
    TipoApontador referencia = Lista -> Primeiro;
    
    while(referencia -> Prox != NULL)
    {
        cont ++;
        referencia = referencia -> Prox;
    }
    return cont;
}

/**FUNCOES OPACAS DO STRUCT PRODUTO **/
Produto  criaProduto(int cod, char *nome, int qtd, float preco){
    Produto p;

    p.codigo = cod;
    p.nome = malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(p.nome, nome);
    p.preco = preco;
    p.qtd = qtd;

    return p;
}

void ImprimeProduto(Produto p){
    printf("CODIGO: %d\n", p.codigo);
    printf("NOME: %s\n", p.nome);
    printf("PRECO: %d\n", p.preco);
    printf("QUANTIDADE: %d\n", p.qtd);
}
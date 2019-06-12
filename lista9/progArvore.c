#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,36};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);
    
    //Alterar o valor de p para testar valores que existem e não
    int p = 36;
    if (consulta_ArvBin(raiz, p))
	printf("Achou o elemento %d\n",p);
    else
	printf("Elemento %d nao encontrado\n", p);
	
    int folha = totalFolha_ArvBin(raiz);
    printf("FOLHAS: %d\n", folha);
    int no = totalNO_ArvBin(raiz);
    printf("NOS: %d\n", no);
    int nFolha = totalNaoFolha_ArvBin(raiz);
    printf("NAO FOLHAS: %d\n", nFolha);

    emOrdem_ArvBin(raiz);
    printf("\n");
    preOrdem_ArvBin(raiz);
    printf("\n");
    posOrdem_ArvBin(raiz);
    printf("\n");

    libera_ArvBin(raiz);

    return 0;
}

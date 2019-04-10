// Exercicio de ordenacao simples (Bubble Sort)

#include <stdio.h>
#include <stdlib.h>

int* preencheArray(int q){
    int* vetor = (int*) malloc(sizeof(int) * q);
    
    for(int i = 0; i < q; i++){
        printf("\nDIGITE UM NUMERO: ");
        scanf("%d", &vetor[i]);
    }
    
    return vetor;
}

void printaArray(int* vet, int q){
    printf("\n");
    for(int i = 0; i < q; i++){
        printf("[%d]", vet[i]);
    }
}

void swap(int* a, int* b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}

void bubbleSorth(int* vet, int q){
    int continua;

    do{
        continua = 0;
        for(int i = 0; i < q - 1; i++){
            if(vet[i] > vet[i + 1]){
                swap(&vet[i], &vet[i + 1]);
                continua = i;
            }
        }
        q --;
    } while(continua != 0);
}

int main(){
    int qtd;

    printf("DIGITE O TAMANHO DA ARRAY: ");
    scanf("%d", &qtd);

    int* array = preencheArray(qtd);

    printaArray(array, qtd);    //ira printar a array original

    bubbleSorth(array, qtd);    //faz a ordenacao

    printaArray(array, qtd);    //ira printar a array ordenada

    free(array);

    return 0;
}
// Exercicio teste: programa que armazena datas de pessoas (sem especificar nomes)

#include <stdio.h>
#include <stdlib.h>

struct Date{
    int day, year;
    char[4] month;
};
typedef struct Date date;

date* alocaArray(int q){
    
    date* array = (date *) malloc (sizeof(date) * q);

    return array;
}

void preencheArray(date* d, int q){

    for(int i = 0; i < q; i++){
        printf("DIGITE O DIA DA DATA DA POSICAO %d: ", (q + 1));
        scanf("%d", d.day);
        printf("DIGITE O MES DA DATA DA POSICAO %d: ", (q + 1));
        scanf("%s", d.month);
        printf("DIGITE O ANO DA DATA DA POSICAO %d: ", (q + 1));
        scanf("%d", d.year);
    };
}

void printaDate(date* d, int q){
    for(int i = 0; i < q; i++){
        printf("DIA: %d MES: %s ANO: %d DA DATA DA POSICAO %d: ", d.day, d.month, d.year, (q + 1));     // Essa parte esta errada por conta da string
    };
}

int main(){
    int qtd;

    printf("QUANTAS DATAS DESEJA GUARDAR? ");
    scanf("%d", &qtd);
    
    date* d = alocaArray(qtd);

    preencheArray(d, qtd);

    printaDate(d, qtd);

    free (d);

    return 0;
}
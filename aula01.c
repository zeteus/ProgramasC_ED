#include <stdio.h>
#include <stdlib.h>

// EXERCICIO 1

void exercicio1(){
    int inteiro = 5;
    float real = 5.5;
    char caracter = 'a';

    int *point_int = &inteiro;
    float *point_float = &real;
    char *point_char = &caracter;
    
    printf("\n\n--EXERCICIO 1--\n");
    printf("ANTES DA MODIFICACAO:\nINTEIRO = %d\nREAL = %.2f\nCARACTER = %c\n", inteiro, real, caracter);

    *point_int = 6;
    *point_float = 6.5;
    *point_char = 'b';

    printf("DEPOIS DA MODIFICACAO:\nINTEIRO = %d\nREAL = %.2f\nCARACTER = %c\n", inteiro, real, caracter);
}

//EXERCICIO 2

void exercicio2(){
    int a = 2, b = 3;
    
    printf("\n\n--EXERCICIO 2--\n");
    
    if(&a > &b){
        printf("ENDERECO DA PRIMEIRA VARIAVEL: %p\n", &a);
    }else{
        printf("ENDERECO DA SEGUNDA VARIAVEL:%p\n", &b);
    }
}

//EXERCICIO 3

int TrocaInteiros(int* n1, int* n2){
    int swap;

    if(*n1 > *n2){
        swap = *n1;
        *n1 = *n2;
        *n2 = swap;

        return 1;
    } else {
        
        return 0;
    }
}

void exercicio3(){
    int n1, n2;
    
    printf("\n\n--EXERCICIO 3--\n");
    printf("DIGITE DOIS NUMEROS SEGUIDOS: ");

    while ( scanf("%d %d", &n1, &n2) == 2 ){
        if ( TrocaInteiros(&n1, &n2) == 1 ){
            printf("TROCADO: %d %d\n", n1, n2);
        } else {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }
}

//EXERCICIO 4

// void preencheArray(void* a, int t, void v){
//     for(int i = 0; i < t; i++){
//         *(a + i) = v;
//     }
// }

// void exercicio4(){
//     printf("\n\n--EXERCICIO 4--\n");

//     void *array, valor;
//     int lenght;
//     char typeValor;

//     printf("DIGITE O TAMANHO DA ARRAY: ");
//     scanf("%d", &lenght);

//     do{
//         printf("DIGITE O TIPO DO VALOR (I, F OU C): ");
//         scanf("%c", &typeValor);
//     switch (typeValor)
//     {
//         case 'i':
//         case 'I':
//             int inteiro;
//             printf("DIGITE UM VALOR INTEIRO: ");
//             scanf("%d", &inteiro);

//             array = (int*) malloc(sizeof(int) * lenght);

//             preencheArray(array, lenght, inteiro);

//             free(array);
//             break;

//         case 'f':
//         case 'F':
//             float real;
//             printf("DIGITE UM VALOR REAL: ");
//             scanf("%f", &real);

//             array = (float*) malloc(sizeof(float) * lenght);

//             preencheArray(array, lenght, real);

//             free(array);
//             break;

//         case 'c':
//         case 'C':
//             char caracter;
//             printf("DIGITE UM CARACTER: ");
//             scanf("%d", &caracter);

//             array = (char*) malloc(sizeof(char) * lenght);

//             preencheArray(array, lenght, caracter);

//             free(array);
//             break;
        
//         default:
//             break;
//     }
//     } while(typeValor != 'c' || typeValor != 'C' || typeValor != 'f' || typeValor != 'F' || typeValor != 'i' || typeValor != 'i')

//     for(int i = 0; i < lenght; i ++){
//         printf("%d ", array[i]);
//     }
// }

//EXERCICIO 6
void swap(int* a, int* b){
    int c;

    c = *a;
    *a = *b;
    *b = c;

}
void inverte(int n, int* vet){
    // int *invet = (int*) malloc(sizeof(int) * n);
    int invet = *vet;
    int j = n;

    for(int i = 0; i < n; i ++){
        swap(&i, &j);
        j --;
    }

}

void exercicio6(){
    int n;

    printf("\n\n--EXERCICIO 6--\n");

    printf("DIGITE O TAMANHO DA ARRAY: ");
    scanf("%d", &n);

    int *vet = (int*) malloc(sizeof(int) * n);

    printf("ANTES>>>\n");
    for(int i = 0; i < n; i ++){
        vet[i] = i;
        printf("[%d]", vet[i]);
    }

    inverte(n, vet);

    printf("\nDEPOIS>>>\n");
    for(int i = 0; i < n; i++){
        printf("[%d]", vet[i]);
    }

    free(vet);
}

int main(){
    
    //exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    exercicio6();
    //exercicio7();

    return 0;
}
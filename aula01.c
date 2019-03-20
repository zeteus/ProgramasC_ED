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

int TrocaInteiros(int *n1, int *n2){
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

int exercicio3(){
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

int main(){
    
    exercicio1();
    exercicio2();
    exercicio3();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOME: EZEQUIEL SCHNEIDER REINHOLTZ *
 * TURMA: CCOMP 01                    *
 *                                    */

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

void preencheArray(int* a, int t, int v){
    for(int i = 0; i < t; i++){
        *(a + i) = v;
    }
}

void exercicio4(){
    printf("\n\n--EXERCICIO 4--\n");

    int *array, inteiro, lenght;

    printf("DIGITE O TAMANHO DA ARRAY: ");
    scanf("%d", &lenght);

    printf("DIGITE UM VALOR INTEIRO: ");
    scanf("%d", &inteiro);

    array = (int*) malloc(sizeof(int) * lenght);

    preencheArray(array, lenght, inteiro);

    for(int i = 0; i < lenght; i ++){
        printf("%d ", array[i]);
    }

    free(array);
}

//EXERCICIO 6

void swap(int* a, int* b){
    int c;

    c = *a;
    *a = *b;
    *b = c;

}
void inverte(int n, int* vet){
    int j = n - 1;

    for(int i = 0; i < j; i ++){
        swap(&(vet[i]), &(vet[j]));
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

// EXERCICIO 7


int ocorre(char* str1, char* str2){
	int i = 0;
	int j = 0;

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

	int repete = 0;

	for( i = 0 ; i < str1_len ; i++ ){
		if( *(str1 + i) == *(str2) ){
			for( j = 0 ; j < str2_len ; j++ ){
				if( i + j >= str1_len ) break;
				if( *(str1 + i + j) == *(str2 + j) ) repete++;
			}
			if( repete == str2_len ) return 1;
			else{
				repete = 0;
				continue;
			}
		}
	}

	return 0;
}

void exercicio7(){
    char *str1 = (char*) malloc(sizeof(char) * 30);
    char *str2 = (char*) malloc(sizeof(char) * 30);

    printf("DIGITE UMA PALAVRA: ");
    scanf("%s", str1);
    printf("DIGITE OUTRA PALAVRA: ");
    scanf("%s", str2);

    if(ocorre(str1, str2)) printf("ESTA CONTIDA!");
    else printf("NAO ESTA CONTIDA!");
    
    free(str1);
    free(str2);
}

int main(){
    
    //exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    //exercicio6();
    exercicio7();

    return 0;
}
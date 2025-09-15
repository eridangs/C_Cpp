#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 10

void bubble(int vetor[], const int size, int (*compare) (int a, int b));
int crescente(int a, int b);
int decrescente(int a, int b);

int main( void ){
    int order; /* 1 para ordem crescente ou 2 para ordem decrescente */
    int i;

    int vetor[TAMANHO] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    float vetor[TAMANHO] = {3.14, 1.41, 2.71, 0.99, 4.20, 0.50, 18.23, 7.93, 4.69, 10.54};
    const char *nomes[] = {"João", "Maria", "Ana", "Carlos", "Beatriz", "Lara", "Antonia", "Vitor", "Sabino", "Marcos"};

    printf( "Digite 1 para ordenar em ordem crescente,\n""Digite 2 para ordenar em ordem decrescente: " );
    scanf( "%d", &order );

    printf( "\nItens de dados na ordem original\n" );
    for ( i = 0; i < TAMANHO; i++ ) {
        printf( "%5d", vetor[ i ] );
    }


    /*passa a função crescente como argumento para especificar ordem crescente */
    if (order == 1) {
        bubble(vetor, TAMANHO, crescente );
        printf("\nItens de dados em ordem crescente\n" );
    }
    else {/*passa a função decrescente */
        bubble(vetor, TAMANHO, decrescente );
        printf("\nItens de dados em ordem decrescente\n" );
    }

    /*exibe o array ordenado */
    for ( i = 0; i < TAMANHO; i++ ) {
        printf("%5d", vetor[ i ] );
    }
    printf("\n");

    return 0;
}


/* bubble sort multipropósito; o parâmetro compare é um ponteiro para a função de comparação que determina a ordem de classificação */
void bubble(int vetor[], const int tamanho, int (*compare)(int a, int b)) {
    int i, j, trocou = 0;
    
    void troca( int *element1Ptr, int *element2Ptr );

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if ((*compare)(vetor[j], vetor[j + 1])) {
                troca(&vetor[j], &vetor[j + 1]);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}


/* troca valores nos locais de memória para os quais element1Ptr e element2Ptr apontam */
void troca( int *element1Ptr, int *element2Ptr ){
    int guarda;
    guarda = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = guarda;
}


/* determina se os elementos estão fora de ordem para uma ordenação crescente */
int crescente( int a, int b ){
    return b < a; /* troca se b for menor que a */
}


/* determina se os elementos estão fora de ordem para uma ordenação decrescente */
int decrescente( int a, int b ){
    return b > a; /* troca se b for maior que a */
}
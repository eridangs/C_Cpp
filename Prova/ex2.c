#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* dobrar_mem(int** , size_t, size_t);

int* dobrar_mem(int **vetor_velho, size_t n, size_t j){
    int *novo_vetor;
    size_t i;
    n *= 2;

    novo_vetor = (int *) malloc(n * sizeof(int));

    for (i = 0; i < j; i++){
        novo_vetor[i] = **vetor_velho + i;
    }

    return *&novo_vetor;
}

int main(){
    int i;
    size_t n = 5, j = 0;
    int *vetor;

    vetor = (int *) malloc(n * sizeof(int));

    while (1){

        for (i = j; i < n; i++){
            printf("N = ");
            scanf("%d",vetor + i);

            if (*vetor + i * sizeof(int) == -1) n = 0; break;
        }

        if (n == 0) break;

        if (i == n){
            j = n;
            vetor = (int*) dobrar_mem(&vetor, n, j);
        }
    }

    for (j = 0; j < i; j++){
        printf("Posicao %d = %d", j, *vetor + j * sizeof(int));
    }

    free(vetor);
    return 0;
}
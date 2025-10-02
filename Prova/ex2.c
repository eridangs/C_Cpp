#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dobrar_mem(int *, size_t, int);

void dobrar_mem(int *vetor, size_t n, int j){
    int *novo_vetor;
    int i;
    n *= 2;

    novo_vetor = (int *) malloc(n);

    for (i = 0; i < j; i++){
        novo_vetor[i] = vetor[i];
    }


    vetor = novo_vetor;
}

int main(){
    int i, j = 0;
    size_t n = 5;
    int *vetor;

    vetor = (int *) malloc(n);

    while (1){

        for (i = j; i < n; i++){
            printf("N = ");
            scanf("%d",&vetor[i]);

            if (vetor[i] == -1) n = 0; break;
            
        }

        if (i == n){
            j = n;
            dobrar_mem(vetor, n, j);
        }  
        else if (n == 0 && i <= n) break;

    }

    for (i = 0; i < n; i++){
        printf("Posicao %d = %d", i, vetor[i]);
    }

    free(vetor);
    return 0;
}
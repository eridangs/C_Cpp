#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* dobrar_mem(int** , size_t, size_t tamanho_antigo);

int* dobrar_mem(int **vetor_velho, size_t n, size_t tamanho_antigo){
    int *novo_vetor;
    size_t i = 0;
    
    novo_vetor = (int *) malloc(n * sizeof(int));
    
    for (i = 0; i < tamanho_antigo; i++){
        *(novo_vetor + i) = *(*vetor_velho + i);
    }
    
    free(*vetor_velho);
    return novo_vetor;
}

int main(){
    size_t index, n = 5, tamanho_antigo = 0, index2;
    int *vetor;
    
    vetor = (int *) malloc(n * sizeof(int));

    while (1){
        
        for (index = tamanho_antigo; index < n; index++){
            printf("N = ");
            scanf("%d",vetor + index);
            if (*(vetor + index) == -1) break;
        }
        
        if (index == n){
            tamanho_antigo = n;
            n *= 2;
            vetor = dobrar_mem(&vetor, n, tamanho_antigo);
        } else{
            break;
        }
    }

    for (index2 = 0; index2 < index; index2++){
        printf("Posicao %d = %d\n", index2, *(vetor + index2));
    }

    free(vetor);
    return 0;
}
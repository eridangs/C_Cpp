#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_FILA 4

void enfilere(int* fila_vetor, int *t_controle, int valor);

int main(){
    int *f;
    int i, s = 0, t = 0, x = 0;

    f = (int*) malloc(TAMANHO_FILA * sizeof(TAMANHO_FILA));

    for (i = 0; i < TAMANHO_FILA; i++) {
        f[i] = -1;
    }
    f[0] = 0;

    for (i = 0; i < TAMANHO_FILA; i++){
        enfilere(f, &t, i);
    }

    return 0;
}


void enfilere(int* f, int *t, int x) {
    if (*t == TAMANHO_FILA){
        printf("\nFila transbordou!\n");
    } else {
        f[*t] = x;
        (*t)++;
    }

}
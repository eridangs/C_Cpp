#include <stdio.h>
#include <stdlib.h>

void enfileirar(int* lista, int* t, unsigned const MAX);
void desenfileirar(int* s, int t);
void imprimirFI(int* lista, int *s, int t);

int main(){
    int *lista, T, opcao, i, s = 0, t = 0;
    scanf("%d", &T);

    lista = (int*) malloc(T * sizeof(int));

    for(i = 0; i < T; i++) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                enfileirar(lista, &t, T);

            break;

            case 2:
                desenfileirar(&s, t);
            break;

            case 3:
                imprimirFI(lista, &s, t);
            break;
        }
    }

    free(lista);
    return 0;
}

void enfileirar(int* lista, int* t, unsigned const MAX){
    int n;

    scanf("%d", &n);

    if ((*t) != MAX) {
        lista[*t] = n;
        (*t)++;
    }
}

void desenfileirar(int* s, int t){

    if ((*s) != t) {
        (*s)++;
    }
}

void imprimirFI(int* lista, int *s, int t){
    if ((*s) != t) {
        printf("%d\n", lista[*s]);
    } else {
        printf("Empty!\n");
    }
}
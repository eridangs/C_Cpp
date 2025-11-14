#include <stdio.h>
#include <stdlib.h>

void empilhar(int* lista, int* t, unsigned const T);
void desempilhar(int* lista, int* s, int t);
int imprimirFI(int* lista, int *s, int t);

int main(){
    int *lista, T, F, opcao, i, s = 0, t = 0;
    scanf("%d", &T);

    lista = (int*) malloc(T * sizeof(int));
    lista[0] = T;

    for(i = 0; i < T; i++) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                empilhar(lista, &t, T);

            break;

            case 2:
                desempilhar(lista, &s, T);
            break;

            case 3:
                F = imprimirFI(lista, &s, T);
                printf("%d", F);
            break;
        }
    }

    free(lista);
    return 0;
}

void empilhar(int* lista, int* t, unsigned const T){
    int n;

    scanf("%d", &n);

    if ((*t) != T) {
        lista[*t] = n;
        (*t)++;
    }
}

void desempilhar(int* lista, int* s, int t){

    if ((*s) != t) {
        lista[*s] = NULL;
        (*s)++;
    }
}

int imprimirFI(int* lista, int *s, int t){
    if ((*s) != t) {
        return lista[*s];
    } else {
        printf("Empty!");
        exit;
    }
}
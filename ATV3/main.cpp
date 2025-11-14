#include <stdio.h>
#include <stdlib.h>

void emfilerar(int* lista, int* t, unsigned const T);
void desemfilherar(int* lista, int* s, int t);
int imprimirFI(int* lista, int *s, int t, int *isnull);

int main(){
    int *lista, T, F, opcao, i, s = 0, t = 0, isnull = 0;
    scanf("%d", &T);

    lista = (int*) malloc(T * sizeof(int));
    lista[0] = T;

    for(i = 0; i < T; i++) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                emfilerar(lista, &t, T);

            break;

            case 2:
                desemfilherar(lista, &s, t);
            break;

            case 3:
                isnull = 0;
                F = imprimirFI(lista, &s, t, &isnull);
                if (!isnull) printf("%d\n", F);
            break;
        }
    }

    free(lista);
    return 0;
}

void emfilerar(int* lista, int* t, unsigned const T){
    int n;

    scanf("%d", &n);

    if ((*t) != T) {
        lista[*t] = n;
        (*t)++;
    }
}

void desemfilherar(int* lista, int* s, int t){

    if ((*s) != t) {
        (*s)++;
    }
}

int imprimirFI(int* lista, int *s, int t, int *isnull){
    if ((*s) != t) {
        return lista[*s];
    } else {
        printf("Empty!\n");
        return (*isnull = 1);
    }
}
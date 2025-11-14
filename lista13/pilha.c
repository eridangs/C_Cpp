#include <stdio.h>
#include <stdlib.h>
#define N 30

// 1 - 11, 7, 2

void empilhar_pilha(int*, int*, int);
int desempilhar_pilha(int*, int*);

int main(){
    int *p, t=0, y, i, u;

    p = (int*) malloc(N * sizeof(int));
    // limpar p
    for (i = 0; i < N; i++){
        p[i] = 0;
    }

    empilhar_pilha(p, &t, 33);
    empilhar_pilha(p, &t, 7);
    empilhar_pilha(p, &t, 11);

    u = desempilhar_pilha(p, &t);
    printf("%d\n", u);
    u = desempilhar_pilha(p, &t);
    printf("%d\n", u);

    empilhar_pilha(p, &t, 2);

    u = desempilhar_pilha(p, &t);
    printf("%d\n", u);


    return 0;
}


void empilhar_pilha(int* p, int* t, int y){
    if ((*t) != N){
        p[(*t)++] = y;
    } else {
        printf("Ocorreu um transbordamento (STACKOVERFLOW)!");
    }
}

int desempilhar_pilha(int* p, int* t){
    int mem;
    if ((*t) != 0) {
        mem = p[(*t)-1];
        p[(*t)--]; //valor sera sobreescrito na proxima empilhacao
        return mem;

    } else {
        printf("Ocorreu um esvaziamento (STACKUNDERFLOW)!");
    }
}
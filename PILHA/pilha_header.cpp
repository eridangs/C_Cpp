#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel* prox;
};

typedef struct cel celula;

int desempilhar(celula *cabeca);
void empilhar(celula *cabeca, int valor);

int main(){
    celula c, *cabeca;
    c.prox = NULL;
    cabeca = &c;

    empilhar(cabeca, 7);
    desempilhar(cabeca);

}

void empilhar(celula *cabeca, int valor){
    celula *nova;

    nova = (celula*) malloc((sizeof(celula)));

    if (nova == NULL) {
        printf("StackOverFlow!");
    } else {
        nova->conteudo = valor;
        nova->prox = cabeca->prox;
    }

    cabeca->prox = nova;
}

int desempilhar(celula *cabeca) {
    int u;
    celula *removido;

    removido = cabeca->prox;

    if (removido != NULL) {
        u = removido->conteudo;

        cabeca->prox = removido->prox;
    } else {
        printf("StackUnderFlow!");
    }

    return u;
}
//void empilhar (celula* &nao_cabeca, int valor); para passar ponteiro para ponteiro em C++
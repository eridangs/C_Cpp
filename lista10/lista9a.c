#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void busque_e_insira(int, celula*);

void imprima(celula*);

void busque_e_insira(int y, celula *cabeca){
    celula *proxima, *anterior, *nova;
    // proxima equivale à Q | anterior equivale à P (começa sendo a cabeça)

    nova = (celula*) malloc(sizeof(celula));
    nova-> conteudo = y;

    anterior = cabeca;
    proxima = cabeca->seg;

    while(proxima != NULL && y >= proxima->conteudo) {
        anterior = proxima;
        proxima = proxima->seg;
    }
    

    nova->seg = anterior->seg;
    anterior->seg = nova;
}

void imprima(celula *cabeca){
    celula *p;

    printf("cabeça -> ");
    for(p = cabeca->seg; p!= NULL; p = p->seg){
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}

int main(){
    celula c, *cabeca; // cabeça equivale à lst
    
    c.seg = NULL;
    cabeca = &c;

    busque_e_insira(5, cabeca);
    busque_e_insira(3, cabeca);
    busque_e_insira(7, cabeca);
    busque_e_insira(1, cabeca);
    
    imprima(cabeca);

    return 0;
}
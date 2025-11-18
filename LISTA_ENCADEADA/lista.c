#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void insira(int valor, celula* cabeca);
void remova(celula* cabeca);
void remova_recursivo(celula* cabeca);
int conte_celulas(celula* cabeca);

int main() {

    celula c, *cabeca;

    c.seg = NULL;

    cabeca = &c;

    int qtd = 0;

    insira(50, cabeca);
    insira(10, cabeca);
    insira(20, cabeca);
    insira(30, cabeca);
    insira(7, cabeca);

    // remova(cabeca);
    // remova_recursivo(cabeca);
    qtd = conte_celulas(cabeca);
    printf("%d", qtd);
    
    return 0;
}

void insira(int valor, celula* cabeca) {
    celula * nova;
    nova = (celula*) malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->seg = cabeca->seg;
    cabeca->seg = nova;
}

void remova(celula* cabeca) {
    celula* go_bin;

    while (cabeca->seg != NULL){
        go_bin = cabeca->seg;
        cabeca->seg = go_bin->seg;
        free(go_bin);
    }
    cabeca->seg = NULL;
}

void remova_recursivo(celula* cabeca) {
    if (cabeca->seg == NULL) {
        return;
    }
    remova_recursivo(cabeca->seg);
    free(cabeca->seg);
    cabeca->seg = NULL;
}

int conte_celulas(celula* cabeca){
    int contador = 1;
    celula* p; 

    while (cabeca->seg != NULL) {
        p = cabeca->seg;
        cabeca->seg = p->seg;
        contador++;
    }

    return contador;
}
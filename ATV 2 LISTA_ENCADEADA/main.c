#include <stdio.h>
#include <stdlib.h>

typedef struct cel celula;
struct cel {
    int conteudo;
    struct cel *ante;
    struct cel *prox;
};

void inserir(int valor, celula* header);
void imprimir(celula* header);
void buscar_e_remover(int y, celula* header);
void remover_inicio(celula* header);
void buscar(int y, celula* header);

int main(){
    celula c, *header;
    header = &c;
    c.conteudo = 0;
    c.ante = header;
    c.prox = header;

    inserir(1, header);
    inserir(2, header);
    inserir(3, header);
    inserir(4, header);
    inserir(5, header);

    imprimir(header);
    
    buscar_e_remover(10, header);
    buscar_e_remover(1, header);

    imprimir(header);

    remover_inicio(header);

    imprimir(header);

    inserir(6, header);
    inserir(7, header);
    inserir(8, header);

    imprimir(header);
    buscar(8, header);

    remover_inicio(header);
    remover_inicio(header);
    
    imprimir(header);
    
    return 0;
}

void inserir(int valor, celula* header){
  celula *nova;
  nova = (celula*) malloc(sizeof(celula));
  nova->conteudo = valor;

  if (header->prox == header){
    header->ante = nova;
    header->prox = nova;
    nova->prox = header;
    nova->ante = header;
  }
  else {
    nova->prox = header->prox;
    nova->ante = header;
    header->prox->ante = nova;
    header->prox = nova;
  }
};

void imprimir(celula* header){
    celula *seguinte = header->prox;

    printf("Cabeça: \"");

    while (seguinte != header) {
        printf("|%d| ->", seguinte->conteudo);
        seguinte = seguinte->prox;
    }
    printf("Fim \"\n");
}

void buscar_e_remover(int y, celula* header) {
    celula *seguinte = header->prox;

    while (seguinte != header && seguinte->conteudo != y){
        seguinte = seguinte->prox;
    }
    if (seguinte != header) {
        seguinte->ante->prox = seguinte->prox;
        seguinte->prox->ante = seguinte->ante;
        free(seguinte);
    }

}

void remover_inicio(celula* header) {
    celula *seguinte = header->prox;

    if (seguinte != header) {
        header->prox = seguinte->prox;
        seguinte->prox->ante = header;
        free(seguinte);
    }
}

void buscar(int y, celula* header) {
    celula *seguinte = header->prox;

    while (seguinte != header && seguinte->conteudo != y){
        seguinte = seguinte->prox;
    }
    if (seguinte != header) {
        printf("Achou o %d!\n", seguinte->conteudo);
    }
}
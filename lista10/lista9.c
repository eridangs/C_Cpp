#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void insert(int, celula*);
void imprima(celula*);

void insert(int y, celula *p){
    celula *nova;

    nova = (celula*) malloc(sizeof(celula));

    nova-> conteudo = y;
    nova->seg = p->seg;

    p->seg = nova;
}

void imprima(celula *lst){
    celula *p;

    printf("cabeça -> ");
    for(p = lst->seg; p!= NULL; p = p->seg){
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}

int main(){
    celula c, *lst;

    c.seg = NULL;
    lst = &c;

    insert(1, lst);
    insert(3, lst);
    insert(5, lst);
    insert(7, lst);
    
    imprima(lst);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *ant;
    struct cel *seg;
};

typedef struct cel celula;

int main(){
    cel c, *cabeca;
    c.seg = NULL;
    c.*ant = NULL;

    cabeca = &c;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PILHA E CHAVES

#define MAX 2005

void empilhar (char *pilha, int *t, char chave);
void desempilhar (char *pilha, int *t);

int main() {
    char linha[MAX], *pilha;
    int casos = 1, t = 0, i = 0;
    pilha = (char*) malloc(MAX * sizeof(char));
    
    while (scanf("%s", linha) != EOF) {
        if (linha[0] == '-') {
            break;
        }

        t = 0;
        for (i = 0; linha[i] != '\0'; i++) {
            char chave = linha[i];

            if (t != 0 && pilha[t-1] == '{' && chave == '}') {
                desempilhar(pilha, &t);
            } else {
                empilhar(pilha, &t, chave);
            }
        }
        int abre = 0, fecha = 0;

        for (t; 0 < t; t--) {
            if (pilha[t-1] == '{') abre++;
            else fecha++;
        }

        int trocas = (abre + 1) / 2 + (fecha + 1) /2 ;

        printf("%d. %d\n",casos, trocas);
        casos++;
    }
    
    

    return 0;
}

void empilhar (char *pilha, int *t, char chave) {
    if ((*t) != MAX) {
        pilha[(*t)] = chave;
        (*t)++;
    }
}
void desempilhar (char *pilha, int *t) {
    if ((*t) != 0) {

        (*t)--;
    }
}
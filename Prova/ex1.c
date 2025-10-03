#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    char descricao[100];
    double preco;
    int qtde;
} produto;


int main(){
    produto *cardapio;
    int n, i;

    printf("Qual a quantidade de itens no cardapio?\n");
    scanf("%d", &n); // 1 - 10

    cardapio = (produto *) malloc(n * sizeof(produto)); //

    printf("Registre as infos do cardapio de hoje:\n");
    for(i = 0; i < n; i++){
        printf("Cód do item %d: ", i+1);
        scanf("%d", &cardapio[i].cod);
        printf("Descriçao do item %d: ", i+1);
        scanf("%s%*c", &cardapio[i].descricao);
        printf("Preco do item %d: ", i+1);
        scanf("%lf", &cardapio[i].preco);
        printf("\n");
        cardapio[i].qtde = 0;
    }

    int cod, qtde, j = 0;
    double total = 0;
    int *guarda;
    guarda = (int *) malloc(n * sizeof(int));

    while (1){
        printf("Qual o codigo do item do cardapio?\n");
        scanf("%d", &cod);
        if (cod == 0) break;
        for(i = 0; i < n; i++){
            if(cod == cardapio[i].cod) break;
        }
        if (i == n){
            printf("Código não encontrado!");
        } else{
            printf("Quantas unidade deseja?\n");
            scanf("%d", &cardapio[i].qtde);

            total += cardapio[i].preco * cardapio[i].qtde;
            guarda[j] = i;
            j += 1;
        }
    }
    
    printf("PEDIDO FINALIZADO\n");
    for (i = 0; i < j; i++){
        printf("%d x %s\n", cardapio[guarda[i]].qtde, cardapio[guarda[i]].descricao);
    }
    printf("TOTAL R$ %.2lf\n", total);
    free(guarda);
    free(cardapio);
    return 0;
}
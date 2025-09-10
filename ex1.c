#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade, ano;
    FILE *entrada;

    entrada = fopen("entrada.txt", "w"); // write variaveis

    printf("Digite sua idade: ");
    scanf("%d",&idade);
    fprintf(entrada, "%d\n", idade);
    printf("Digite seu ano de nascimento: ");
    scanf("%d",&ano);
    fprintf(entrada, "%d\n", ano);
    fclose(entrada);

    printf("Idade = %d Ano = %d", idade, ano);

    return 0;
}
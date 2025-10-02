#include <stdio.h>
#include <stdlib.h>

int main(){
    int soma = 0, i, v = 0;
    FILE *entrada, *saida;

    entrada = fopen("entrada.txt", "r");
    if(entrada == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    for(i=0;i<2;i++){
        fscanf(entrada, "%d", &v);
        soma += v; 
    }

    fclose(entrada);

    saida = fopen("saida.txt", "w");
    fprintf(saida, "%d", soma);
    fclose(saida);
    printf("Soma = %d\n",soma);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int soma = 0, retorno = 0, v = 0, v2 = 0;
    FILE *entrada, *saida;

    entrada = fopen("entrada.txt", "r");
    if(entrada == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    for(;;){
        retorno = fscanf(entrada, "%d%d", &v, &v2);

        if(retorno == EOF){// EOF = -1
            break;
        }
        else if(retorno == 2){
            soma += v + v2; 
        }
        else if(retorno == 1){
            soma += v;
        }
    }

    fclose(entrada);
    printf("Soma = %d\n",soma);

    saida = fopen("saida.txt", "w");
    fprintf(saida, "%d", soma);
    fclose(saida);


    return 0;
}
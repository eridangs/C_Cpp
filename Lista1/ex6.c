#include <stdio.h>

int main(){
    int i = 0, soma = 0, numero;
    double  media;

    while (1){
        printf("Digite 0 para parar e qualquer número para continuar:\n");
        scanf("%d",&numero);
        if( numero == 0) break;
        soma += numero;
        i += 1;
    }
    media = soma / i;
    printf("Números digitados: %d\n Soma final: %d\n Média: %.2lf", i, soma, media);
    
    return 0;
}
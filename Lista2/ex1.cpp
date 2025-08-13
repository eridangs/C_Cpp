#include <stdio.h>

int main(){
    int i = 0;
    float vetorU[3] , vetorV[3],multiplica = 0, produto = 0;

    printf("Entre com os valores para os vetores U e V:\n");

    for (i = 0; i < 3; i++){
        multiplica = 0;
        scanf("%f %f", &vetorU[i], &vetorV[i]);
        multiplica = vetorU[i] * vetorV[i];

        printf("\n");

        produto += multiplica;

    }

    printf("O produto escalar dos vetores U e V é : %.2f\n", produto);

    return 0;
}
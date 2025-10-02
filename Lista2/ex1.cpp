#include <stdio.h>

int main(){
    int i = 0, multiplica = 0, produto = 0;
    int vetorU[3] , vetorV[3];

    
    for (i = 0; i < 3; i++){
        printf("Entre o valor %d para o vetor U\n", i);
        scanf("%d", &vetorU[i]);
    }
    for (i = 0; i < 3; i++){
        printf("Entre o valor %d para o vetor V\n", i);
        scanf("%d", &vetorV[i]);
    }
    for(i = 0; i < 3; i ++){
        multiplica = vetorU[i] * vetorV[i];
        produto += multiplica;
    }

    printf("\nO produto escalar dos vetores U e V é : %d\n", produto);

    return 0;
}
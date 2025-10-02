#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor_aleatorio[6], chute = 0, i, aleatorio;
    srand(time(NULL));

    for (i = 0; i < 6; i++){
        aleatorio = (rand() % 60) + 1;
        vetor_aleatorio[i] = aleatorio;
    }

    while (1){
        printf("Faça um palpite do número dento do vetor no intervalo de 1-60:\n");
        scanf("%d", &chute);
        
        if (chute == 0){
            break;
        } else {
            for (i = 0; i < 6; i++){
                if (vetor_aleatorio[i] == chute){
                    printf("Você acertou 1 número! Ele está na posição %d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
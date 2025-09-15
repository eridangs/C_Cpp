#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_SORTEIO 3

// Enum //
enum valor {AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI};
enum naipe {COPAS = 1, OUROS, PAUS, ESPADAS} naipe;
// Enum //

// Struct //
typedef struct{
    enum valor valor;
    enum naipe naipe;
} carta;
// Struct //


void sorteio(carta *baralho);

int main(){
    carta baralho[52];
    int i = 0, sorteio_num[6];

    sorteio(baralho);

    for (i = 0; i < 3; i++){
        printf("Carta = %d de %d\n",baralho[i].valor, baralho[i].naipe);
    }

    return 0;
}

const char* traducao_valor(enum valor valor) {
    switch(valor) {
        case AS:
        return "Ás";

        case DOIS:
        return "Dois";

        case TRES:
        return "Três";

        case QUATRO:
        return "Quatro";

        case CINCO:
        return "Cinco";

        case SEIS:
        return "Seis";

        case SETE:
        return "Sete";

        case OITO:
        return "Oito";

        case NOVE:
        return "Nove";

        case DEZ:
        return "Dez";

        case VALETE:
        return "Valete";

        case DAMA:
        return "Dama";

        case REI:
        return "Rei";

        default:
        return "Desconhecido";
    }
}

const char* naipe_para_string(enum naipe n) {
    switch(n) {
        case COPAS: return "Copas";
        case OUROS: return "Ouros";
        case PAUS: return "Paus";
        case ESPADAS: return "Espadas";
        default: return "Desconhecido";
    }
}

void sorteio(carta *baralho){
    int i, sorteio_num[6];
    srand(time(NULL));

    for (i = 0; i < 6; i++){
        if (i % 2 == 0){
            sorteio_num[i] = (rand() % 13) + 1;
        } else {
            sorteio_num[i] = (rand() % 4) + 1;
        }
        printf("\nNumero sorteado: %d\n", sorteio_num[i]);
    }

    for (i = 0; i < 6; i ++){
        printf("%d",sorteio_num[i]);
        if (i % 2 == 0){
            baralho[i].valor = sorteio_num[i];
        } else {
            baralho[i].naipe = sorteio_num[i];
        }
    }
}

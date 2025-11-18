#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 52

// Enum //
enum valor {AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI};
enum naipe {COPAS = 1, OUROS, PAUS, ESPADAS};
// Enum //

// Struct //
typedef struct {
    enum valor valor;
    enum naipe naipe;
} cartas;
// Struct //

void inicializar_baralho(cartas *baralho);
void sortear_cartas(cartas *baralho, cartas *sorteadas);
void imprimir_carta(cartas carta);

int main() {
    cartas baralho[TAM];
    cartas sorteadas[3];
    
    srand(time(NULL));
    
    inicializar_baralho(baralho);
    sortear_cartas(baralho, sorteadas);
    
    printf("Cartas sorteadas:\n");
    for (int i = 0; i < 3; i++) {
        imprimir_carta(sorteadas[i]);
        if (i < 2) {
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}

void inicializar_baralho(cartas *baralho) {
    int i = 0;
    for (int naipe = COPAS; naipe <= ESPADAS; naipe++) {
        for (int valor = AS; valor <= REI; valor++) {
            baralho[i].valor = valor;
            baralho[i].naipe = naipe;
            i++;
        }
    }
}

void sortear_cartas(cartas *baralho, cartas *sorteadas) {
    int indices_sorteados[3] = {0};
    int i, j, indice;
    int repetido;
    
    for (i = 0; i < 3; i++) {
        do {
            repetido = 0;
            indice = rand() % TAM;
            
            for (j = 0; j < i; j++) {
                if (indices_sorteados[j] == indice) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);
        
        indices_sorteados[i] = indice;
        sorteadas[i] = baralho[indice];
    }
}

void imprimir_carta(cartas carta) {
    // Converter valor para texto
    switch(carta.valor) {
        case AS: printf("Ás"); break;
        case DOIS: printf("Dois"); break;
        case TRES: printf("Três"); break;
        case QUATRO: printf("Quatro"); break;
        case CINCO: printf("Cinco"); break;
        case SEIS: printf("Seis"); break;
        case SETE: printf("Sete"); break;
        case OITO: printf("Oito"); break;
        case NOVE: printf("Nove"); break;
        case DEZ: printf("Dez"); break;
        case VALETE: printf("Valete"); break;
        case DAMA: printf("Dama"); break;
        case REI: printf("Rei"); break;
    }
    
    printf(" de ");
    
    // Converter naipe para texto
    switch(carta.naipe) {
        case COPAS: printf("Copas"); break;
        case OUROS: printf("Ouros"); break;
        case PAUS: printf("Paus"); break;
        case ESPADAS: printf("Espadas"); break;
    }
}
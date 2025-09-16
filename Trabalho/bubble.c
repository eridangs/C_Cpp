#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 10
int tipo_ordenacao;

void bubble(void *vetor, size_t tamanho, size_t tam_tipo, int (*compare) (const void *, const void *));
int compare(const void *, const void *);

int main(void){
    int order, i;
    void *vetor;
    size_t tam_tipo;

    int numeros[TAMANHO] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    float decimais[TAMANHO] = {3.14, 1.41, 2.71, 0.99, 4.20, 0.50, 18.23, 7.93, 4.69, 10.54};
    char *nomes[TAMANHO] = {"João", "Maria", "Ana", "Carlos", "Beatriz", "Lara", "Antonia", "Vitor", "Sabino", "Marcos"};
    char letras[TAMANHO] = {'k','n','q','o','a','p','c','z','s','l'};

    printf("Digite 1 para ordenar inteiros\nDigite 2 para ordenar float\nDigite 3 para ordenar nomes\nDigite 4 para ordenar caracteres\n");
    scanf("%d", &order );
    printf("\nItens de dados na ordem original\n" );
    
    tipo_ordenacao = order;

    if (order == 1) {

        vetor = numeros;
        tam_tipo = sizeof(int);

        for (i = 0; i < TAMANHO; i++){
            printf("   %d", ((int*)vetor)[i]); // casting
        }
    } else if(order == 2){

        vetor = decimais;
        tam_tipo = sizeof(float);

        for (i = 0; i < TAMANHO; i++){
            printf("   %.2f", ((float*)vetor)[i]);
        }
    } else if(order == 3){

        vetor = nomes;
        tam_tipo = sizeof(char*);

        for ( i = 0; i < TAMANHO; i++ ) {
            printf("   %s", ((char**)vetor)[i]);
        }
    } else if(order == 4){

        vetor = letras;
        tam_tipo = sizeof(char);

        for ( i = 0; i < TAMANHO; i++ ) {
            printf( "   %c", ((char*)vetor)[i]);
        }
    }

    bubble(vetor, TAMANHO, tam_tipo, compare);
    printf("\nChegou aqui!");

    printf( "\nItens de dados ordenados\n" );
    switch(tipo_ordenacao){
        case 1:
            for (i = 0; i < TAMANHO; i++){
                printf("   %d ", ((int*)vetor)[i]);
            }
            break;
        case 2:
            for (i = 0; i < TAMANHO; i++){
                printf("   %.2f ", ((float*)vetor)[i]);
            }
            break;
        case 3:
            for (i = 0; i < TAMANHO; i++){
                printf("   %s ", ((char**)vetor)[i]);
            }
            break;
        case 4:
            for (i = 0; i < TAMANHO; i++){
                printf("   %c ", ((char*)vetor)[i]);
            }
            break;
    }
    return 0;
}

/*multipropósito, o parâmetro compare é um ponteiro para a função de comparação*/
void bubble(void *vetor, size_t tamanho, size_t size, int (*compare)(const void *, const void *)) {
    size_t i, j, trocou;
    void *temp = malloc(size);
    
    for (i = 0; i < tamanho - 1; i++) {
        trocou = 0;

        for (j = 0; j < tamanho - i - 1; j++) {

            void *a = (char*)vetor + j * size; //vamos avançar endereços não posições
            void *b = (char*)vetor + (j + 1) * size;

            if ((*compare)(vetor + j * size, vetor + (j + 1) * size) > 0) {
                /* troca valores nos locais de memória para os quais a e b apontam */
                memcpy(temp, a, size);
                memcpy(a, b, size);
                memcpy(b, temp, size);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
    free(temp);
}



int compare(const void *a, const void *b){
    float num1, num2;

    switch(tipo_ordenacao){
        case 1:
            return (*(int*)a > *(int *)b);
        
        case 2:
            num1 = *(float *)a;
            num2 = *(float *)b;
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            return 0;
        
        case 3:
            return strcmp(*(const char**)a, *(const char**)b); //* a mais pois os valores são acessados com char**

        case 4:
            return (*(char*)a - *(char*)b);

        default:
            return 0;
    }

}

#include <stdio.h>
#include <locale.h>
#define DESCONTO 0.2

typedef struct{
    char nome[50]; //%49s%*c
    char cpf[14];
    char socio;
    int qtd_curso;
} cadastro;

float calcula(cadastro, int);

int main(){
    cadastro cadastro;
    float valor = 0;

    printf("Qual o nome do participante?\n");
    scanf("%49s%*c", &cadastro.nome);
    printf("Qual o CPF do participante? (Formato 000.000.000-00)\n");
    scanf("%14s%*c", &cadastro.cpf);
    printf("Participante eh associado? (Digite S - sim, N - nao)\n");
    scanf("%c", &cadastro.socio);
    printf("Quantos cursos participara? (1 - 2 - 3 - 4)\n");
    scanf("%d", &cadastro.qtd_curso);

    valor = calcula(cadastro,valor);

    printf("Participante %s deve pagar um total de %.2f reais", cadastro.nome, valor);
    return 0;
}

float calcula(cadastro cadastro, int valor){
    float desconto = 0.0;

    if (cadastro.socio == 'S'){
        desconto = DESCONTO;
    }

    if (cadastro.qtd_curso == 1){
        valor = 30 - (30 * desconto);
    }
    else if (cadastro.qtd_curso == 2){
        valor = 60 - (60 * desconto);
    }
    else if (cadastro.qtd_curso == 2){
        valor = 90 - (90 * desconto);
    }
    else if (cadastro.qtd_curso == 4){
        valor = 100 - (100 * desconto);
    }
    return valor;
}
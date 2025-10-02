#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM 50

typedef struct {
    int dia;
    int mes;
    int ano;
} data_hoje;

typedef struct{
    int dia;
    int mes;
    int ano;
} data_nasc;

int descobre_idade(data_hoje, data_nasc, int);

int main(){
    setlocale(LC_ALL,"Portuguese");
    
    data_hoje today = {23, 9, 2025};
    data_nasc birth = {0, 0, 0};
    char nome[TAM];
    int idade;


    printf("Qual seu nome?\n");
    scanf("%s", &nome);
    printf("Seu nome eh %s\n", nome);

    printf("Qual o dia que voce nasceu?\n");
    scanf("%d", &birth.dia);
    printf("Qual o mes que voce nasceu?\n");
    scanf("%d", &birth.mes);
    printf("Qual o ano que voce nasceu?\n");
    scanf("%d", &birth.ano);

    
    idade = descobre_idade(today, birth, idade);
    
    printf("\n%s nasceu em %d/%d/%d e tem %d anos!", nome, birth.dia, birth.mes, birth.ano, idade);

    return 0;
};


int descobre_idade(data_hoje hoje, data_nasc birth, int idade){

    if ((hoje.mes >= birth.mes && hoje.dia >= birth.dia) || hoje.mes > birth.mes){
        idade = hoje.ano - birth.ano;
    } else{
        idade = hoje.ano - birth.ano - 1;
    }

    return idade;
    
};
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM 50

struct data_hoje{
    int dia;
    int mes;
    int ano;
};

struct data_nasc{
    int dia;
    int mes;
    int ano;
};

typedef struct data_hoje data_hoje; //renomeando de "struct data_hoje" para apenas "data_hoje"
typedef struct data_nasc data_nasc;


int descobre_idade(data_hoje data1, data_nasc data2, int idade);


int main(){
    setlocale(LC_ALL,"Portuguese");
    
    data_hoje hoje = {22, 8, 2025};
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

    
    idade = descobre_idade(hoje, birth, idade);
    
    printf("\n%s nasceu em %d/%d/%d e tem %d anos!", nome, birth.dia, birth.mes, birth.ano, idade);

    return 0;
};


int descobre_idade(data_hoje hoje, data_nasc birth, int idade){

    if (hoje.mes == birth.mes && hoje.dia >= birth.dia){
        idade = hoje.ano - birth.ano;
    }
    else if (hoje.mes > birth.mes){
        idade = hoje.ano - birth.ano;
    } else{
        idade = hoje.ano - birth.ano - 1;
    }

    return idade;
    
};
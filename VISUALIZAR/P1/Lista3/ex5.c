#include <stdio.h>
#include <locale.h>
#include <string.h>

enum estado_civil {SOLTEIRO = 1, CASADO, DIVORCIADO, VIUVO} estado;
int menu(int op);

int main () {
    enum estado_civil op = 0;
    op = menu(op);

    switch(op) {
        case SOLTEIRO:
        printf("Seu estado civil é solteiro!\n");
        break;

        case CASADO:
        printf("Seu estado civil é casado!\n");
        break;

        case DIVORCIADO:
        printf("Seu estado civil é divorciado!\n");
        break;

        case VIUVO:
        printf("Seu estado civil é viúvo!\n");
        break;

        default:
        printf("Opcao invalida! Entre com um valor valido!\n");
        break;
    }
    
    return 0;
}

int menu(int op){
    printf("---Digite o número correspondente a sua situação cívil---\n1 - SOLTEIRO\n2 - CASADO\n3 - DIVORCIADO\n4 - VIÚVO\n5 - SAIR\n");
    scanf("%d", &op);
    return op;
}
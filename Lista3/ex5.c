
#include <stdio.h>
int main () {
    int op;
    printf("Entre com uma opcao: \n");
    scanf("%d", &op);

    switch(op) { // Usar para o Enum
        case 1:
        printf("Opcao 1 selecionada!\n");
        break;

        case 2:
        printf("Opcao 2 selecionada!\n");
        break;

        default:
        printf("Opcao invalida! Entre com um valor valido!\n");
        break;
    }
    
    return 0;
}
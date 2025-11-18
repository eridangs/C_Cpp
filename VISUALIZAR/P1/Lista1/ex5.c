#include <stdio.h>

int main(){
    int dividendo = 0, divisor = 0, quociente = 0, resto;
    printf("Digite o valor de a e b, para realizar a/b:\n");
    scanf("%d %d", &dividendo, &divisor);
    resto = dividendo;

    while (1){
        if(resto - divisor >= 0){
            resto -= divisor;
            quociente += 1;
        } else{
            break;
        }
    }
    printf("A divisão inteira de %d / %d = %d\n", dividendo, divisor, quociente);
    printf("O resto é: %d", resto);
    
    return 0;
}
#include <stdio.h>
#define pi 3.1415

int main(){
    double raio, altura;
    printf("Informe o raio e altura do cilindro: ");
    scanf("%lf %lf", &raio, &altura);
    double vol = pi * (raio * raio) * altura;
    printf("O volume é: %.2lf\n", vol);
    return 0;
}
/* pode ser %d ou %i para que seja entendido como inteiro (nesse caso, é double)*/
/* %lf é para mostrar em double*/
/* declara como double porque vai ler lido como double*/
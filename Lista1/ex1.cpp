#include <stdio.h>
#include <math.h>

int main(){
    double pi = 3.1415;
    double raio, altura; /* declara como double porque vai ler lido como double*/
    printf("Informe o raio e altura do cilindro: ");
    scanf("%lf %lf", &raio, &altura); /* pode ser %d ou %i para que seja entendido como inteiro (nesse caso, é double)*/
    double vol = pi * (raio * raio) * altura;
    /*printf("%lf %lf %lf", pi, raio, altura);*/
    printf("O volume é: %lf\n", vol); /* %lf é para mostrar em double*/

    return 0;
}
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
    int numerador;
    int denominador;
} fracao;

int mdc(int a, int b);
void simplifica(fracao *); //* Garante que a fração não duplique
float para_real(fracao );
fracao soma(fracao, fracao);

int main(){
    setlocale(LC_ALL, "Portuguese");

    fracao fracao1 = {1, 2};
    fracao fracao2 = {1, 3};
    fracao fracao3 = {-6, -8};
    float real = 0;
    fracao resultado_soma = {0, 0};

    printf("Fracao original: %d / %d\n", fracao3.numerador, fracao3.denominador);
    simplifica(&fracao3);
    printf("Fracao simplificada: %d / %d\n", fracao3.numerador, fracao3.denominador);

    real = para_real(fracao1);
    printf("A fracao %d / %d equivale a %.2f\n", fracao1.numerador, fracao1.denominador, real);


    resultado_soma = soma(fracao1, fracao2);
    printf("%d / %d + %d / %d = ", fracao1.numerador, fracao1.denominador, fracao2.numerador, fracao2.denominador);
    printf("%d / %d", resultado_soma.numerador, resultado_soma.denominador);

    return 0;
};

int mdc(int a, int b){
    a = abs(a); //abs garante que funcione para frações negativas
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplifica(fracao *fracao){
    if (fracao->denominador == 0) {
        printf("Erro: Denominador zero.\n");
        return;
    }
    int divisor = mdc(fracao->numerador, fracao->denominador);
    fracao->numerador /= divisor;
    fracao->denominador /= divisor;
}

float para_real(fracao f){
    if (f.denominador == 0) {
        printf("Erro: Denominador zero.\n");
        return 0.0;
    }
    return (float)f.numerador / f.denominador;
}

fracao soma(fracao fracao1, fracao fracao2){
    fracao resultado;
    resultado.numerador = (fracao1.numerador * fracao2.denominador) + (fracao2.numerador * fracao1.denominador);
    resultado.denominador = fracao1.denominador * fracao2.denominador;

    simplifica(&resultado);
    
    return resultado;
}
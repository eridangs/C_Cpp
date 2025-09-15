#include <stdio.h>

void funcao(char *vetor);

int main(){
    int a, *aptr;
    float f, *fptr;
    char vetor[10];

    a = 9;
    aptr = &a;

    const int PI = 3.14; // por referencia, o valor é um ponteiro - recomendado
    int const PI = 3.14;

    // const int &const > p;

    funcao(vetor); // -- o endereço da memoria é que é passado


    // -------- ARITMETICA DE PONTEIRO -------------------------

    int a = 3000, *p;

    a += 2; // = 3002

    p += 2; // = 3008, pois foi a multiplicao dos bytes do tipo do ponteiro (nesse caso int(4))

    // ---------VETOR e PONTEIRO--------------------------------

    int *a = "Teste";
    int a[] = "Teste2";

    // Matriz
    void f( int a[][9]);
    void j(int **a);


    
    return 0;
}


void funcao(char *vetor){ //aloca o endereço do ponteiro localmente

}
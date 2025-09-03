#include <stdio.h>

int main(){
    float *q, b;
    b = 3.14;
    //q = &b; -- necessário para funcionar
    *q = *q + 1.0;
    printf("*q = %f\n", *q);
    //Essa execuxão causa falha de segmento
    //Pois o *q não está apontando para um endereço conhecido da memória
    return 0;
}

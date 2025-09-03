#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v ;

    v = ( int *) malloc(10 * sizeof(int));
    printf("Size of int %zu\n", sizeof(int));
    return 0;
}

//Define um ponteiro v
//Faz o casting para garantir o tipo do vetor
//Faz com que esse ponteiro seja um vetor
//O tamanho desse vetor é de 40
//Pois é 10 vezes o tamanho de um int
//Faltou o free() ao final
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, *v;

    v = numeros;

    for (i = 10; i > -1; i--){
        printf("%d\n", v[i]);
    }
    printf("Fogo!");

    return 0;
}
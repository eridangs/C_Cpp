#include <stdio.h>

int main(){
    int x, y;
    int *p, *q;

    x = 2;
    y = 8;

    p = &x;
    q = &y;

    printf("Endereco x %p e Valor x %d\n", x, x);
    printf("Valor p %d e valor de p* %d\n", p, *p);
    printf("Endereco y %p e valor de y %d\n", y, y);
    printf("Endereco p %p\n", p);

    return 0;
}
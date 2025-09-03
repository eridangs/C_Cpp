#include <stdio.h>
int main ( ) {
    int *p , a ;
    a = 10;
    p = &a ;//Recebe o endereço e passa a guardar a
    printf("p = %d e a = %d\n", *p, a); //*p é a própria variável a
    *p = *p * 2 ;
    printf("a = %d\n", a);//a após a multiplicação
    printf("Endereco de a guardado por p = %p\n", *p); //
    printf("Endereco de a = %p\n", a); //Se mantém o mesmo
    printf("Endereco de p na memoria = %p\n", p);//Muda constantemente
    return 0 ;
}
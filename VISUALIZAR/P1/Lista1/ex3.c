#include <stdio.h>

int main(){
    int a, b, c, maior = 0, menor = 0;
    printf("Digite 3 números inteiros:\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c){
        maior = a;
    } else if (b >= a && b >= c){
        maior = b;
    } else {
        maior = c;
    }

    if (a <= b && a <= c){
        menor = a;
    } else if (b <= a && b <= c){
        menor = a;
    } else{
        menor = c;
    }
    printf("Maior: %d \nMenor: %d" , maior, menor);
    return 0;
}
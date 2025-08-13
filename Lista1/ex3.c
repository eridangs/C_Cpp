#include <stdio.h>
int main(){
    int a, b, c, maior, menor;
    printf("Digite 3 números:\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c){
        maior = a;
        if (b > c){
            menor = c;
        }
        else {
            menor = b;
        }
    }
    else if (b > a && b > c){
        maior = b;
        if (a > c) {
            menor = c;
        }
        else {
            menor = a;
        }
    }
    else if (c > a && c > b){
        maior = c;
        if (a > b){
            menor = b;
        }
        else {
            menor = a;
        }
    }

    printf("Maior: %d \nMenor: %d" , maior, menor);


    return 0;
}
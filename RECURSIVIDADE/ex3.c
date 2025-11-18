#include <stdio.h>

int digitos(int n);


int main(){
    int n;
    printf("Digite um número: ");
    scanf("%d",&n);

    printf("%d tem ",n);
    n = digitos(n);
    printf("%d digitos.\n",n);
    return 0;
}

int digitos(int n){

    if (n < 10){
        return 1;
    }
    else {
        return digitos(n/10) + 1;
    }
}

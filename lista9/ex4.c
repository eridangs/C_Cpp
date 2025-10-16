#include <stdio.h>

int impar(int n);


int main(){
    int n;
    printf("Digite um número: ");
    scanf("%d",&n);
    if (n % 2 == 0) n = n-1;

    impar(n);

    return 0;
}

int impar(int n){
    int i = n;

    if (n < 0){
        return 1;
    }
    else {
        printf("%d\n", n);
        return impar(n -2);
    }
}

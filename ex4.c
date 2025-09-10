#include <stdio.h>
#include <stdlib.h>

void gera_sequencia();

void gera_sequencia(){
    int i = 0, termo1 = 0, termo2 = 1, proximo;
    FILE *fib;
    fib = fopen("30_fib.txt", "w");

    for(i;i<30;i++){
        if(i <= 1){ 
            proximo = i;
        } else{
            proximo = termo1 + termo2;
            termo1 = termo2;
            termo2 = proximo;
        }
        fprintf(fib, "%d\n", proximo);
    }

}

int main(){

    gera_sequencia();


    return 0;
}
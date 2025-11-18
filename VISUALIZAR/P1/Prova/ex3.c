#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *lotr_imp;
    FILE *lotr_par;
    FILE *lotr_recovered;
    char linha_impar[256], linha_par[256];
    int i = 0, controle = 1;


    lotr_imp = fopen("lotr_cap1_odd.txt", "r");
    if (lotr_imp == NULL){
        perror("Erro ao abrir o arquivo");
    }

    lotr_par = fopen("lotr_cap1_even.txt", "r");
    if (lotr_par == NULL){
        perror("Erro ao abrir o arquivo");
    }

    lotr_recovered = fopen("lotr_cap1_recovered.txt", "w");
    
    while(1){
        controle = 0;

        if (fgets(linha_impar, 256, lotr_imp) != NULL){

            if (lotr_recovered == NULL){
                perror("Erro ao abrir o arquivo");
                break;
            }
            else{
                fputs(linha_impar, lotr_recovered);
            }
        }
        else{ controle += 1; }

        if (fgets(linha_par, 256, lotr_par) != NULL){

            if (lotr_recovered == NULL){
                perror("Erro ao abrir o arquivo");
                break;
            }
            else{
                fputs(linha_par, lotr_recovered);
            }

        } else{ controle += 1; }

        if (controle > 1){
            break;
        }
    }
    
    fclose(lotr_recovered);
    
    fclose(lotr_imp);
    fclose(lotr_par);
    
    return 0;
}
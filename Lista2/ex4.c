#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    FILE *matriz;
    int i, j, m, n, num;
    
    printf("Digite o número de linhas e colunas da Matriz, respectivamente\n");
    scanf("%d%*c %d%*c", &m, &n);

    matriz = fopen("Escrita.txt", "w+");
    if(matriz == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            num = (rand() %2);
            fprintf(matriz, "%d   ", num);
        }
        fprintf(matriz, "\n");
    }
    
    rewind(matriz);

    int linha, Ncol = 0;
    for (i = 0; i < m; i++){
        linha = 0;
        for (j = 0; j < m; j++){
            fscanf(matriz, "%d", &num);
            if(num == 0){
                linha += 1;
            }
        }
        if(linha == m) Ncol += 1;
    }
    
    printf("A matriz tem %d colunas zeradas!", Ncol);
    fclose(matriz);
    
    return 0;

}
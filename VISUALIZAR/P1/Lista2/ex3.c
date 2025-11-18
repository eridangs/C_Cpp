#include <stdio.h>
#include <stdlib.h>

void transposta(int *Matriz, int *T, int, int);

int main(){
    int *Matriz;
    int *T;
    int i, j, m, n;

    printf("Digite o número de linhas e colunas da Matriz, respectivamente\n");
    scanf("%d%*c %d%*c", &m, &n);

    Matriz = (int *) malloc(m*n);
    T = (int *) malloc(n*m);

    printf("Digite os valores da Matriz %d x %d:\n", m, n);
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("%d%*c", &Matriz[i * n + j]); // * n se eu quiser andar de coluna em coluna
        }
    }

    printf("\nMatriz original\n");
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("%d   ", Matriz[i * n + j]);
        }
        printf("\n");
    }


    transposta(Matriz, T, m, n);

    printf("\nMatriz transposta:\n");
    for (j = 0; j < n; j++){
        for (i = 0; i < m; i++){
            printf("%d   ", T[j * m + i]); // * m se eu quero andar de linha em linha
        }
        printf("\n");
    }

    free(Matriz);
    free(T);
    return 0;
}

void transposta(int *Matriz, int *T, int m, int n) {
    int i, j;

    for (i = 0; i < m; i++){ //2

        for (j = 0; j < n; j++){ //3

            T[j * m + i] = Matriz[i * n + j];
        }
    }
}

#include <stdio.h>
#define M 2 //linhas
#define N 3 //colunas

void transposta(int Matriz[M][N], int T[N][M]);

int main(){
    int Matriz[M][N];
    int T[N][M];
    int i, j;

    printf("Digite os valores da Matriz %d x %d:\n", M, N);
    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            scanf("%d%*c", &Matriz[i][j]);
        }
    }

    printf("\nMatriz original\n");
    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            printf("%d   ", Matriz[i][j]);
        }
        printf("\n");
    }


    transposta(Matriz, T);

    printf("\nMatriz transposta:\n");
    for (j = 0; j < N; j++){
        for (i = 0; i < M; i++){
            printf("%d   ", T[j][i]);
        }
        printf("\n");
    }

    return 0;
}

void transposta(int Matriz[M][N], int T[N][M]) {
    int i, j;

    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            T[j][i] = Matriz[i][j];
        }
    }
}

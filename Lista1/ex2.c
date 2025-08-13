# include <stdio.h>

int main(){
    int velocidade;
    printf("Qual a velocidade do veiculo? ");
    scanf("%d", &velocidade);
    if (velocidade > 80){
        int acima = velocidade - 80, multa = acima * 5;
        printf("A multa é de: %d  reais!\n", multa);
    }else{
        printf("A sua velocidade é: %d  km/h!\n", velocidade);
    }

    return 0;
}
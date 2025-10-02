# include <stdio.h>
#define const 5

int main(){
    int velocidade = 0, multa = 0;
    printf("Qual a velocidade do veiculo?\n");
    scanf("%d", &velocidade);
    
    if(velocidade > 80){
        int excesso = velocidade - 80;
        multa = excesso * const;
        printf("A multa é de: %d  reais!\n", multa);
    }else{
        printf("A sua velocidade é: %d  km/h!\n", velocidade);
    }

    return 0;
}
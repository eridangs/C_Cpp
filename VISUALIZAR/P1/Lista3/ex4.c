#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 15

// Struct //
typedef struct{
    int num_conta;
    char nome[50];
    double saldo;
} conta;
// Struct //


// Funções //
int menu(int);
int cadastrar(int, conta *);
void mostrar_nomes(int, conta *);
int descrobrir_menor(int, int, conta *);
void inverte_ordem(int, conta *);
// Funções //


int main(){
    conta registro_bancario[TAM];
    int op = 0, i = 0, menor_indice = 0, valido = 0;
    
    while(1){
        op = menu(op);
        printf("Opção %d selecionada\n", op);
        printf("Quantidade de contas cadastradas: %d\n",i);
        if (op == 4){
            break;
        } else {
            switch(op) {
                case 1:
                    if (i < 15){
                        valido = cadastrar(i, registro_bancario);
                        if (valido){
                            i ++;
                        }
                        else{
                            printf("Não foi possivel cadastrar essa conta!\n");
                        }
                    } else {
                        printf("Quantidade de registros bancários chegou ao límite!\nExclua alguma conta para adicionar mais!\n");
                    }
                break;
                

                case 2:
                    if (i >= 1){
                        mostrar_nomes(i, registro_bancario);
                    } else{
                        printf("Há menos de 1 contas cadastradas!\n");
                    }
                break;
                

                case 3:
                    if (i > 1){
                        menor_indice = descrobrir_menor(menor_indice, i, registro_bancario);
                        if (menor_indice < 15){
                            inverte_ordem(menor_indice, registro_bancario);
                            i -= 1;
                        } else{
                            printf("Não foi possivel excluir nenhuma conta, pois há mais de 1 conta com o menor saldo!\n");
                        }
                    } else {
                        printf("Há menos de 2 contas cadastradas, não é possivel remover a conta com menor saldo!\n");
                    }
                break;
    }}}
    return 0;
}
    
int menu(int op){
    printf("Digite o número da escolha:\n1 - Cadastrar contas\n2 - Visualizar todas as contas de determinado cliente\n3 - Excluir conta com menor saldo\n4 - Sair\n");
    scanf("%d", &op);
    return op;
}

int cadastrar(int i, conta *registro_bancario){
    int j = 0;
    printf("Adicione os dados:\nNúmero da conta: ");
    scanf("%d", &registro_bancario[i].num_conta);

    for (j = i - 1; j >= 0; j--){
        if (registro_bancario[i].num_conta == registro_bancario[j].num_conta){
            registro_bancario[i].num_conta = 0.0;
            printf("Esse número de conta já esta sendo usado por outro cliente, escolha outro número.\n");
            return 0;
        }
    }

    printf("Nome: ");
    getchar();
    fgets(registro_bancario[i].nome, 50, stdin);

    printf("Saldo: ");
    scanf("%lf", &registro_bancario[i].saldo);
    printf("Conta %d criada com sucesso!\n", i + 1);
    return 1;
}

void mostrar_nomes(int i, conta *registro_bancario){
    int j = 0, nome_certo = 0;
    char nome_clie[50];

    printf("\n--- TODOS OS CLIENTES CADASTRADOS ---\n");
    for (j = 0; j < i; j++){
        printf("- %s", registro_bancario[j].nome);
    }
    printf("Digite o nome do cliente que deseja visualizar a conta: ");
    getchar();
    fgets(nome_clie, 50, stdin);

    for (j = 0; j < i; j++ ){
        if (strcmp(nome_clie, registro_bancario[j].nome) == 0){
            nome_certo = 1;
            printf("Dados bancarios de %s", nome_clie);
            printf("Conta: %d\n", registro_bancario[j].num_conta);
            printf("Nome: %s", registro_bancario[j].nome);
            printf("Saldo: R$ %.2lf\n", registro_bancario[j].saldo);
        }
    }
    if (nome_certo == 0){printf("\nNome digitado incorreto ou não está cadastrado!\n");}

}

int descrobrir_menor(int menor_indice, int i, conta *registro_bancario){
    double menor_saldo = 0.0;
    int j;
    
    menor_saldo = registro_bancario[0].saldo;
    for (j = 1; j < i; j++){
        if (registro_bancario[j].saldo < menor_saldo){
        menor_saldo = registro_bancario[j].saldo;
        menor_indice = j;
        
        } else if (registro_bancario[j].saldo == menor_saldo){
            menor_indice = 15;
        }
    }
    return menor_indice;
}

void inverte_ordem(int menor_indice, conta *registro_bancario){
    int j = 0;
    for (j = menor_indice; j < TAM; j++ ){
        registro_bancario[j] = registro_bancario[j + 1];
    }
}
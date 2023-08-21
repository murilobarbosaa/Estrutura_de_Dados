#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int numeroConta;
    char nomeCliente[50];
    double saldo;
} ContaBancaria;

ContaBancaria contas[15];  // Usaremos um tamanho fixo para o array de contas
int numContas = 0;

int encontrarIndiceConta(int numeroConta) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == numeroConta) {
            return i;
        }
    }
    return -1;
}

void cadastrarConta() {
    if (numContas >= 15) {
        printf("Limite máximo de contas atingido.\n");
        return;
    }

    ContaBancaria novaConta;
    printf("Número da conta: ");
    scanf("%d", &novaConta.numeroConta);

    if (encontrarIndiceConta(novaConta.numeroConta) != -1) {
        printf("Já existe uma conta com esse número.\n");
        return;
    }

    printf("Nome do cliente: ");
    scanf("%s", novaConta.nomeCliente);

    printf("Saldo: ");
    scanf("%lf", &novaConta.saldo);

    contas[numContas] = novaConta;
    numContas++;

    printf("Conta cadastrada com sucesso!\n");
}

void visualizarContasPorCliente() {
    char nomeAlvo[50];
    printf("Digite o nome do cliente: ");
    scanf("%s", nomeAlvo);

    printf("Contas do cliente %s:\n", nomeAlvo);
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].nomeCliente, nomeAlvo) == 0) {
            printf("Número da conta: %d, Saldo: %.2lf\n", contas[i].numeroConta, contas[i].saldo);
        }
    }
}

void excluirContaComMenorSaldo() {
    if (numContas == 0) {
        printf("Não há contas para excluir.\n");
        return;
    }

    int indiceMenorSaldo = 0;
    for (int i = 1; i < numContas; i++) {
        if (contas[i].saldo < contas[indiceMenorSaldo].saldo) {
            indiceMenorSaldo = i;
        }
    }

    printf("Conta com menor saldo excluída:\n");
    printf("Número da conta: %d, Saldo: %.2lf\n", contas[indiceMenorSaldo].numeroConta, contas[indiceMenorSaldo].saldo);

    for (int i = indiceMenorSaldo; i < numContas - 1; i++) {
        contas[i] = contas[i + 1];
    }
    numContas--;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        printf("\nMenu de opções:\n");
        printf("1. Cadastrar contas\n");
        printf("2. Visualizar todas as contas de determinado cliente\n");
        printf("3. Excluir a conta com menor saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta();
                break;
            case 2:
                visualizarContasPorCliente();
                break;
            case 3:
                excluirContaComMenorSaldo();
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

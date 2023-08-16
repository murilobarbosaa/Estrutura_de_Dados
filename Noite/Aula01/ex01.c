#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[100];
    float saldo;
} Conta;

void cadastrarConta(Conta contas[], int *totalContas) {
    int maxContas = 15;

    if (*totalContas >= maxContas) {
        printf("Limite de contas cadastradas atingido \n");
        return;
    }

    Conta novaConta;

    printf("Digite o numero da conta: ");
    scanf("%d", &novaConta.numero);

    for (int i = 0; i < *totalContas; i++) {
        if (contas[i].numero == novaConta.numero) {
            printf("Ja existe uma conta com esse numero. \n");
            return;
        }
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novaConta.nome);

    printf("Digite o saldo da conta: ");
    scanf("%f", &novaConta.saldo);

    contas[*totalContas] = novaConta;
    (*totalContas)++;

    printf("Conta cadastrada com sucesso!\n");
}

void visualizarConta(Conta contas[], int totalContas) {
    char busca[100];

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", busca);

    printf("Contas de %s: \n", busca);

    int encontrados = 0;
    for (int i = 0; i < totalContas; i++) {
        if (strcmp(contas[i].nome, busca) == 0) {
            printf("Conta: %d, Saldo: %.2f \n", contas[i].numero, contas[i].saldo);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma conta foi encontrada para o cliente %s. \n", busca);
    }
}

void excluirConta(Conta contas[], int *totalContas) {
    if (*totalContas == 0) {
        printf("Nao ha contas cadastradas\n");
        return;
    }

    int menorSaldo = 0;

    for (int i = 0; i < *totalContas; i++) {
        if (contas[i].saldo < contas[menorSaldo].saldo) {
            menorSaldo = i;
        }
    }

    printf("Conta excluida: %d \n", contas[menorSaldo].numero);

    for (int i = menorSaldo; i < *totalContas - 1; i++) {
        contas[i] = contas[i + 1];
    }

    (*totalContas)--;
}

int main() {
    Conta contas[15];
    int totalContas = 0;
    int opcao;

    do {
        printf("-------------------------------\n");
        printf("|            AGENDA           |\n");
        printf("-------------------------------\n");
        printf("| 1 - Adicionar um contato.   |\n");
        printf("| 2 - Excluir um contato.     |\n");
        printf("| 3 - Exibir contato.         |\n");
        printf("| 4 - Encerrar o programa.    |\n");
        printf("|-----------------------------|\n");

        printf("Qual operacao deseja realizar? ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta(contas, &totalContas);
                break;
            case 2:
                excluirConta(contas, &totalContas);
                break;
            case 3:
                visualizarConta(contas, totalContas);
                break;
            case 4:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente \n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

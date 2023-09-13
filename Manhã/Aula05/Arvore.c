// Programa que Implementa uma Árvore de Ordem 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

// Declaração de Estruturas
struct no {
    int numero;
    struct no *filho1;
    struct no *filho2;
    struct no *filho3;
    struct no *filho4;
    struct no *filho5;
};

// Função que Insere um Nó
struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        // Caso Fácil: A Árvore Está Vazia
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> filho1 = NULL;
        raiz -> filho2 = NULL;
        raiz -> filho3 = NULL;
        raiz -> filho4 = NULL;
        raiz -> filho5 = NULL;
    }
    else {
        // Caso Difícil : A Árvore não Está vazia
        int sorteio = (rand() % 5);

        if (sorteio == 0) {
            raiz -> filho1 = inserir(raiz -> filho1, numero);
        }
        else if (sorteio == 1) {
            raiz -> filho2 = inserir(raiz -> filho2, numero);
        }
        else if (sorteio == 2) {
            raiz -> filho3 = inserir(raiz -> filho3, numero);
        }
        else if (sorteio == 3) {
            raiz -> filho4 = inserir(raiz -> filho4, numero);
        }
        else if (sorteio == 4) {
            raiz -> filho5 = inserir(raiz -> filho5, numero);
        }
    }
    return raiz;
};

// Função que Imprime a Árvore
void imprimir(struct no *raiz, char *endentacao) {
    if (raiz != NULL) {
        printf("%s %d\n", endentacao, raiz -> numero);

        char *temp = (char *)malloc(1024 * sizeof(char));
        strcpy(temp, " --- ");
        strcat(temp, endentacao);

        imprimir(raiz -> filho1, temp);
        imprimir(raiz -> filho2, temp);
        imprimir(raiz -> filho3, temp);
        imprimir(raiz -> filho4, temp);
        imprimir(raiz -> filho5, temp);
    }
}

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicialização da Aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    // Declaração da Raiz
    struct no *raiz = NULL;

    // Declaração do Endentador
    char *endentador = (char *)malloc(1024 * sizeof(char));
    strcpy(endentador, "");

    // Menu de Opções
    int opcao = 0;
    while (opcao != 3) {
        printf("+================+\n");
        printf("| Menu de opções |\n");
        printf("+================+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Imprimir  |\n");
        printf("|  3 - Sair      |\n");
        printf("+================+\n");
        printf("\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int numero = 0;
            printf("Digite o número:");
            scanf("%d", &numero);
            printf("\n");
            raiz = inserir(raiz, numero);
        }
        else if (opcao == 2) {
            printf("\n");
            imprimir(raiz, endentador);
            printf("\n");
        }
    }
}

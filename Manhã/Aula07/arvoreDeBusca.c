// Programa que Implemeta uma Árvore de Busca
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Declaração de Estruturas
struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

// Função que Insere um Nó na Árvore
struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    }
    else {
        if (numero < raiz -> numero) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        }
        else if (numero > raiz -> numero){
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }
    return raiz;
};

// Função que Busca um Nó na Árvore
void buscar(struct no *raiz, int numero) {
    if (raiz == NULL) {
        printf("Não achei");
    }
    else if (raiz -> numero == numero){
        printf("Achei");
    }
    else if (numero < raiz -> numero) {
        buscar(raiz -> esquerda, numero);
    }
    else {
        buscar(raiz -> direita, numero);
    }
}

// Função que Navega a Árvore em Ordem
void navegar(struct no *raiz) {
    if (raiz != NULL) {
        navegar(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegar(raiz -> direita);
    }
}

// Função que Desenha um Menu na Tela
int menu() {
    int opcao;

    printf("\n");
    printf("+==================+\n");
    printf("| -Menu de Opções- |\n");
    printf("+==================+\n");
    printf("| 1 - Inserir      |\n");
    printf("| 2 - Buscar       |\n");
    printf("| 3 - Navegar      |\n");
    printf("| 4 - Construir    |\n");
    printf("| 5 - Sair         |\n");
    printf("+==================+\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

// Função Principal de Execução do Código
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Declaraçõ de Variáveis
    struct no *raiz = NULL;
    int opcao = 0;
    int numero = 0;
    int i = 0;

    // Inicializaçõ da Aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    // Manipulaçção da Árvore
    while (opcao != 5) {
        opcao = menu();
        switch (opcao){
            case 1:
                printf("Digite o número: ");
                scanf("%d", &numero);

                raiz = inserir(raiz, numero);
                break;

            case 2:
                printf("Digite o número: ");
                scanf("%d", &numero);

                buscar(raiz, numero);
                break;

            case 3:
                navegar(raiz);
                break;

            case 4:
                for (i = 0; i < 10000000000; i++) {
                    raiz = inserir(raiz, rand());

                }
                break;

        }
    }
}

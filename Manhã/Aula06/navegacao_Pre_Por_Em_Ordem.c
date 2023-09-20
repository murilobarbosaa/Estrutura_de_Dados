// Progamaa que Implementa uma Árvore Binária e suas Respectivas Navegações

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
    // Caso fácil
    if (raiz == NULL) {
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    }
    // Caso Difícil
    else {
        if ((rand() % 2) == 0) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        }
        else {
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};

// Navegação em PRÉ-ORDEM
void navegarPreOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

// Navegação EM_ORDEM
void navegarEmOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarEmOrdem(raiz -> esquerda);
        navegarEmOrdem(raiz -> direita);
    }
}

// Navegação PÓS_ORDEM
void navegarPosOrdem(struct no *raiz) {
    if (raiz != NULL) {
        navegarPosOrdem(raiz -> esquerda);
        navegarPosOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Declaração de Variáveis
    struct no *raiz = NULL;

    // Inicialização da Aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    // Preenchimento da Árvore
    for (long int i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    // Navegações
    printf("=============================== PRÉ-ORDEM ===============================\n");
    navegarPreOrdem(raiz);


    printf("\n================================ EM-ORDEM ===============================\n");
    navegarEmOrdem(raiz);


    printf("\n=============================== PÓS-ORDEM ===============================\n");
    navegarPosOrdem(raiz);
}

// Árvore Rubro-Negra
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declaração da Struct
struct no {
    int numero;
    int cor;  // 0: preto  -  1: vermelho
    struct no* direita;
    struct no* esquerda;
};

// Função que Rotaciona a Árvore à Esquerda
struct no *rotacionarEsquerda(struct no *raiz) {
    // Rotação Propriamente Dita
    struct no *temp = raiz -> direita;
    raiz -> direita = temp -> esquerda;
    temp -> esquerda = raiz;

    // Ajuste da Cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    // Retorno
    return temp;
};

// Função que Rotaciona a Árvore à Direita
struct no *rotacionarDireita(struct no *raiz) {
    // Rotação Propriamente Dita
    struct no *temp = raiz -> esquerda;
    raiz -> esquerda = temp -> direita;
    temp -> direita = raiz;

    // Ajuste da Cor
    temp -> cor = raiz -> cor;
    raiz -> cor = 1;

    // Retorno
    return temp;
};

// Função que Sobe o Vermelho
void subirVermelho(struct no *raiz) {
    raiz -> cor = 1;
    raiz -> esquerda -> cor = 0;
    raiz -> direita -> cor = 0;
}

// Função que Determina a Cor do Nó
int vermelho(struct no *raiz) {
    int retorno = 0;

    if (raiz != NULL) {
        retorno = raiz -> cor;
    }

    return retorno;
}

// Função que Insere um Nó na Árvore
struct no *inserir(struct no *raiz, int numero) {
    // Inserção Como Árvore de Busca
    if (raiz == NULL) {
        raiz = (struct no*) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        raiz -> cor = 1;
    }
    else {
        if (numero < raiz -> numero) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        }
        else {
            raiz -> direita = inserir(raiz -> direita, numero);
        }

    }

    // Balanceamento da Árvore
    if ((! vermelho(raiz -> esquerda)) && (vermelho (raiz -> direita))) {
        raiz = rotacionarEsquerda(raiz);
    }

    if (vermelho(raiz -> esquerda) && vermelho(raiz -> esquerda -> esquerda)) {
        raiz = rotacionarDireita(raiz);
    }

    if (vermelho(raiz -> esquerda) && vermelho(raiz -> direita)) {
        subirVermelho(raiz);
    }

    // Retorno
    return raiz;
}

// Função que Imprime a Árvore
void imprimir(struct no *raiz, char *endentacao) {
    if (raiz != NULL) {
        printf("%s%d\n", endentacao, raiz -> numero);

        char *temp = (char *) malloc(1024 * sizeof(char));
        strcpy(temp, "---");
        strcat(temp, endentacao);

        imprimir(raiz -> esquerda, temp);
        imprimir(raiz -> direita, temp);
    }
}

// Função Principal de Execução do Código
int main() {
    setlocale(LC_ALL, "Portuguese");

    struct no *raiz = NULL;
    int i = 0;

    for (i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    imprimir(raiz, "");

    return 0;
}

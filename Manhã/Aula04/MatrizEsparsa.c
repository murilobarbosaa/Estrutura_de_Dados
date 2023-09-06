// Programa Que Implementa Uma Matriz Esparsa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Declaração de Constantes
const int MODULO = 3;

// Declaração de Estruturas
struct no {
    int numero;
    struct no *proximoNo;
};

struct diretor{
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

// Declaração de Variáveis
struct diretor *cabeca = NULL;

// Função Que Procura o Diretor Certo
struct diretor *procurarDiretor(int resto) {
    struct diretor *ponteiro = cabeca;

    // Varrendo a lista até encontrar o resto certo ou chegar no final
    while ((ponteiro != NULL) && (ponteiro -> resto != resto)) {
        ponteiro = ponteiro -> proximoDiretor;
    }

    if (ponteiro == NULL) {
        // Criar um diretor novo
        ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
        ponteiro -> resto = resto;
        ponteiro -> proximoNo = NULL;
        ponteiro -> proximoDiretor = cabeca;

        cabeca = ponteiro;
    }

    return ponteiro;
};

// Função Que Insere um Nó na Matriz Esparsa
void inserir(int numero) {
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    struct no *novoNo = (struct no *) malloc(sizeof(struct no));

    novoNo -> numero = numero;
    novoNo -> proximoNo = ponteiroDiretor -> proximoNo;

    ponteiroDiretor -> proximoNo = novoNo;
}

//Função Que Imprime a Matriz Esparsa
void imprimir() {
    struct diretor *ponteiroDiretor = cabeca;

    printf("============= Matriz Esparsa =============\n");
    while(ponteiroDiretor != NULL) {
        struct no *ponteiroNo = ponteiroDiretor -> proximoNo;

        printf("%d:\t", ponteiroDiretor -> resto);
        while(ponteiroNo != NULL) {
            printf("%d\t", ponteiroNo -> numero);
            ponteiroNo = ponteiroNo -> proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
}

// Função Que Remove um Elemento da Matriz
void remover(int numero) {
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    if (ponteiroDiretor -> proximoNo != NULL) {
        if (ponteiroDiretor -> proximoNo -> numero == numero) {
            // Caso fácil, excluir o primeiro no da lista
            struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
            ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
            free(ponteiroExcluir);
        }
        else {
            // Caso Difícil, excluir algum no meio da lista
            struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;

            while((ponteiroAnterior -> proximoNo != NULL) && (ponteiroAnterior -> proximoNo -> numero != numero)) {
                ponteiroAnterior = ponteiroAnterior -> proximoNo;
            }

            if (ponteiroAnterior -> proximoNo != NULL) {
                struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
                ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
                free(ponteiroExcluir);
            }
        }
    }
}

// Função Principal de Execuçãod o Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    time_t t;
    int numero = 0;

    srand((unsigned)time(&t));
    for (int i = 0; i < 10; i++) {
        inserir(rand());
    }
    imprimir();

    while (numero != -1) {
        printf(" -> Digite um número para excluir ou -1 para sair: ");
        scanf("%d", &numero);
        printf("\n");

        remover(numero);

        imprimir();
    }
}


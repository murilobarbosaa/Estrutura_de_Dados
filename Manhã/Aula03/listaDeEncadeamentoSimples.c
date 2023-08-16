// Programa de Lista de Encadeamento Simples
#include <stdio.h>
#include <stdlib.h>

// Declaração da Estrutura do Nó
struct no {
    int numero;
    struct no *proximo;
};

// Declaração de Variáveis
struct no *cabeca = NULL;

// Função que Insere um Nó na Lista
void inserir(int numero) {
    // Alocação do Espaço de Memória
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    if (cabeca == NULL) {
        // Caso Fácil, a Lista Está Vazia
        cabeca = novoNo;
    }
    else {
        // Caso Difícil a Lista NÃO Está Vazia
        struct no *ponteiro = cabeca;

        while (ponteiro -> proximo != NULL) {
            ponteiro = ponteiro -> proximo;
        }

        ponteiro -> proximo = novoNo;
    }
}

// Função que Imprime os Nós da Lista
void imprimir() {
    printf("==========================\n");

    struct no *ponteiro = cabeca;

    while (ponteiro != NULL) {
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

// Função que Exclui o Nó da Lista
void remover(int numero) {
    if (cabeca != NULL) {
        if (cabeca -> numero == numero) {
            // Caso Fácil, Excluir o primeiro Elemento da Lista
            struct no *ponteiroExcluir = cabeca;
            cabeca = cabeca -> proximo;
            free (ponteiroExcluir);
        }
        else {
            // Caso Difícil, Excluir Algum Elemento no Meio da Lista
            struct no *ponteiroAnterior = cabeca;
            while ((ponteiroAnterior -> proximo != NULL) && (ponteiroAnterior -> proximo -> numero != numero)) {
                ponteiroAnterior = ponteiroAnterior -> proximo;
            }

            if (ponteiroAnterior -> proximo != NULL) {
                struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
                ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
                free(ponteiroExcluir);
            }
        }
    }
}

// Função Principal de Execução do Programa
int main(int argc, char *argv[]) {
    int opcao = 0;
    int numero = 0;

    while (opcao != 4) {
        printf("+----------------+\n");
        printf("| Menu de opcoes |\n");
        printf("+----------------+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Remover   |\n");
        printf("|  3 - Imprimir  |\n");
        printf("|  4 - Sair      |\n");
        printf("+----------------+\n");
        printf("Digite a opcao: ")/
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            inserir(numero);
            break;
        case 2:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            remover(numero);
            break;
        case 3:
            imprimir();
            break;
        }
    }
}

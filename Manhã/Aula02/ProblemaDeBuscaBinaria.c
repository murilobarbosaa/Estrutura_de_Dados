// Problema de Busca Binária
#include <stdio.h>
#include <locale.h>

// Declaração de Variáveis
int vetor[10000];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 9999;
int meio = 0;

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicialização da Memória
    for (i = 0; i < 10000; i++) {
        vetor[i] = i;
    }

    // Perguntar o Parâmetro de busca
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &busca);

    // Busca Propriamente Dita
    while (fim >= inicio) {
        meio = (inicio + fim) / 2;

        if (busca == vetor[meio]) {
            printf("Achei na posição %d\n", meio);
            return 0;
        }
        else if (busca > vetor[meio]) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    printf("Não existe");

}
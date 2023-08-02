// Problema de Ordenação BubbleSort
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declaração de Variáveis
int vetor[10000];
int i = 0;
int troquei = 1;

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicialização da Memória
    for (i = 0; i < 10000; i++) {
        vetor[i] = (rand() % 10000);
    }

    // Impressão do Vetor
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

    // Ordenação Propriamente Dita
    while (troquei) {
        troquei = 0;
        for (i = 0; i < 9999; i++) {
            if (vetor[i] > vetor[i+1]) {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                troquei = 1;
            }
        }
    }

    // Impressão do Vetor Ordenado
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

}

// Problema de Ordenação Direta
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declaração de Variáveis
int vetor[10000];
int i = 0;
int j = 0;

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
    for (i = 0; i < 9999; i++) { // Do Primeiro ao Penúltimo
        for (j = (i + 1) ; j < 10000; j++) { // Do Próximo ao ùltimo
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    // Impressão do Vetor Ordenado
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

}

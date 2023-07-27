// Programa de Preenchimento de Vetor
#include <stdio.h>
#include <locale.h>

// Declaração das Variáveis
int vetor[10];
int i = 0;

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicialização da Memória
    for (i = 0; i < 10; i++) {
        vetor[i] = 0;
    }

    // Preenchimento do Vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &vetor[i]);
    }

    // Impressão do Vetor
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor[%d] = %d \n", i, vetor[i]);
    }

}

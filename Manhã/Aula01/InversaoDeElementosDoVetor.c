// Programa de Inversão de Elementos do vetor
#include <stdio.h>
#include <locale.h>

// Declaração das Variáveis
int vetorOriginal[10];
int vetorInvertido[10];
int i = 0;

// Função Principal de Execução do Programa
int main () {
    setlocale(LC_ALL, "Portuguese");
    // Inicialização de Memória
    for (i = 0; i < 10; i++) {
        vetorOriginal[i] = 0;
        vetorInvertido[i] = 0;
    }

    // Preenchimento do Vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &vetorOriginal[i]);
    }

    // Inversão do Vetor
    printf("\n");
    for (i = 9; i >= 0; i--) {
        vetorInvertido[9 - i] = vetorOriginal[i];
    }

    // Impressão dos Vetores
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor [%d] = %d \n", i, vetorOriginal[i]);
    }

    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor [%d] = %d \n", i, vetorInvertido[i]);
    }

}

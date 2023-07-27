// Programa Criação de Matriz Transposta
#include <stdio.h>
#include <locale.h>

// Declaração das Variáveis
int matriz[2][3];
int transposta[3][2];
int i = 0;
int j = 0;

// Função Principal de Execução do Código
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicialização da Memória
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = 0;
            transposta[j][i] = 0;
        }
    }

    // Introdução dos Valores na Matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o valor para a linha %d e coluna %d da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");

    // Transpondo a Matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Impressão das Matrizes
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", transposta[i][j]);
        }
        printf("\n");
    }

}

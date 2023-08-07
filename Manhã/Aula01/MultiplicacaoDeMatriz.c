// Programa de Multiplicação de Matrizes
#include <stdio.h>
#include <locale.h>

// Declaração de Variáveis
int operando1[2][3];
int operando2[3][2];
int resultado[2][2];
int i = 0;
int j = 0;
int k = 0;

// Função Principal de Execução do Código
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicialização da Memória
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            operando1[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            operando2[i][j] = 0;
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            resultado[i][j] = 0;
        }
    }

    // Preenchimento dos Operandos
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("operando1[%d, %d] = ", i, j);
            scanf("%d", &operando1[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("operando2[%d, %d] = ", i, j);
            scanf("%d", &operando2[i][j]);
        }
    }

    // Multiplicação Propriamente Dita
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                resultado[i][j] += (operando1[i][k] * operando2[k][j]);
            }
        }
    }

    // Impressão do Resultado
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", resultado[i][j]);
        }
        printf("\n");
    }
}

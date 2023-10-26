// Programa que Implementa um Grafo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição de constantes
const int TAMANHO = 10;

// Função que Cria o Grafo
void criar(int grafo[TAMANHO][TAMANHO], int aleatorio) {
    // Declaração de Variáveis
    int i = 0;
    int j = 0;
    int amigo = 0;

    // Inicialização do Grafo
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            grafo[i][j] = 0;
        }
    }

    // Definição das Conexões do Grafo

    for (i = 0; i < TAMANHO - 1; i++) {
        for (j = i + 1; j < TAMANHO; j++) {
            if (!aleatorio) {
                printf("Digite 1 caso %d seja amigo de %d: ", i, j);
                scanf("%d", &amigo);
            }
            else {
                amigo = (rand() % 2);
            }

            grafo[i][j] = amigo;
            grafo[j][i] = amigo;
        }
    }

}

// Função que Imprime o Grafo
void imprimir(int grafo[TAMANHO][TAMANHO]) {
    // Declaração de Variáveis
    int i = 0;
    int j = 0;

    // Impressão Propriamente Dita
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d\t", grafo[i][j]);
        }
        printf("\n");
    }
}

// Função que Descobre o Vértice de Maior Grau
int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
    // Declaração de Variáveis
    int i = 0;
    int j = 0;
    int contador = 0;
    int maior = 0;
    int vertice = 0;

    // Navegação do Grafo
    for (i = 0; i < TAMANHO; i++) {
        contador = 0;
        for (j = 0; j < TAMANHO; j++) {
            if (grafo[i][j]) {
                contador++;
            }
        }
        if (contador > maior) {
            maior = contador;
            vertice = i;
        }
    }

    // Retorno
    return vertice;
}

// Função Principal de Execução do Código
int main() {
    time_t t;
    srand((unsigned) time(&t));
    // Declaração de Variáveis
    int grafo[TAMANHO][TAMANHO];

    criar(grafo, 1);

    imprimir(grafo);

    printf("Vertice mais popular : %d\n", descobrirVerticeMaiorGrau(grafo));

    return 0;
}


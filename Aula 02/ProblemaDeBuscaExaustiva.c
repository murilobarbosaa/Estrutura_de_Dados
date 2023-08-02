// Problema de Busca Exaustiva
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declaração de Variáveis
int vetor[10000];
int i = 0;
int busca = 0;
int achei = -1;

// Função Principal de Execução do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicialização da Memória
    for (i = 0; i < 10000; i++) {
        vetor[i] = (rand() % 10000);
    }

    // Perguntar o Parâmetro de busca
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &busca);

    // Busca Propriamente Dita
    for (i = 0; i < 10000; i++) {
        if (vetor[i] == busca) {
            achei = i;
        }
        else {

        }
    }

    if (achei == -1) {
        printf("Não Existe!");
    }
    else {
        printf("Achei na posição %d", achei);
    }
}

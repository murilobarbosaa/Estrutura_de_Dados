#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    float vendas[3]; // Novembro, Dezembro, Janeiro
    float vendasTotais;
    float pontosTotais;
} Funcionario;

void calcularVendasEPontosTotais(Funcionario *funcionario) {
    for (int i = 0; i < 3; i++) {
        funcionario->vendasTotais += funcionario->vendas[i];
        funcionario->pontosTotais += funcionario->vendas[i] / 1000.0;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Funcionario funcionarios[15];
    char nomesMeses[3][20] = {"Novembro", "Dezembro", "Janeiro"};
    float vendasTotais = 0.0;
    float maxPontos = 0.0;
    char nomeMaxPontos[50];

    for (int i = 0; i < 15; i++) {
        printf("Informe o nome do funcionário %d: ", i + 1);
        scanf("%s", funcionarios[i].nome);
        funcionarios[i].vendasTotais = 0.0;
        funcionarios[i].pontosTotais = 0.0;

        for (int j = 0; j < 3; j++) {
            printf("Informe as vendas de %s (%s): ", funcionarios[i].nome, nomesMeses[j]);
            scanf("%f", &funcionarios[i].vendas[j]);
        }

        calcularVendasEPontosTotais(&funcionarios[i]);

        vendasTotais += funcionarios[i].vendasTotais;

        if (funcionarios[i].pontosTotais > maxPontos) {
            maxPontos = funcionarios[i].pontosTotais;
            strcpy(nomeMaxPontos, funcionarios[i].nome);
        }
    }

    printf("\nPontuação do Funcionário em cada mês:\n");
    for (int i = 0; i < 15; i++) {
        printf("%s:", funcionarios[i].nome);
        for (int j = 0; j < 3; j++) {
            printf(" %.2f", funcionarios[i].vendas[j] / 1000.0);
        }
        printf("\n");
    }

    printf("\nTotal de Pontos do Funcionário:\n");
    for (int i = 0; i < 15; i++) {
        printf("%s: %.2f pontos\n", funcionarios[i].nome, funcionarios[i].pontosTotais);
    }

    printf("\nFuncionário com mais pontos: %s (%.2f pontos)\n", nomeMaxPontos, maxPontos);
    printf("\nVendas totais: %.2f\n", vendasTotais);

    return 0;
}

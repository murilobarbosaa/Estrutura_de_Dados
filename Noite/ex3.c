#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Produto {
    int codigo;
    char descricao[100];
    float precoCompra;
    float precoVenda;
    int quantidade;
    int estoqueMinimo;
};

void cadastrarProduto(struct Produto estoque[], int *numProdutos) {
    struct Produto novoProduto;

    printf("Código do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Descrição do produto: ");
    scanf(" %[^\n]", novoProduto.descricao);
    printf("Preço de compra: ");
    scanf("%f", &novoProduto.precoCompra);
    printf("Preço de venda: ");
    scanf("%f", &novoProduto.precoVenda);
    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Estoque mínimo: ");
    scanf("%d", &novoProduto.estoqueMinimo);

    estoque[*numProdutos] = novoProduto;
    (*numProdutos)++;

    printf("Produto cadastrado com sucesso!\n");
}

void calcularLucro(struct Produto produto) {
    float lucro = (produto.precoVenda - produto.precoCompra) * produto.quantidade;
    float percentualLucro = (lucro / (produto.precoCompra * produto.quantidade)) * 100;

    printf("Lucro obtido: R$ %.2f\n", lucro);
    printf("Percentual de lucro: %.2f%%\n", percentualLucro);
}

void mostrarProdutosAbaixoEstoqueMinimo(struct Produto estoque[], int numProdutos) {
    printf("Produtos com estoque abaixo do mínimo:\n");

    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].quantidade < estoque[i].estoqueMinimo) {
            printf("Código: %d\n", estoque[i].codigo);
            printf("Descrição: %s\n", estoque[i].descricao);
            printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
            printf("Estoque mínimo: %d\n\n", estoque[i].estoqueMinimo);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Produto estoque[100];
    int numProdutos = 0;
    int opcao;

    do {
        printf("===== Controle de Estoque =====\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Calcular Lucro de Produto\n");
        printf("3. Mostrar Produtos Abaixo do Estoque Mínimo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int codigoProduto;
        switch (opcao) {
            case 1:
                cadastrarProduto(estoque, &numProdutos);
                break;
            case 2:
                printf("Digite o código do produto: ");
                scanf("%d", &codigoProduto);

                for (int i = 0; i < numProdutos; i++) {
                    if (estoque[i].codigo == codigoProduto) {
                        calcularLucro(estoque[i]);
                        break;
                    }
                }
                break;
            case 3:
                mostrarProdutosAbaixoEstoqueMinimo(estoque, numProdutos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

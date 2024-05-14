#include <stdio.h>

// Definição da estrutura Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Função para calcular o valor total em estoque
float calcularTotal(struct Produto produtos[], int tamanho) {
    float total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += produtos[i].preco * produtos[i].quantidade;
    }
    return total;
}

int main() {
    // Definindo um array de produtos com capacidade para armazenar até 100 produtos
    struct Produto produtos[100];
    int opcao, numProdutos = 0;

    do {
        // Menu de opções
        printf("\n1. Cadastrar produto\n");
        printf("2. Exibir produtos cadastrados\n");
        printf("3. Calcular valor total em estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cadastrar produto
                printf("\nNome do produto: ");
                scanf("%s", produtos[numProdutos].nome);
                printf("Preco do produto: ");
                scanf("%f", &produtos[numProdutos].preco);
                printf("Quantidade em estoque: ");
                scanf("%d", &produtos[numProdutos].quantidade);
                numProdutos++;
                break;
            case 2:
                // Exibir produtos cadastrados
                printf("\nProdutos cadastrados:\n");
                for (int i = 0; i < numProdutos; i++) {
                    printf("Nome: %s, Preco: %.2f, Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
                }
                break;
            case 3:
                // Calcular valor total em estoque
                printf("\nValor total em estoque: %.2f\n", calcularTotal(produtos, numProdutos));
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do registro de funcionário
struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

// Função de comparação para ordenar por idade
int compararPorIdade(const void *a, const void *b) {
    const struct Funcionario *funcionarioA = (const struct Funcionario *)a;
    const struct Funcionario *funcionarioB = (const struct Funcionario *)b;

    return funcionarioA->idade - funcionarioB->idade;
}

// Função para ler os dados de um funcionário
void lerFuncionario(struct Funcionario *funcionario) {
    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario->nome);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario->idade);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario->salario);
}

// Função para imprimir o array de funcionários
void imprimirFuncionarios(struct Funcionario *funcionarios, int numFuncionarios) {
    printf("\n=== Lista de Funcionarios Ordenados por Idade ===\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].salario);
    }
    printf("==============================================\n");
}

int main() {
    int numFuncionarios;

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numFuncionarios);

    // Aloca espaço para o array de funcionários
    struct Funcionario *funcionarios = (struct Funcionario *)malloc(numFuncionarios * sizeof(struct Funcionario));

    // Lendo os dados dos funcionários
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        lerFuncionario(&funcionarios[i]);
    }

    // Ordenando o array de funcionários por idade
    qsort(funcionarios, numFuncionarios, sizeof(struct Funcionario), compararPorIdade);

    // Imprimindo os funcionários ordenados
    imprimirFuncionarios(funcionarios, numFuncionarios);

    // Liberando a memória alocada
    free(funcionarios);

    return 0;
}

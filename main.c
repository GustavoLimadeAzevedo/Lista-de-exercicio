#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do registro de funcionário
struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

// Função para adicionar um novo registro
void adicionarRegistro(FILE *arquivo) {
    struct Funcionario funcionario;

    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario.nome);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    fwrite(&funcionario, sizeof(struct Funcionario), 1, arquivo);
}

// Função para listar todos os registros
void listarRegistros(FILE *arquivo) {
    struct Funcionario funcionario;

    rewind(arquivo); // Voltando para o início do arquivo

    printf("\n=== Lista de Funcionarios ===\n");
    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
    printf("=============================\n");
}

// Função para buscar por registros específicos pelo nome
void buscarPorNome(FILE *arquivo) {
    struct Funcionario funcionario;
    char nomeBusca[50];
    int encontrado = 0;

    printf("Digite o nome a ser buscado: ");
    scanf("%s", nomeBusca);

    rewind(arquivo); // Voltando para o início do arquivo

    while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.nome, nomeBusca) == 0) {
            printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Funcionario com o nome '%s' nao encontrado.\n", nomeBusca);
    }
}

int main() {
    FILE *arquivo;
    int opcao;

    arquivo = fopen("funcionarios.bin", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar registro\n");
        printf("2. Listar registros\n");
        printf("3. Buscar por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarRegistro(arquivo);
                break;
            case 2:
                listarRegistros(arquivo);
                break;
            case 3:
                buscarPorNome(arquivo);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while(opcao != 4);

    fclose(arquivo);

    return 0;
}

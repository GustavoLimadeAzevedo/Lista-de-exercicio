#include <stdio.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Declaração do array com o tamanho informado
    int array[tamanho];

    // Solicita ao usuário inserir os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Calcula a soma dos elementos do array
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    // Imprime a soma dos elementos
    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}

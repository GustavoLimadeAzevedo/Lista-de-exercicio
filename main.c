#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array utilizando ponteiros
int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int*)malloc(tamanho * sizeof(int));

    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    int *ptrOriginal = array + tamanho - 1;
    int *ptrInvertido = arrayInvertido;

    while (ptrOriginal >= array) {
        *ptrInvertido = *ptrOriginal;
        ptrOriginal--;
        ptrInvertido++;
    }

    return arrayInvertido;
}

// Função para imprimir um array
void imprimirArray(int *array, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int*)malloc(tamanho * sizeof(int));

    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array original: ");
    imprimirArray(array, tamanho);

    int *arrayInvertido = inverterArray(array, tamanho);

    printf("Array invertido: ");
    imprimirArray(arrayInvertido, tamanho);

    // Liberando a memória alocada
    free(array);
    free(arrayInvertido);

    return 0;
}

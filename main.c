#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros (usada no qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função para calcular a média
double calcular_media(int arr[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
    }
    return (double)soma / n;
}

// Função para calcular a mediana
double calcular_mediana(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

// Função para calcular a moda
int calcular_moda(int arr[], int n) {
    int max_count = 0, moda = arr[0], count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                moda = arr[i - 1];
            }
            count = 1;
        }
    }

    if (count > max_count) {
        moda = arr[n - 1];
    }

    return moda;
}

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double media = calcular_media(arr, n);
    double mediana = calcular_mediana(arr, n);
    int moda = calcular_moda(arr, n);

    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}

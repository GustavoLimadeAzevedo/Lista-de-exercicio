#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz de tamanho rows x cols
int** alocaMatriz(int rows, int cols) {
    int **matriz;
    matriz = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matriz[i] = (int *)malloc(cols * sizeof(int));
    }
    return matriz;
}

// Função para desalocar uma matriz alocada dinamicamente
void liberaMatriz(int **matriz, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para multiplicação de matrizes
int** multiplicaMatrizes(int **matriz1, int **matriz2, int rows1, int cols1, int cols2) {
    int **resultado = alocaMatriz(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

// Função para transposição de uma matriz
int** transpoeMatriz(int **matriz, int rows, int cols) {
    int **transposta = alocaMatriz(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    return transposta;
}

// Função para imprimir uma matriz
void imprimeMatriz(int **matriz, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Digite o número de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Digite o número de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("As matrizes não podem ser multiplicadas. O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
        return 1;
    }

    int **matriz1 = alocaMatriz(rows1, cols1);
    int **matriz2 = alocaMatriz(rows2, cols2);

    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    printf("Matriz resultante da multiplicação:\n");
    int **resultado = multiplicaMatrizes(matriz1, matriz2, rows1, cols1, cols2);
    imprimeMatriz(resultado, rows1, cols2);

    printf("Matriz transposta da primeira matriz:\n");
    int **transposta = transpoeMatriz(matriz1, rows1, cols1);
    imprimeMatriz(transposta, cols1, rows1);

    // Libera a memória alocada para as matrizes
    liberaMatriz(matriz1, rows1);
    liberaMatriz(matriz2, rows2);
    liberaMatriz(resultado, rows1);
    liberaMatriz(transposta, cols1);

    return 0;
}

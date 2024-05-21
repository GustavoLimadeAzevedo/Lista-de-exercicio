#include <stdio.h>
#include <time.h>

// Função para simular um trecho de código que leva tempo para executar
void trecho_de_codigo() {
    // Simulação de trabalho: um loop que faz algo
    for (volatile int i = 0; i < 100000000; i++) {
        // Este loop não faz nada útil, apenas gasta tempo
    }
}

int main() {
    // Variáveis para armazenar o tempo de início e fim
    clock_t inicio, fim;
    double tempo_gasto;

    // Captura o tempo de início
    inicio = clock();

    // Trecho de código cujo tempo de execução será medido
    trecho_de_codigo();

    // Captura o tempo de fim
    fim = clock();

    // Calcula o tempo gasto em segundos
    tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    // Imprime o tempo gasto
    printf("O trecho de código levou %f segundos para executar.\n", tempo_gasto);

    return 0;
}

#include <stdio.h>

// Função para converter uma string para maiúsculas
char* converteMaiusculas(char *string) {
    char *ptr = string; // Ponteiro para percorrer a string

    // Percorre a string até encontrar o caractere nulo que indica o final da string
    while (*ptr != '\0') {
        // Verifica se o caractere atual está dentro do intervalo 'a'-'z' (minúsculas)
        if (*ptr >= 'a' && *ptr <= 'z') {
            // Converte o caractere para maiúscula subtraindo a diferença entre 'a' e 'A'
            *ptr = *ptr - ('a' - 'A');
        }
        // Move para o próximo caractere na string
        ptr++;
    }

    // Retorna a string após a conversão
    return string;
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    scanf("%[^\n]", string);

    // Chama a função para converter a string para maiúsculas
    char *resultado = converteMaiusculas(string);

    // Imprime a string convertida
    printf("String convertida para maiúsculas: %s\n", resultado);

    return 0;
}

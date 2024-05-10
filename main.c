#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    int vogais = 0;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    // Percorre a string para contar as vogais
    for (int i = 0; string[i] != '\0'; i++) {
        // Verifica se o caractere atual é uma vogal (maiúscula ou minúscula)
        if (string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' ||
            string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' ||
            string[i] == 'u' || string[i] == 'U') {
            vogais++;
        }
    }

    printf("O número de vogais na string é: %d\n", vogais);

    return 0;
}

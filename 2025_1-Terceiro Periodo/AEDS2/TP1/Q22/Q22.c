#include <stdio.h>
#include <string.h>

// Função recursiva para somar os dígitos de uma string
int soma(char str[], int index) {
    // Caso base: se index for igual ao tamanho da string, retorna 0
    if (index == strlen(str)) {
        return 0;
    }
    // Converte o caractere atual em número e soma ao resultado recursivo
    int r = str[index] - '0';
    return r + soma(str, index + 1);
}

int main() {
    char str[100];

    // Loop para ler entradas até o usuário digitar "FIM"
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "FIM") == 0) {
            break;
        }
        // Chama a função recursiva, começando do índice 0
        int r = soma(str, 0);
        printf("%d\n", r);
    }

    return 0;
}

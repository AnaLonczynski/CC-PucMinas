#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Realiza a troca dos caracteres de maneira iterativa
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];  // Supondo que o tamanho máximo da string será 100 caracteres

    while (1) {
        fgets(str, sizeof(str), stdin);
        
        // Remover o caractere de nova linha da entrada, se presente
        str[strcspn(str, "\n")] = 0;
        
        // Se a entrada for "FIM", o programa termina
        if (strcmp(str, "FIM") == 0) {
            break;
        }

        // Chama a função reverse para inverter a string
        reverse(str);

        // Imprime a string invertida
        printf("%s\n", str);
    }

    return 0;
}

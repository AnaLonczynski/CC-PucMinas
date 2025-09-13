#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função recursiva para verificar se uma string é um palíndromo
int isPalindromeRecursive(const char* str, int left, int right) {
	// Caso base: se os índices se cruzarem, a string é um palíndromo
	if (left >= right) {
		return 1;
	}
	
	// Ignora caracteres não alfabéticos no início da string
	if (!isalpha(str[left]) || (unsigned char)str[left] >= 127) {
		return isPalindromeRecursive(str, left + 1, right);
	}
	
	// Ignora caracteres não alfabéticos no final da string
	if (!isalpha(str[right]) || (unsigned char)str[right] >= 127) {
		return isPalindromeRecursive(str, left, right - 1);
	}
	
	// Compara os caracteres convertidos para minúsculas
	if (tolower(str[left]) != tolower(str[right])) {
		return 0; // Não é palíndromo
	}
	
	// Recursão para os próximos caracteres
	return isPalindromeRecursive(str, left + 1, right - 1);
}

int main() {
	char line[1000]; // Supondo que o tamanho máximo da linha seja 999 caracteres
	
	while (fgets(line, sizeof(line), stdin)) {
		// Remove o caractere de nova linha, se presente
		line[strcspn(line, "\n")] = '\0';
		
		if (strcmp(line, "FIM") == 0) {
			break;
		}
		
		if (isPalindromeRecursive(line, 0, strlen(line) - 1)) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	
	return 0;
}


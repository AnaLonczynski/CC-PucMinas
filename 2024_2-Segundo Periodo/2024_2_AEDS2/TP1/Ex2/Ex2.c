#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string é um palíndromo
int isPalindrome(const char* str) {
	int left = 0;
	int right = strlen(str) - 1;
	
	while (left < right) {
		// Ignora caracteres não alfabéticos
		while (left < right && (!isalpha(str[left]) || (unsigned char)str[left] >= 127)) {
			left++;
		}
		while (left < right && (!isalpha(str[left]) || (unsigned char)str[left] >= 127)) {
			right--;
		}
		
		// Compara os caracteres convertidos para minúsculas
		if (tolower(str[left]) != tolower(str[right])) {
			return 0; // Não é palíndromo
		}
		
		left++;
		right--;
	}
	
	return 1; // É palíndromo
}

int main() {
	char line[1000]; // Supondo que o tamanho máximo da linha seja 999 caracteres
	
	while (fgets(line, sizeof(line), stdin)) {
		// Remove o caractere de nova linha, se presente
		line[strcspn(line, "\n")] = '\0';
		
		if (strcmp(line, "FIM") == 0) {
			break;
		}
		
		if (isPalindrome(line)) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//oi

// Função recursiva que verifica se uma string é um palíndromo
int isPalindrome(char palavra[], int inicio, int fim) {
	// Caso base: se o início for maior ou igual ao fim, a palavra é um palíndromo
	if (inicio >= fim) {
		return 1; // Retorna 1 (verdadeiro) se for palíndromo
	}
	
	// Ignorar caracteres não alfabéticos e considerar minúsculas
	if (!isalnum(palavra[inicio])) {
		return isPalindrome(palavra, inicio + 1, fim);
	}
	if (!isalnum(palavra[fim])) {
		return isPalindrome(palavra, inicio, fim - 1);
	}
	
	// Comparar os caracteres nas extremidades, ignorando maiúsculas e minúsculas
	if (tolower(palavra[inicio]) != tolower(palavra[fim])) {
		return 0; // Retorna 0 (falso) se não for palíndromo
	}
	
	// Chamada recursiva para as extremidades internas da string
	return isPalindrome(palavra, inicio + 1, fim - 1);
}

int main() {
	char entrada[1001]; // O tamanho máximo da string é 1000 caracteres
	int resp;
	
	// Lê as linhas até a entrada ser "FIM"
	while (1) {
		fgets(entrada, sizeof(entrada), stdin);
		
		// Remover o caractere de nova linha (\n) se existir
		entrada[strcspn(entrada, "\n")] = '\0';
		
		// Se a palavra for "FIM", encerra o programa
		if (strcmp(entrada, "FIM") == 0) {
			break;
		}
		
		// Chama a função recursiva para verificar se é palíndromo
		resp = isPalindrome(entrada, 0, strlen(entrada) - 1);
		
		// Imprime "SIM" se for palíndromo, "NAO" caso contrário
		if (resp) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	
	return 0;
}



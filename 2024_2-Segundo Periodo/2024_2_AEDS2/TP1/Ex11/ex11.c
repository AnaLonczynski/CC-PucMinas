#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função recursiva para verificar se uma string é um palíndromo
int isPalindrome(char *str, int left, int right) {
	// Ignorar caracteres fora do intervalo ASCII (< 127) ou espaços (32)
	while (left < right && (!(str[left] < 127 && str[left] != 32))) {
		left++;
	}
	while (left < right && (!(str[right] < 127 && str[right] != 32))) {
		right--;
	}
	
	// Condição base: se os ponteiros se cruzarem ou se encontrarem, é um palíndromo
	if (left >= right) {
		return 1;
	}
	
	// Verificar se os caracteres nas posições atuais são iguais (ignorando maiúsculas/minúsculas)
	if (tolower(str[left]) != tolower(str[right])) {
		return 0;
	}
	
	// Chamada recursiva para os próximos caracteres
	return isPalindrome(str, left + 1, right - 1);
}

int main() {
	char palavra[100];
	
	do {
		// Ler a palavra
		fgets(palavra, sizeof(palavra), stdin);
		
		// Remover o newline do final da string
		palavra[strcspn(palavra, "\n")] = '\0';
		
		if (strcmp(palavra, "FIM") != 0) {
			int resp = isPalindrome(palavra, 0, strlen(palavra) - 1);
			if (resp) {
				printf("SIM\n");
			} else {
				printf("NAO\n");
			}
		}
	} while (strcmp(palavra, "FIM") != 0);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para substituir recursivamente uma letra por outra na string
void substitui(char *str, char escolhida, char substituta, int index) {
	if (index < strlen(str)) {
		if (str[index] == escolhida) {
			str[index] = substituta;
		}
		substitui(str, escolhida, substituta, index + 1);
	}
}

// Função para gerar letras aleatórias
char geraLetraAleatoria() {
	return 'a' + rand() % 26;
}

// Função principal
int main() {
	char palavra[100];
	srand(time(NULL));
	
	// Lê a primeira palavra
	fgets(palavra, 100, stdin);
	palavra[strcspn(palavra, "\n")] = '\0'; // Remove o '\n' do final
	
	while (strcmp(palavra, "FIM") != 0) {
		char escolhida = geraLetraAleatoria();
		char substituta = geraLetraAleatoria();
		
		// Chamada da função de substituição
		substitui(palavra, escolhida, substituta, 0);
		
		// Imprime a palavra modificada
		printf("%s\n", palavra);
		
		// Lê a próxima palavra
		fgets(palavra, 100, stdin);
		palavra[strcspn(palavra, "\n")] = '\0'; // Remove o '\n' do final
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	int n, i;
	FILE *file;
	
	// Leitura do número de valores
	scanf("%d", &n);
	
	// Abre o arquivo para escrita
	file = fopen("dados.txt", "w");
	if (file == NULL) {
		perror("Não foi possível abrir o arquivo para escrita");
		return 1;
	}
	
	// Leitura dos valores reais e escrita no arquivo
	for (i = 0; i < n; i++) {
		float valor;
		scanf("%f", &valor);
		fprintf(file, "%f\n", valor);
	}
	
	// Fecha o arquivo após a escrita
	fclose(file);
	
	// Abre o arquivo para leitura
	file = fopen("dados.txt", "r");
	if (file == NULL) {
		perror("Não foi possível abrir o arquivo para leitura");
		return 1;
	}
	
	// Move o ponteiro do arquivo para o final
	fseek(file, 0, SEEK_END);
	
	// Leitura dos valores de trás para frente e exibição
	for (i = 0; i < n; i++) {
		// Move o ponteiro para a posição do valor atual
		fseek(file, -1 * (i + 1) * sizeof(float), SEEK_END);
		float valor;
		fread(&valor, sizeof(float), 1, file);
		printf("%f\n", valor);
	}
	
	// Fecha o arquivo
	fclose(file);
	
	return 0;
}

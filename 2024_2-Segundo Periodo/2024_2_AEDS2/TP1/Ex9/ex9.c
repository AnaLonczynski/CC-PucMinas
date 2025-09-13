#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Função auxiliar para posicionar o ponteiro
long seekPreviousLine(FILE *fp, long pointer) {
	if (pointer == 0) return 0;// Se já está no início do arquivo
	
	fseek(fp, --pointer, SEEK_SET);
	
	while (pointer > 0) {
		fseek(fp, --pointer, SEEK_SET);
		if (fgetc(fp) == '\n') {
			pointer++;
			break;
		}
	}
	
	return pointer;
}

int main() {
	int n;
	double valor;
	FILE *fp;
	char line[MAX_LINE_LENGTH];
	
	// Lendo a quantidade de valores
	scanf("%d", &n);
	n++;
	
	// Escrevendo os valores no arquivo
	fp = fopen("valores.txt", "wt");
	if (fp == NULL) {
		printf("Erro ao abrir o arquivo para escrita.\n");
		return 1;
	}
	
	for (int i = 0; i < n-1; i++) {
		scanf("%lf", &valor);
		fprintf(fp, "%g\n", valor);  // %g desconsidera zeros não significativos
	}
	
	fclose(fp);
	
	// Lendo os valores de trás para frente
	fp = fopen("valores.txt", "rt");
	if (fp == NULL) {
		printf("Erro ao abrir o arquivo para leitura.\n");
		return 1;
	}
	
	fseek(fp, 0, SEEK_END);
	long pointer = ftell(fp);  // Tamanho total do arquivo
	
	for (int i = 0; i < n; i++) {
		pointer = seekPreviousLine(fp, pointer);
		fseek(fp, pointer, SEEK_SET);  // Posiciona corretamente no início da linha
		if (fgets(line, sizeof(line), fp) != NULL) {
			valor = atof(line);
			if (valor == (int)valor) {
				printf("%d\n", (int)valor);  // Imprime como inteiro se terminar em .0
			} else {
				printf("%g\n", valor);  // %g desconsidera zeros não significativos
			}
		}
	}
	
	fclose(fp);
	
	return 0;
}

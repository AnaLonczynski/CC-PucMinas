#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STR_LEN 100
#define MAX_POKEMONS 801

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	int id, geracao, taxaCaptura;
	char nome[MAX_STR_LEN], descricao[MAX_STR_LEN];
	char tipos[2][MAX_STR_LEN], habilidades[20][MAX_STR_LEN];
	double peso, altura;
	bool lendario;
	Data dataCaptura;
} Pokemon;

typedef struct {
	int tamanho, inicio, fim;
	Pokemon buffer[MAX_POKEMONS + 1];
} FilaCircular;

FilaCircular* inicializarFilaCircular() {
	FilaCircular* fila = (FilaCircular*)malloc(sizeof(FilaCircular));
	fila->inicio = fila->fim = fila->tamanho = 0;
	return fila;
}

void adicionarElemento(FilaCircular* fila, Pokemon pokemon, int posicao) {
	if (fila->tamanho >= MAX_POKEMONS || posicao > fila->tamanho || posicao < 0) {
		printf("Erro: %s\n", posicao > fila->tamanho || posicao < 0 ? "Posição inválida!" : "Fila cheia!");
		return;
	}
	
	for (int i = fila->tamanho; i > posicao; i--) {
		fila->buffer[i] = fila->buffer[i - 1];
	}
	fila->buffer[posicao] = pokemon;
	fila->tamanho++;
}

Pokemon removerElemento(FilaCircular* fila, int posicao) {
	Pokemon removido;
	if (fila->tamanho <= 0 || posicao >= fila->tamanho || posicao < 0) {
		printf("Erro: %s\n", posicao >= fila->tamanho || posicao < 0 ? "Posição inválida!" : "Fila vazia!");
		return removido;
	}
	
	removido = fila->buffer[posicao];
	for (int i = posicao; i < fila->tamanho - 1; i++) {
		fila->buffer[i] = fila->buffer[i + 1];
	}
	fila->tamanho--;
	return removido;
}

void mostrarFila(FilaCircular* fila) {
	for (int i = 0; i < fila->tamanho; i++) {
		printf("[%d] %s\n", i, fila->buffer[i].nome);
	}
}

Pokemon criarClone(Pokemon pkmOriginal) {
	Pokemon clone = pkmOriginal; // Copia os campos diretamente
	return clone;
}

Pokemon buscarPokemonPorID(Pokemon* pokemons, int id, int total) {
	for (int i = 0; i < total; i++) {
		if (pokemons[i].id == id) return pokemons[i];
	}
	Pokemon vazio = { .id = -1 }; 
	return vazio;
}

Pokemon* carregarPokemons(const char* nomeArquivo, int* totalPokemons) {
	FILE* arquivo = fopen(nomeArquivo, "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo.\n");
		return NULL;
	}
	
	Pokemon* pokemons = malloc(MAX_POKEMONS * sizeof(Pokemon));
	char linha[512];
	fgets(linha, sizeof(linha), arquivo); // Ignora o cabeçalho
	int index = 0;
	
	while (fgets(linha, sizeof(linha), arquivo)) {
		Pokemon pkm = {0};
		int lendario;
		sscanf(linha, "%d,%d,%[^,],%[^,],%[^,],%[^,],%lf,%lf,%d,%d",
			&pkm.id, &pkm.geracao, pkm.nome, pkm.descricao, pkm.tipos[0], pkm.tipos[1],
			&pkm.peso, &pkm.altura, &pkm.taxaCaptura, &lendario);
		pkm.lendario = lendario == 1;
		pokemons[index++] = pkm;
	}
	
	fclose(arquivo);
	*totalPokemons = index;
	return pokemons;
}

void exibirPokemon(Pokemon pkm) {
	printf("[%d] %s - %s | Peso: %.1f kg | Altura: %.1f m\n",
		pkm.id, pkm.nome, pkm.descricao, pkm.peso, pkm.altura);
}

int main() {
	int totalPokemons;
	Pokemon* pokemons = carregarPokemons("/tmp/pokemon.csv", &totalPokemons);
	if (!pokemons) return 1;
	
	FilaCircular* fila = inicializarFilaCircular();
	char comando[100];
	while (scanf("%s", comando) && strcmp(comando, "FIM") != 0) {
		int id;
		sscanf(comando, "%d", &id);
		Pokemon encontrado = buscarPokemonPorID(pokemons, id, totalPokemons);
		if (encontrado.id != -1) {
			adicionarElemento(fila, encontrado, fila->tamanho);
		}
	}
	
	mostrarFila(fila);
	free(pokemons);
	free(fila);
	return 0;
}


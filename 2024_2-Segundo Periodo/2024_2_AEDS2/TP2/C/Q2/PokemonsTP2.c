#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 
#define TAMANHO 801

// Estrutura de data
typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

// Estrutura do Pokémon
typedef struct {
	int identificador;
	int geracao;
	char nome[MAX];
	char descricao[MAX];
	char tipos[2][MAX];
	char habilidades[20][MAX];
	double peso;
	double altura;
	int taxaCaptura;
	bool lendario;  
	Data dataCaptura;
} Pokemon;

// Setters
void definirID(int id, Pokemon pokemon){pokemon.identificador = id;}
void definirGeracao(int geracao, Pokemon pokemon){pokemon.geracao = geracao;}
void definirNome(char nome[], Pokemon pokemon){strcpy(pokemon.nome, nome);}
void definirDescricao(char descricao[], Pokemon pokemon){strcpy(pokemon.descricao, descricao);}
void definirTipos(char tipo1[], char tipo2[], Pokemon pokemon){strcpy(pokemon.tipos[0], tipo1); strcpy(pokemon.tipos[1], tipo2);}
void definirHabilidades(char** habilidades, Pokemon pokemon) {
	int i = 0;
	while (habilidades[i][0] != '\0') {
		strcpy(pokemon.habilidades[i], habilidades[i]);
		i++;
	}
}
void definirPeso(double peso, Pokemon pokemon){pokemon.peso = peso;}
void definirAltura(double altura, Pokemon pokemon){pokemon.altura = altura;}
void definirTaxaCaptura(int taxa, Pokemon pokemon){pokemon.taxaCaptura = taxa;}
void definirLendario(bool lendario, Pokemon pokemon){pokemon.lendario = lendario;}
void definirData(int dia, int mes, int ano, Pokemon pokemon){pokemon.dataCaptura.dia = dia; pokemon.dataCaptura.mes = mes; pokemon.dataCaptura.ano = ano;}

// Getters
int obterID(Pokemon pokemon) {
	return pokemon.identificador;
}

int obterGeracao(Pokemon pokemon) {
	return pokemon.geracao;
}

char* obterNome(Pokemon pokemon) {
	return pokemon.nome;
}

char* obterDescricao(Pokemon pokemon) {
	return pokemon.descricao;
}

char** obterTipos(Pokemon pokemon) {
	char** tipos = malloc(2 * sizeof(char));
	tipos[0] = pokemon.tipos[0];
	tipos[1] = pokemon.tipos[1];
	return tipos;
}

char** obterHabilidades(Pokemon pokemon) {
	int i = 0;
	char** clone = malloc(20 * sizeof(char));
	while (pokemon.habilidades[i][0] != '\0') {
		strcpy(clone[i], pokemon.habilidades[i]);
		i++;
	}
	clone[i][0] = '\0';
	return clone;
}

double obterPeso(Pokemon pokemon) {
	return pokemon.peso;
}

double obterAltura(Pokemon pokemon) {
	return pokemon.altura;
}

int obterTaxaCaptura(Pokemon pokemon) {
	return pokemon.taxaCaptura;
}

bool obterLendario(Pokemon pokemon) {
	return pokemon.lendario;
}

void obterData(Pokemon pokemon, int *dia, int *mes, int *ano) {
	*dia = pokemon.dataCaptura.dia;
	*mes = pokemon.dataCaptura.mes;
	*ano = pokemon.dataCaptura.ano;
}

// Função clone
Pokemon clonarPokemon(Pokemon original) {
	Pokemon clone;
	clone.identificador = original.identificador;
	clone.geracao = original.geracao;
	strcpy(clone.nome, original.nome);
	strcpy(clone.descricao, original.descricao);
	strcpy(clone.tipos[0], original.tipos[0]);
	strcpy(clone.tipos[1], original.tipos[1]);
	
	int i = 0;
	while (original.habilidades[i][0] != '\0') {
		strcpy(clone.habilidades[i], original.habilidades[i]);
		i++;
	}
	clone.habilidades[i][0] = '\0';
	
	clone.peso = original.peso;
	clone.altura = original.altura;
	clone.taxaCaptura = original.taxaCaptura;
	clone.lendario = original.lendario;
	clone.dataCaptura = original.dataCaptura;
	return clone;
}

// Função para procurar um Pokémon pelo ID
Pokemon buscarPokemon(Pokemon* pokemons, int id) {
	for (int i = 0; i < TAMANHO; i++) {
		if (pokemons[i].identificador == id) {
			return pokemons[i];
		}
	}
	
	Pokemon pokemon;
	pokemon.identificador = -1;
	return pokemon;
}

// Função para ler o arquivo CSV e carregar os Pokémons
Pokemon* carregarArquivo(char nomeArquivo[]) {
	Pokemon* pokemons = (Pokemon*)malloc(TAMANHO * sizeof(Pokemon));
	
	FILE* arquivo = fopen(nomeArquivo, "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo.\n");
		return NULL;
	}
	
	char lixo[200];
	fgets(lixo, sizeof(lixo), arquivo); // Pular o cabeçalho
	
	char linha[500];
	int lendario;
	int index = 0;
	
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		char habilidades[MAX] = " ";
		Pokemon temp = { .tipos = { " ", " " } };
		
		// Processar a linha
		sscanf(linha, "%d;%d;%[^;];%[^;];%[^;];%[^;]", 
			&temp.identificador, &temp.geracao, temp.nome, temp.descricao, temp.tipos[0], temp.tipos[1]);
		
		// Outros dados
		char resto[100];
		sscanf(linha, "%[^[][%[^]]]%s", lixo, habilidades, resto);
		
		char dividir[10][100];
		int m = 0, j = 0;
		
		for (int i = 1; i < strlen(resto); i++) {
			if (resto[i] != ';') {
				dividir[m][j++] = resto[i];
			} else {
				dividir[m++][j] = '\0';
				j = 0;
			}
		}
		
		sscanf(dividir[1], "%lf", &temp.peso);
		sscanf(dividir[2], "%lf", &temp.altura);
		sscanf(dividir[3], "%d", &temp.taxaCaptura);
		sscanf(dividir[4], "%d", &lendario);
		sscanf(dividir[5], "%d/%d/%d", &temp.dataCaptura.dia, &temp.dataCaptura.mes, &temp.dataCaptura.ano);
		
		// Processar habilidades
		m = 0;
		j = 0;
		for (int i = 0; i < strlen(habilidades); i++) {
			if (habilidades[i] != '\'') {
				temp.habilidades[m][j++] = habilidades[i];
			} else {
				temp.habilidades[m++][j] = '\0';
				j = 0;
			}
		}
		
		temp.lendario = (lendario == 1);
		pokemons[index++] = temp;
	}
	
	fclose(arquivo);
	return pokemons;
}

// Função para imprimir informações de um Pokémon
void imprimirPokemon(Pokemon pokemon) {
	printf("[#%d -> %s: %s - ", pokemon.identificador, pokemon.nome, pokemon.descricao);
	
	if (strcmp(pokemon.tipos[1], " ") == 0) {
		printf("['%s'] - ", pokemon.tipos[0]);
	} else {
		printf("['%s', '%s'] - ", pokemon.tipos[0], pokemon.tipos[1]);
	}
	
	printf("[");
	
	for (int i = 0; strlen(pokemon.habilidades[i]) > 0; i++) {
		printf("'%s'", pokemon.habilidades[i]);
		
		if (strlen(pokemon.habilidades[i + 1]) > 0) {
			printf(", ");
		}
	}
	
	printf("] - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %02d/%02d/%d\n", 
		pokemon.peso, 
		pokemon.altura, 
		pokemon.taxaCaptura, 
		pokemon.lendario ? "true" : "false", 
		pokemon.geracao,
		pokemon.dataCaptura.dia, 
		pokemon.dataCaptura.mes, 
		pokemon.dataCaptura.ano);
}

// Função Principal
int main(void) {
	int id;
	int i = 0;
	char entrada[20];
	
	Pokemon* pokemons = carregarArquivo("pokemon.csv");
	if (!pokemons) {
		return 1;
	}
	
	Pokemon selecionados[TAMANHO];
	while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
		sscanf(entrada, "%d", &id);
		Pokemon encontrado = buscarPokemon(pokemons, id);
		
		if (encontrado.identificador != -1) {
			selecionados[i++] = encontrado;
		}
	}
	
	for (int j = 0; j < i; j++) {
		imprimirPokemon(selecionados[j]);
	}
	
	free(pokemons);
	return 0;
}



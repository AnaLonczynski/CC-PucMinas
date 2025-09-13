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
} Date;

// Estrutura do Pokemon
typedef struct {
	int id;
	int generation;
	char name[MAX];
	char description[MAX];
	char types[2][MAX];
	char abilities[20][MAX];
	double weight;
	double height;
	int captureRate;
	bool isLegendary;  
	Date captureDate;
} Pokemon;

// Funções SET
void setID(int id, Pokemon *pokemon) { pokemon->id = id; }
void setGeneration(int generation, Pokemon *pokemon) { pokemon->generation = generation; }
void setName(char name[], Pokemon *pokemon) { strcpy(pokemon->name, name); }
void setDescription(char description[], Pokemon *pokemon) { strcpy(pokemon->description, description); }
void setTypes(char type1[], char type2[], Pokemon *pokemon) { 
	strcpy(pokemon->types[0], type1); 
	strcpy(pokemon->types[1], type2); 
}
void setAbilities(char **abilities, Pokemon *pokemon) {
	int i = 0;
	while (abilities[i][0] != '\0') {  
		strcpy(pokemon->abilities[i], abilities[i]);
		i++;
	}
}
void setWeight(double weight, Pokemon *pokemon) { pokemon->weight = weight; }
void setHeight(double height, Pokemon *pokemon) { pokemon->height = height; }
void setCaptureRate(int captureRate, Pokemon *pokemon) { pokemon->captureRate = captureRate; }
void setIsLegendary(bool isLegendary, Pokemon *pokemon) { pokemon->isLegendary = isLegendary; }
void setData(int dia, int mes, int ano, Pokemon *pokemon) {
	pokemon->captureDate.dia = dia;
	pokemon->captureDate.mes = mes;
	pokemon->captureDate.ano = ano;
}

// Funções GET
int getID(Pokemon pokemon) { return pokemon.id; }
int getGeneration(Pokemon pokemon) { return pokemon.generation; }
char* getName(Pokemon pokemon) { return pokemon.name; }
char* getDescription(Pokemon pokemon) { return pokemon.description; }
char** getTypes(Pokemon pokemon) {
	char** tipos = malloc(2 * sizeof(char*));
	tipos[0] = pokemon.types[0];
	tipos[1] = pokemon.types[1];
	return tipos;
}
char** getAbilities(Pokemon pokemon) {
	char** clone = malloc(20 * sizeof(char*));
	int i = 0;
	while (pokemon.abilities[i][0] != '\0') {
		strcpy(clone[i], pokemon.abilities[i]);
		i++;
	}
	return clone;
}
double getWeight(Pokemon pokemon) { return pokemon.weight; }
double getHeight(Pokemon pokemon) { return pokemon.height; }
int getCaptureRate(Pokemon pokemon) { return pokemon.captureRate; }
bool getIsLegendary(Pokemon pokemon) { return pokemon.isLegendary; }
void getData(Pokemon pokemon, int *dia, int *mes, int *ano) {
	*dia = pokemon.captureDate.dia;
	*mes = pokemon.captureDate.mes;
	*ano = pokemon.captureDate.ano;
}

// Função de Clone
Pokemon clonePokemon(Pokemon original) {
	Pokemon clone;
	clone.id = original.id;
	clone.generation = original.generation;
	strcpy(clone.name, original.name);
	strcpy(clone.description, original.description);
	strcpy(clone.types[0], original.types[0]);
	strcpy(clone.types[1], original.types[1]);
	
	int i = 0;
	while (original.abilities[i][0] != '\0') {
		strcpy(clone.abilities[i], original.abilities[i]);
		i++;
	}
	clone.weight = original.weight;
	clone.height = original.height;
	clone.captureRate = original.captureRate;
	clone.isLegendary = original.isLegendary;
	clone.captureDate = original.captureDate;
	
	return clone;
}

// Função para procurar um Pokémon pelo ID
Pokemon procurar(Pokemon* pokemons, int id) {
	for (int i = 0; i < TAMANHO; i++) {
		if (pokemons[i].id == id) {
			return pokemons[i];
		}
	}
	Pokemon pokemon;
	pokemon.id = -1;
	return pokemon; 
}

// Função para trocar vírgulas fora de aspas por ponto e vírgula
void trocarVirgula(char* line) {
	bool aspas = false;
	for (int i = 0; i < strlen(line); i++) {
		if (!aspas && line[i] == ',') {
			line[i] = ';';
		} else if (line[i] == '"') {
			aspas = !aspas;
		}
	}
}

// Função para ler o arquivo CSV e carregar os Pokémons
Pokemon* lerTodoArquivo(char fileName[]) {
	Pokemon* pokemons = (Pokemon*)malloc(TAMANHO * sizeof(Pokemon));
	FILE* arquivo = fopen(fileName, "r");
	if (!arquivo) {
		printf("Erro ao abrir o arquivo.\n");
		return NULL;
	}
	
	char trash[200];
	fgets(trash, sizeof(trash), arquivo); // Pular o cabeçalho
	
	char line[500];
	int legendary; 
	int index = 0;
	
	while (fgets(line, sizeof(line), arquivo) != NULL) {
		char abilities[MAX] = " ";
		Pokemon temp = { .types = { " ", " " } };
		
		trocarVirgula(line);
		
		sscanf(line, "%d;%d;%[^;];%[^;];%[^;];%[^;]", 
			&temp.id, &temp.generation, temp.name, temp.description, temp.types[0], temp.types[1]);
		
		char resto[100];
		sscanf(line, "%[^[][%[^]]]%s", trash, abilities, resto);
		
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
		
		sscanf(dividir[1], "%lf", &temp.weight);
		sscanf(dividir[2], "%lf", &temp.height);
		sscanf(dividir[3], "%d", &temp.captureRate);
		sscanf(dividir[4], "%d", &legendary);
		sscanf(dividir[5], "%d/%d/%d", &temp.captureDate.dia, &temp.captureDate.mes, &temp.captureDate.ano);
		
		j = 0;
		int tamanhoabilities = strlen(abilities);
		char abilities2[100];
		for (int i = 0; i < tamanhoabilities; i++) {
			if (abilities[i] != '\'') {
				abilities2[j++] = abilities[i];
			}
		}
		abilities2[j] = '\0';
		
		m = 0;
		j = 0;
		for (int i = 0; i < strlen(abilities2); i++) {
			if (abilities2[i] == ',') {
				temp.abilities[j][m] = '\0';
				j++;
				m = 0;
				i++;
			} else {
				temp.abilities[j][m++] = abilities2[i];
			}
		}
		
		temp.isLegendary = (legendary == 1);
		pokemons[index++] = temp;
	}
	
	fclose(arquivo);
	return pokemons;
}

// Função para imprimir informações de um Pokémon
void printar(Pokemon pokemon) {
	printf("[#%d -> %s: %s - ", pokemon.id, pokemon.name, pokemon.description);
	
	if (strcmp(pokemon.types[1], " ") == 0) {
		printf("['%s'] - ", pokemon.types[0]);
	} else {
		printf("['%s', '%s'] - ", pokemon.types[0], pokemon.types[1]);
	}
	
	printf("[");
	for (int i = 0; strlen(pokemon.abilities[i]) > 0; i++) {
		printf("'%s'", pokemon.abilities[i]);
		if (strlen(pokemon.abilities[i + 1]) > 0) {
			printf(", ");
		}
	}
	printf("] - %.1lfkg - %.1lfm - %d%% - %s - %d gen] - %02d/%02d/%d\n", 
		pokemon.weight, 
		pokemon.height, 
		pokemon.captureRate, 
		pokemon.isLegendary ? "true" : "false", 
		pokemon.generation,
		pokemon.captureDate.dia, 
		pokemon.captureDate.mes, 
		pokemon.captureDate.ano);
}

// Função Principal
int main(void) {
	int id;
	int i = 0;
	char entrada[20];
	
	Pokemon* pokemons = lerTodoArquivo("pokemon.csv");
	if (!pokemons) {
		return 1;
	}
	
	Pokemon selecionados[TAMANHO];
	while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
		sscanf(entrada, "%d", &id);
		Pokemon temp = procurar(pokemons, id);
		if (temp.id != -1) {
			selecionados[i++] = temp;
		}
	}
	
	for (int j = 0; j < i; j++) {
		printar(selecionados[j]);
	}
	
	free(pokemons);
	return 0;
}


#include <stdio.h>
#include <string.h>

// Definição da struct Pokemon
typedef struct {
	int id;
	char name[50];
	int generation;
	float weight;
	float height;
	int captureRate;
	int isLegendary;
} Pokemon;

// Função para buscar um Pokémon pelo nome no arranjo
int findPokemonByName(Pokemon arr[], int size, char name[]) {
	for (int i = 0; i < size; i++) {
		// Verifica se o nome do Pokémon na posição i é igual ao nome procurado
		if (strcmp(arr[i].name, name) == 0) {
			return i; // Retorna o índice onde o Pokémon foi encontrado
		}
	}
	return -1; // Retorna -1 se o Pokémon não foi encontrado
}

int main() {
	// Criação de um arranjo de Pokémons
	Pokemon pokemons[] = {
		{1, "Bulbasaur", 1, 6.9, 0.7, 45, 0},
		{4, "Charmander", 1, 8.5, 0.6, 45, 0},
		{7, "Squirtle", 1, 9.0, 0.5, 45, 0},
		{25, "Pikachu", 1, 6.0, 0.4, 190, 0},
		{150, "Mewtwo", 1, 122.0, 2.0, 3, 1}
	};
	
	int size = sizeof(pokemons) / sizeof(pokemons[0]);
	char searchName[50];
	
	// Pede ao usuário para inserir o nome do Pokémon a ser buscado
	printf("Digite o nome do Pokemon que deseja buscar: ");
	scanf("%s", searchName);
	
	// Chama a função para procurar o Pokémon
	int index = findPokemonByName(pokemons, size, searchName);
	
	// Verifica o resultado da busca
	if (index != -1) {
		printf("Pokemon %s encontrado na posição %d do arranjo.\n", pokemons[index].name, index);
	} else {
		printf("Pokemon %s não encontrado no arranjo.\n", searchName);
	}
	
	return 0;
}


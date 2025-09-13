#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

// Estrutura de célula para a lista dinâmica
typedef struct Celula {
	Pokemon pokemon;
	struct Celula* prox;
} Celula;

// Função para criar uma nova célula
Celula* novaCelula(Pokemon pokemon) {
	Celula* cel = (Celula*) malloc(sizeof(Celula));
	cel->pokemon = pokemon;
	cel->prox = NULL;
	return cel;
}

// Função para inserir no início da lista
void inserirInicio(Celula** head, Pokemon pokemon) {
	Celula* nova = novaCelula(pokemon);
	nova->prox = *head;
	*head = nova;
}

// Função para inserir no fim da lista
void inserirFim(Celula** head, Pokemon pokemon) {
	Celula* nova = novaCelula(pokemon);
	if (*head == NULL) {
		*head = nova;
	} else {
		Celula* temp = *head;
		while (temp->prox != NULL) {
			temp = temp->prox;
		}
		temp->prox = nova;
	}
}

// Função para inserir em uma posição específica
void inserir(Celula** head, Pokemon pokemon, int pos) {
	if (pos == 0) {
		inserirInicio(head, pokemon);
	} else {
		Celula* nova = novaCelula(pokemon);
		Celula* temp = *head;
		for (int i = 0; i < pos - 1 && temp != NULL; i++) {
			temp = temp->prox;
		}
		if (temp != NULL) {
			nova->prox = temp->prox;
			temp->prox = nova;
		} else {
			printf("ERRO: posição inválida!\n");
		}
	}
}

// Função para remover do início da lista
Pokemon removerInicio(Celula** head) {
	Pokemon pokemonVazio = {0}; // Caso a lista esteja vazia
	if (*head == NULL) {
		printf("ERRO: lista vazia!\n");
		return pokemonVazio;
	}
	Celula* temp = *head;
	Pokemon removido = temp->pokemon;
	*head = temp->prox;
	free(temp);
	return removido;
}

// Função para remover do fim da lista
Pokemon removerFim(Celula** head) {
	Pokemon pokemonVazio = {0}; // Caso a lista esteja vazia
	if (*head == NULL) {
		printf("ERRO: lista vazia!\n");
		return pokemonVazio;
	}
	if ((*head)->prox == NULL) {
		Pokemon removido = (*head)->pokemon;
		free(*head);
		*head = NULL;
		return removido;
	}
	Celula* temp = *head;
	while (temp->prox->prox != NULL) {
		temp = temp->prox;
	}
	Pokemon removido = temp->prox->pokemon;
	free(temp->prox);
	temp->prox = NULL;
	return removido;
}

// Função para remover em uma posição específica
Pokemon remover(Celula** head, int pos) {
	Pokemon pokemonVazio = {0}; // Caso a lista esteja vazia
	if (*head == NULL) {
		printf("ERRO: lista vazia!\n");
		return pokemonVazio;
	}
	if (pos == 0) {
		return removerInicio(head);
	}
	Celula* temp = *head;
	for (int i = 0; i < pos - 1 && temp != NULL; i++) {
		temp = temp->prox;
	}
	if (temp != NULL && temp->prox != NULL) {
		Celula* removida = temp->prox;
		Pokemon removido = removida->pokemon;
		temp->prox = removida->prox;
		free(removida);
		return removido;
	}
	printf("ERRO: posição inválida!\n");
	return pokemonVazio;
}

// Função para exibir a lista
void mostrarLista(Celula* head) {
	int index = 0;
	while (head != NULL) {
		printf("[%d] ", index++);
		printar(head->pokemon); // Assumindo que você já tem a função 'printar' implementada
		head = head->prox;
	}
}

// Implementação da função principal
int main(void) {
	int id;
	char entrada[100];
	
	Pokemon* pokemons = lerTodoArquivo("/tmp/pokemon.csv");
	if (!pokemons) {
		return 1;
	}
	
	Celula* lista = NULL;
	
	// Lógica para leitura de entrada e inserção
	while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
		sscanf(entrada, "%d", &id);
		Pokemon encontrado = procurar(pokemons, id);
		
		if (encontrado.id != -1) {
			inserirFim(&lista, encontrado);
		}
	}
	
	int numEntradas;
	scanf("%d", &numEntradas);
	
	for (int i = 0; i < numEntradas; i++) {
		char entrada2[100];
		scanf(" %99[^\n]%*c", entrada2);
		entrada2[strcspn(entrada2, "\r")] = '\0';
		
		switch (getOperacao(entrada2)) {
		case 0:
			inserirInicio(&lista, getPokemon(pokemons, subString(3, strlen(entrada2), entrada2)));
			break;
		case 1:
			inserirFim(&lista, getPokemon(pokemons, subString(3, strlen(entrada2), entrada2)));
			break;
		case 2:
			inserir(&lista, getPokemon(pokemons, subString(getEndOfNumber(entrada2) + 1, strlen(entrada2), entrada2)), 
				toInt(subString(3, getEndOfNumber(entrada2), entrada2)));
			break;                
		case 3:
			printf("(R) %s\n", removerInicio(&lista).name);
			break;
		case 4:
			printf("(R) %s\n", removerFim(&lista).name);
			break;
		case 5:
			printf("(R) %s\n", remover(&lista, toInt(subString(3, getEndOfNumber(entrada2), entrada2))).name);
			break;
		default:
			printf("Entrada inválida\n");
		}
	}
	
	mostrarLista(lista);
	
	free(pokemons);
	return 0;
}


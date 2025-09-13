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

//Estrutura da Lista
typedef struct {
	int tamanho;
	int primeiro;
	int ultimo;
	Pokemon filaCircular[802];
}FilaCircular;

//Set 
void setID          (int id, Pokemon pokemon){pokemon.id = id;};
void setGeneration  (int id, Pokemon pokemon){pokemon.generation = id;};
void setName        (char name[], Pokemon pokemon){strcpy(pokemon.name, name);};
void setDescription (char description[], Pokemon pokemon){strcpy(pokemon.description, description);};
void setTypes       (char type1[], char type2[], Pokemon pokemon){strcpy(pokemon.types[0],type1); strcpy(pokemon.types[0],type1);};
void setAbilities   (char** abilities, Pokemon pokemon)
                    {
                        int i = 0;
                       while (abilities[i][0] != '\0')
                        {  
                        strcpy(pokemon.abilities[i], abilities[i]);
                            i++;
                         }
                    };
void setWeight      (double id, Pokemon pokemon){pokemon.weight = id;};
void setHeight      (double id, Pokemon pokemon){pokemon.height = id;};
void setCaptureRate (int id, Pokemon pokemon){pokemon.captureRate = id;};
void setIsLegendary (bool id, Pokemon pokemon){pokemon.isLegendary = id;};
void setData        (int dia, int mes, int ano, Pokemon pokemon){pokemon.captureDate.dia = dia; pokemon.captureDate.mes = mes; pokemon.captureDate.ano = ano; }

//Get 
int getID(Pokemon pokemon) {
    return pokemon.id;
}

int getGeneration(Pokemon pokemon) {
    return pokemon.generation;
}

char* getName(Pokemon pokemon)
 {
    char* nome = pokemon.name;
    return nome;
}

char* getDescription(Pokemon pokemon) {
    
    char* descricao = pokemon.description;
    return descricao;
}

char** getTypes(Pokemon pokemon) 
{
    char** tipos = malloc(2 *sizeof(char));
    tipos[0] = pokemon.types[0];
    tipos[1] = pokemon.types[1];
    return tipos;
}

char** getAbilities(Pokemon pokemon) {
    int i = 0;
    char** clone = malloc(20 *sizeof(char));
    while (pokemon.abilities[i][0] != '\0') {
        strcpy(clone[i], pokemon.abilities[i]);
        i++;
    }
    
    // Definir o terminador de array no clone
    clone[i][0] = '\0';

    return clone;
}

double getWeight(Pokemon pokemon) {
    return pokemon.weight;
}

double getHeight(Pokemon pokemon) {
    return pokemon.height;
}

int getCaptureRate(Pokemon pokemon) {
    return pokemon.captureRate;
}

bool getIsLegendary(Pokemon pokemon) {
    return pokemon.isLegendary;
}

void getData(Pokemon pokemon, int *dia, int *mes, int *ano) {
    *dia = pokemon.captureDate.dia;
    *mes = pokemon.captureDate.mes;
    *ano = pokemon.captureDate.ano;
}


//clone
Pokemon clonePokemon(Pokemon original) {
    Pokemon clone;

    // Copiar campos simples
    clone.id = original.id;
    clone.generation = original.generation;
    strcpy(clone.name, original.name);
    strcpy(clone.description, original.description);

    // Copiar tipos
    strcpy(clone.types[0], original.types[0]);
    strcpy(clone.types[1], original.types[1]);

    // Copiar habilidades 
    int i = 0;
    while (original.abilities[i][0] != '\0') {
        strcpy(clone.abilities[i], original.abilities[i]);
        i++;
    }
    
    // Definir o terminador de array no clone
    clone.abilities[i][0] = '\0';

    // Copiar demais campos
    clone.weight = original.weight;
    clone.height = original.height;
    clone.captureRate = original.captureRate;
    clone.isLegendary = original.isLegendary;

    // Copiar data
    clone.captureDate.dia = original.captureDate.dia;
    clone.captureDate.mes = original.captureDate.mes;
    clone.captureDate.ano = original.captureDate.ano;

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
void trocarVirgula(char* Line) {
    bool aspas = false;
    for (int i = 0; i < strlen(Line); i++) {
        if (!aspas && Line[i] == ',') {
            Line[i] = ';';
        } else if (Line[i] == '"') {
            aspas = !aspas;
        }
    }
}

int comparaElementosString(Pokemon a, Pokemon b){
	
	int Comparison = strcmp(a.name, b.name);
	//printf("string\n");
	return Comparison;
	
} 

int comparaElementosPeso(Pokemon a, Pokemon b){
	
	if (a.weight < b.weight) {
		return 0; 
	} else if (a.weight > b.weight) {
		return 1; 
	} else {
		return comparaElementosString(a,b); 
	}
} 

int comparaElementosGeracao(Pokemon a, Pokemon b){
	
	if (a.generation < b.generation) {
		return -1; 
	} else if (a.generation > b.generation) {
		return 1; 
	} else {
		return comparaElementosString(a , b); 
	}
} 

int comparaElementosId(Pokemon a, Pokemon b){
	
	if (a.id < b.id) {
		return -1; 
	} else if (a.id > b.id) {
		return 1; 
	} else {
		return comparaElementosString(a , b); 
	}
}

int comparaElementosAltura(Pokemon a, Pokemon b){
	
	if (a.height < b.height) {
		return 0; 
	} else if (a.height > b.height) {
		return 1; 
	} else {
		return comparaElementosString(a,b); 
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
    
    char Line[500];
    int legendary; 
    int index = 0;
    
    while (fgets(Line, sizeof(Line), arquivo) != NULL) {
        char abilities[MAX] = " ";
        Pokemon temp = { .types = { " ", " " } };

        trocarVirgula(Line);

        sscanf(Line, "%d;%d;%[^;];%[^;];%[^;];%[^;]", 
               &temp.id, &temp.generation, temp.name, temp.description, temp.types[0], temp.types[1]);

        char resto[100];
        sscanf(Line, "%[^[][%[^]]]%s", trash, abilities, resto);

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

        // Limpar aspas das habilidades
        j = 0;
        int tamanhoabilities = strlen(abilities);
        char abilities2[100];
        for (int i = 0; i < tamanhoabilities; i++) {
            if (abilities[i] != '\'') {
                abilities2[j++] = abilities[i];
            }
        }
        abilities2[j] = '\0';
        int tamanho2 = strlen(abilities2);
        // Processar habilidades
        m = 0;
        j = 0;
        for (int i = 0; i < tamanho2; i++) {
            if (abilities2[i] == ',') {
                temp.abilities[j][m] = '\0';
                j++;
                m = 0;
                i++;
            } else {
                temp.abilities[j][m++] = abilities2[i];
            }
        }
       // temp.abilities[j][m] = '\0';

        temp.isLegendary = (legendary == 1);
        pokemons[index++] = temp;
    }
    
    fclose(arquivo);
    return pokemons;
}

/*
//Fila Circular Sequencial C
*/

FilaCircular* construtorFilaCircular(){
	FilaCircular* fila = (FilaCircular*) malloc(sizeof(FilaCircular));
	fila->primeiro = 0;
	fila->ultimo = 0;
	fila->tamanho = 0;
	
	return fila;
}

void inserir(FilaCircular *fila, Pokemon pokemon, int pos){
	if(list->tamanho >= 803 || pos > list->tamanho || pos < 0){
		if(pos > list->tamanho || pos < 0){
			printf("ERRO: Posicao invalida!!\n");
		}else{
			printf("ERRO: lista cheia!!\n");
		}
	}else{
		for(int i = list->tamanho; i > pos; i--){
			list->lista[i] = list->lista[i-1];
		}
		list->lista[pos] = pokemon;
		list->tamanho++;
	}
}

Pokemon remover(FilaCircular *fila, int pos){
	Pokemon tmp;
	if(list->tamanho <= 0 || pos >= list->tamanho || pos < 0){
		if(pos >= list->tamanho || pos < 0){
			printf("Posicao invalida!!\n");
		}else{
			printf("ERRO: lista cheia!!\n");
		}
	}else{
		tmp = list->lista[pos];
		for(int i = pos; i < list->tamanho; i++){
			list->lista[i] = list->lista[i+1];
		}
		list->tamanho--;
	}
	return tmp;
}

void mostrarFilaCircular(FilaCircular *fila){
	for(int i = 0; i < fila->tamanho; i++){
		printf("[%d] ", i);
		printar(list->lista[i]);
	}
}
/*
//Fim Fila Sequencial
*/

//identificar comando a ser realizado
int getOperacao(char* entrada){
	int resp;
	
	if(entrada[0] == 'I'){
		if(entrada[1] == 'I'){
			resp = 0;
		}else if(entrada[1] == 'F'){
			resp = 1;
		}else{
			resp = 2;
		}
	}else{
		if(entrada[1] == 'I'){
			resp = 3;
		}else if(entrada[1] == 'F'){
			resp = 4;
		}else{
			resp = 5;
		}
	}
	
	return resp;
}

int toInt(char* entrada){
	int indicadorFim = 0;
	int i = 0;
	
	while(entrada[i] != '\0'){
		indicadorFim++;
		i++;
	}
	
	char novaString[indicadorFim];
	
	for(int j = 0; j < indicadorFim; j++){
		novaString[j] = entrada[indicadorFim-j-1];
	}
	
	int soma = 0;
	
	for(int i = 0; i < indicadorFim; i++){
		int asccivalue = novaString[i];
		asccivalue -= 48;
		
		soma+= asccivalue*(pow(10, i));
	}
	
	return soma;
	
}

int getEndOfNumber(char* entrada){
	int i;
	
	for(i = 3; i < strlen(entrada) && entrada[i] != ' '; i++);
	
	return i;
}

char* subString(int posInit, int posFinal, char* entrada) {
	
	char* novaString = (char*) malloc((posFinal - posInit + 1) * sizeof(char));
	
	for (int i = 0; i < (posFinal - posInit); i++) {
		novaString[i] = entrada[posInit + i];
	}
	
	novaString[posFinal - posInit] = '\0';
	
	return novaString;
}

/*
bool isIgual2(char str[], int id){
	bool test = true;
	int tam = strlen(id) -1 ;
	for(int i = 0; i < tam; i++){
		if(str[i] != id[i]){
			test = false;
			i = tam;
		}
	}
	
	return test;
}*/

bool isIgual(int id, char str[]) {
	char idStr[10];
	snprintf(idStr, sizeof(idStr), "%d", id); // Convert id to string
	
	return strcmp(idStr, str) == 0;
}

Pokemon getPokemon(Pokemon pokemons[], char* id){
	Pokemon pokemon;
	for(int i = 0; i < 803; i++){
		if(isIgual(pokemons[i].id, id)){
			pokemon = pokemons[i];
			i = 803;
		}
	}
	
	return pokemon;
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

    for (int i = 0; strlen(pokemon.abilities[i]) > 0; i++) 
	{
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

int main(void) {
    int id;
    int i = 0;
    char entrada[100];
    
	//Pokemon* pokemons = lerTodoArquivo("pokemon.csv");
    Pokemon* pokemons = lerTodoArquivo("/tmp/pokemon.csv");
    if (!pokemons) {
        return 1;
    }

	Lista* list = construtorLista();
    //Pokemon selecionados[TAMANHO];
    while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
        sscanf(entrada, "%d", &id);
        Pokemon encontrado = procurar(pokemons, id);
        
        if (encontrado.id != -1) {
            //selecionados[i++] = encontrado;
			inserirFim(list, encontrado);
        }
		
    }
	
	/*
	for (int j = 0; j < i; j++) {
		printar(selecionados[j]);
	}*/
	
	int numEntradas;
	scanf("%d", &numEntradas);
	
	for(int i = 0; i < numEntradas; i++){
		char entrada2[100];
		
		scanf(" %99[^\n]%*c", entrada2);
		entrada2[strcspn(entrada2, "\r")] = '\0';
		
		switch(getOperacao(entrada2)){
			case 0:
				inserirInicio(list, getPokemon(pokemons, subString(3, strlen(entrada2), entrada2)));
				break;
			case 1:
				inserirFim(list, getPokemon(pokemons, subString(3, strlen(entrada2), entrada2)));
				break;
			case 2:
				inserir(list, getPokemon(pokemons, subString(getEndOfNumber(entrada2) + 1, strlen(entrada2), entrada2)), toInt(subString(3, getEndOfNumber(entrada2), entrada2)));                
				break;                
			case 3:
			printf("(R) %s\n", removerinicio(list).name);               
			printf("(R) %s\n", removerinicio(list).name);               
				break;
			case 4:
				printf("(R) %s\n", removerfim(list).name);                
				break;
			case 5:
				printf("(R) %s\n", remover(list, toInt(subString(3, getEndOfNumber(entrada2), entrada2))).name);               
				break;
			default:
				printf("entrada invalida");
		}
	}
	
	mostrarLista(list);
	
    free(pokemons);
    return 0;
}

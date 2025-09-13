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

//get 

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


void swap(Pokemon vetor[], int i, int j){
	Pokemon tmp = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = tmp;
}


void selectionSort(Pokemon vetor[], int pos){
	
	int menor = pos;
	
	if(pos < 26){
		//printf("entrei %d\n", pos);
		for(int i = pos + 1; strcmp(vetor[i].name, "") != 0 && i < 27; i++){
			if(comparaElementosPeso(vetor[menor], vetor[i]) >= 0){
				menor = i;
			}
		}
		//printf("saiS %d\n", pos);
		swap(vetor, pos, menor);
		selectionSort(vetor, pos + 1);
		//printf("sai msm\n");
		
	}
	
}


void insercaoPorPeso(Pokemon vetor[], int weight, int h, int n){
	for(int i = (h + weight); i < n; i += h){
		Pokemon tmp = vetor[i];
		int j = i - h;
		while((j >= 0) && comparaElementosPeso(vetor[j], tmp) > 0){
			vetor[j+h] = vetor[j];
			j -= h;
		}
		vetor[j+h] = tmp;
	}
}


void shellSort(Pokemon vetor[], int n){
	int h = 1;
	while (h < n / 3) {
		h = h * 3 + 1; // 1, 4, 13, 40, ...
	}
	do{
		for(int weight = 0; weight < h; weight++){
			insercaoPorPeso(vetor, weight, h, n);
		}
		h /= 3;
	} while(h > 0);
}


void quickSort(Pokemon vetor[], int esq, int dir){
	int i = esq;
	int j = dir;
	int meio = (j+i)/2;
	Pokemon pivot = vetor[meio];
	//printf("esq:%d \n", i);
	//printf("dir:%d \n",j);
	//printf("pivor:%d \n",meio);
	
	//printf("dentro quick\n");
	
	while (i <= j) {
		
		while (comparaElementosGeracao(vetor[i], pivot) < 0) {
			
			//printf("comparar 1 \n");
			i++;
		}
		while (comparaElementosGeracao(vetor[j], pivot) > 0 ) {
			
			//printf("comparar 2 \n");
			j--;
		}
		
		if (i <= j) {
			swap(vetor, i, j);
			i++;
			j--;
		}
	}
	
	
	if (esq < j) {
		quickSort(vetor, esq, j);
	}
	if (i < dir) {
		quickSort(vetor, i, dir);
	}
}


void bubbleSort(Pokemon vetor[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(comparaElementosId(vetor[j], vetor[j+1]) > 0){
				swap(vetor, j, j+1);
			}
		}
	}
}

void adicionaNoHeap(Pokemon heap[], int pos){
	for(; pos > 1 && comparaElementosAltura(heap[pos], heap[pos/2]) > 0  ; pos = pos/2){
		swap(heap, pos, pos/2);
	}
}

bool hasFilho(int i, int tam){
	bool test = true;
	
	if(2*i > tam){
		test = false;
	}
	
	return test;
}

int getMaiorFilho(Pokemon heap[], int i, int tam){
	int maior;
	if(2*i+1 > tam){
		maior = 2*i;
	}
	else{
		if(comparaElementosAltura(heap[2*i], heap[2*i+1]) < 0){
			maior = 2*i+1;
		}
		else{
			maior = 2*i;
		}
	}
	return maior;
}

void reconstroiHeap(Pokemon heap[], int tam){
	int i = 1;
	while(hasFilho(i, tam)){
		int filho = getMaiorFilho(heap, i, tam);
		
		if(comparaElementosAltura(heap[i], heap[filho]) < 0){
			
			swap(heap, i, filho);
			i = filho;
		}
		else{
			i = tam;
		}
	}
}

void heapSort(Pokemon vetor[]){
	int tam = 0;
	Pokemon heap[28];
	
	for(int i = 0; i < 10; i++){
		heap[i+1] = vetor[i];
		adicionaNoHeap(heap, i+1);
		tam++;
	}
	
	for(int i = 10 + 1; i < 27; i++){
		if(comparaElementosAltura(vetor[i], heap[1]) < 0){
			heap[1] = vetor[i];
			reconstroiHeap(heap, 10);
		}
	}
	
	tam = 10;
	while(tam > 1){
		swap(heap, 1, tam--);
		reconstroiHeap(heap, tam);
	}
	
	/*for(int j = 1; j < heap.length; j++){
	heap[j].imprime();
	}*/
	
}
/*
int compareData(Date d1, Date d2) {
	if (d1.year != d2.year) return d1.year - d2.year;
	if (d1.month != d2.month) return d1.month - d2.month;
	return d1.day - d2.day;
}


void InsertionSort(Pokemon vetor[], int n) {
	for (int i = 1; i < n; i++) {
		Pokemon menor = vetor[i];
		int j = i - 1;
		
		// Comparar e inserir o menor elemento na posição correta
		while (j >= 0 && 
			(compareData(vetor[j].captureDate, menor.captureDate) > 0 || 
				(compareData(vetor[j].captureDate, menor.captureDate) == 0 && 
					strcmp(vetor[j].name, menor.name) > 0))) {
			vetor[j + 1] = vetor[j]; // Desloca o elemento para a direita
			j--;
		}
		vetor[j + 1] = menor; // Coloca o menor elemento na posição correta
	}
}*/

void insertionSort(Pokemon vetor[], int size) {
	for (int i = 1; i < size; i++) {
		Pokemon menor = vetor[i];  
		int j;
		if(i < 10){
			j = i;
		}else{
			j = 10;
		}
		
		// Compara datas
		while (j > 0 && 
			(vetor[j - 1].captureDate.ano > menor.captureDate.ano ||
				(vetor[j - 1].captureDate.ano == menor.captureDate.ano && vetor[j - 1].captureDate.mes > menor.captureDate.mes) ||
				(vetor[j - 1].captureDate.ano == menor.captureDate.ano && vetor[j - 1].captureDate.mes == menor.captureDate.mes && vetor[j - 1].captureDate.dia > menor.captureDate.dia))) {
			vetor[j] = vetor[j - 1];  // Apenas desloca a referência, sem clone
			j--;
		}
		
		// Para comparação de nomes se as datas forem iguais
		if (j > 0 && vetor[j - 1].captureDate.ano == menor.captureDate.ano &&
			vetor[j - 1].captureDate.mes == menor.captureDate.mes &&
			vetor[j - 1].captureDate.dia == menor.captureDate.dia) {
			// Compara nomes
			while (j > 0 && strcmp(vetor[j - 1].name, menor.name) > 0) {
				vetor[j] = vetor[j - 1];  // Apenas desloca a referência, sem clone
				j--;
			}
		}
		
		vetor[j] = menor;  // Coloca a referência correta sem criar um clone
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
    char entrada[20];
    
	//4Pokemon* pokemons = lerTodoArquivo("pokemon.csv");
    Pokemon* pokemons = lerTodoArquivo("/tmp/pokemon.csv");
    if (!pokemons) {
        return 1;
    }

    Pokemon selecionados[TAMANHO];
    while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
        sscanf(entrada, "%d", &id);
        Pokemon encontrado = procurar(pokemons, id);
        
        if (encontrado.id != -1) {
            selecionados[i++] = encontrado;
        }
		
    }
	
    //printf("leitura feita no arranjo\n");

	insertionSort(selecionados,i);
	
	/*
	for (int j = 0; j < i; j++) {
		printar(selecionados[j]);
	}*/
	
	
	for (int j = 0; j < 10; j++) {
		printar(selecionados[j]);
	}
	
    free(pokemons);
    return 0;
}

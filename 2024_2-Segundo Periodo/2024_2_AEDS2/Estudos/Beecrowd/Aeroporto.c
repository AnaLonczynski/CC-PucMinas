#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Lista{
	int tamanho;
	char* lista[20];
}Lista;

Lista* construtorLista(){
	Lista* list = (Lista*) malloc(sizeof(Lista));
	list->tamanho = 0;
	
	return list;
}

//if -1
void inserirInicio(Lista* list, char* aviao){
	if(list->tamanho > 20){
		printf("Lista Cheia");
	}else{
		
		for(int i=list->tamanho;i>0;i--){
			list->lista[i]=list->lista[i-1];
		}
		
		// Insere o novo avião no início
		strcpy(list->lista[0], aviao);
		list->tamanho++;	
	}
}

//if -4
void inserirFimFim (Lista* listFinal){
	
}

//if -4 -2 -3 ou sem valor
void inserirFim (Lista* list, char* aviao){
	if(list->tamanho < 0){
		printf("Lista Vazia");
	}else{
		strcpy(list->lista[list->tamanho], aviao);
		list->tamanho++;
	}
}

void ordenarLista(Lista* oeste, Lista* norte, Lista* sul, Lista* leste) {

	int iOeste = 0, iNorte = 0, iSul = 0, iLeste = 0;
	
	while(iOeste < oeste->tamanho){
		printf("%s ", oeste->lista[iOeste++]);
	}
	
	// Alterna entre aviões do Norte e do Sul
	while (iNorte < norte->tamanho || iSul < sul->tamanho) {
		if (iNorte < norte->tamanho) {
			printf("%s ", norte->lista[iNorte++]);
		}
		if (iSul < sul->tamanho) {
			printf("%s ", sul->lista[iSul++]);
		}
	}
	
	// Finalmente, imprime os aviões do Leste
	while (iLeste < leste->tamanho) {
		printf("%s ", leste->lista[iLeste++]);
	}
	
	printf("\n");
}

int main (){
	
	int coordenada;
	char* aviao = "";

	// Inicializa listas para cada direção
	Lista* oeste = construtorLista();
	Lista* norte = construtorLista();
	Lista* sul = construtorLista();
	Lista* leste = construtorLista();
	
	do{
		
		scanf("%d", coordenada);
		
		// Lê o identificador do avião
		scanf("%s", aviao);
		
		switch (coordenada) {
			case -1: // Oeste
			inserirFim(oeste, aviao);
			break;
			case -3: // Norte
			inserirFim(norte, aviao);
			break;
			case -2: // Sul
			inserirFim(sul, aviao);
			break;
			case -4: // Leste
			inserirFim(leste, aviao);
			break;
			default:
			printf("Coordenada inválida\n");
			break;
		}
		
	}while(coordenada != 0);

	// Organiza e imprime a lista final
	ordenarLista(oeste, norte, sul, leste);
	
	free(oeste);
	free(leste);
	free(sul);
	free(norte);
	
	return 0;
}

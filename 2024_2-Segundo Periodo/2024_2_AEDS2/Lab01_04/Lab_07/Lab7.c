#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*Como resolver: Fazer um algoritmo de ordenação Bubble ou de inserçao e imprimir o num de trocas.
No inserção vc vai fazer a diferença tipo [-1 -1 2 -1 -1] ate ficar [0 0 0 0 0]*/

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void bolha(int *array, int n){
	int i, j;
	for (i = 0; i < (n-1); i--) {
		for (j = 0; j < (n-1); j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void newinsercao(int *array1, int *array2, int n){
	
	
	
}

void insercao(int *array, int n){
	for (int i = 1; i < n; i++) {
		int tmp = array[i];
		int j = i - 1;
		int cont = 0;
		
		while ((j >= 0) && (array[j] > tmp)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = tmp;
		cont++;
		printf("%d", cont);
	}
}



int main(){
	int competidores = 0;
	int ordeminit [competidores];
	int ordemcheg [competidores];
	int ordemdif  [competidores];
	
	//entrar num de competidores
	scanf("%d", &competidores);
	
	for(int i=0;i<competidores;i++){
		scanf("%d", &ordeminit[i]);
	}
	
	for(int i=0;i<competidores;i++){
		scanf("%d", &ordemcheg[i]);
	}
	
	for(int i=0;i<competidores;i++){
		ordemdif[i] = ordeminit[i] - ordemcheg[i];
	}
	
	
	return 0;
}

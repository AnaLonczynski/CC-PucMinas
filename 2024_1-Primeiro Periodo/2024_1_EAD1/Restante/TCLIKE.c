/*Trabalho C-Like
Disciplina: Introdução a Computação
Aluno: Ana Clara Lonczynski
Linguagem: C*/

#include <stdio.h>
#include <math.h>


int main(){
	// Declaração e inicialização de variaveis.
	int N = 0;
	int Camisetas = 0;
	int contP = 0, contM = 0, P = 0, M = 0;
	
	// Solicita ao usuário o número de premiados e le a entrada.
	printf("%s", "Insira o numero de premiados:\n");
	scanf("%d", &N); getchar( );

	// Loop para ler os tamanhos das camisetas de cada premiado
	for(int i=0;i<N;i++){
		printf("%s", "Insira os tamanhos das camisetas, sendo P = 1 e M = 2\n");
		scanf("%d", &Camisetas); getchar( );
		if(Camisetas == 1){ // Atualiza os contadores de camisetas
			contP ++;
		}else if(Camisetas == 2){
			contM ++;
		}
	}
	
	// Leitura do numero de camisetas disponíveis de tamanho P e M e le as entradas.
	printf("%s", "Insira o numero de camisetas P\n");
	scanf("%d", &P); getchar( );
	printf("%s", "Insira o numero de camisetas M\n");
	scanf("%d", &M); getchar( );
	
	if(contP == P && contM == M){ //verifica se a quantidade de camisetas solicitadas é igual à disponível. Se for verdadeiro imprime S se não imrpime N
		printf("S");
	}else{
		printf("N");
	}
	
	return 0;
}

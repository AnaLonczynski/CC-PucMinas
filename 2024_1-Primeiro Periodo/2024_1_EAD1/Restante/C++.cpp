/*Trabalho C-Like
Disciplina: Introdução a Computação
Aluno: Ana Clara Lonczynski
Linguagem: C++*/

#include <iostream>
using namespace std;

int main() {
	// Declaração e inicialização de variaveis.
	int N = 0;
	int Camisetas = 0;
	int contP = 0, contM = 0, P = 0, M = 0;
	
	// Solicita ao usuário o número de premiados e le a entrada.
	cout << "Insira o numero de premiados:" << endl;
	cin >> N;
	
	// Loop para ler os tamanhos das camisetas de cada premiado
	for (int i = 0; i < N; i++) {
		cout << "Insira os tamanhos das camisetas, sendo P = 1 e M = 2" << endl;   
		cin >> Camisetas;
		if (Camisetas == 1) {  // Atualiza os contadores de camisetas
			contP++;
		} else if (Camisetas == 2) {
			contM++;
		}
	}
	
	cout << "Insira o numero de camisetas P" << endl; // Leitura do numero de camisetas disponíveis de tamanho P e M e le as entradas.
	cin >> P;
	cout << "Insira o numero de camisetas M" << endl;
	cin >> M;
	
	//verifica se a quantidade de camisetas solicitadas é igual à disponível. Se for verdadeiro imprime S se não imrpime N
	if (contP == P && contM == M) {
		cout << "S" << endl;
	} else {
		cout << "N" << endl;
	}
	
	return 0;
}


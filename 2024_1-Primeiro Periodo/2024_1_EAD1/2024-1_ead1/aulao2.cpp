#include <stdio.h>
#include <string>

class Celula {
public:
	int elemento;
	Celula* prox;
	
	Celula(){
		elemento = 0;
		prox=nullptr;
	}
	Celula(int x) {
		elemento = x ;
		prox= nullptr;
	}
};

class Pilha {
public:
	Celula* topo;
public:
	Pilha() {
		topo = nullptr;
	}
	void push(int x) {
		Celula* tmp = new Celula (x);
		tmp->prox=topo;
		topo = tmp;
		delete tmp;
	}
	int pop(){
		if(topo == nullptr){
			return 0;
		}
		
		int elemento = topo->elemento;
		Celula* tmp = topo;
		topo = topo->prox;
		delete tmp;
		delete topo;
		
		return elemento;
	}
};

class Fila {
	Celula* inicio;
	Celula*  final;
public:
	Fila() {
		inicio = new Celula();
		final=nullptr;
	}
	void push(int x) {
		
		Celula* tmp = new Celula (x);
		final->prox = tmp;
		final = final->prox;
		delete tmp;
	}
	int pop(){
		
		if(inicio==final){
			return 0;
		}
		
		int elemento = inicio->elemento;
		Celula* tmp = inicio;
		inicio=inicio->prox;
		delete tmp;
		
		return elemento;
	}
};

int main(){
	
	
	
	return 0;
}


#include <stdio.h>
#include <string>

/*class pessoa
{
protected:
	string nome;
	int idade;
	string
public:
	pessoa;
	pessoa();
};
pessoa: pessoa)
{
}
pessoa:: pessoa()
{
}
*/

class Celula {
protected:
	int elemento;
	Celula* prox;
public:
	Celula(int x) {
		elemento = x;
		prox = nullptr;
	}
	void setProx(Celula* cel){
		prox = cel;
	}
	void setElemento(int elemento){
		this->elemento = elemento;
	}
	int getElemento(){
		return elemento;
	}
	Celula* setprox(){
		return prox;
	}
};

class Pilha {
public:
	Celula* topo;
public:
	Pilha() {
		topo = nullptr;
	}

	//Push
	void push (int x){
		Celula* tmp = new Celula(x);
		tmp->prox = topo;
		//tmp=setProx(topo);
		topo = tmp;
		delete tmp;
	}
	
	//pop
	int pop(int x){
		
		if(topo==nullptr){
			return 0;
		}
		
		int elemento = topo->elemento;
		Celula* tmp = topo;
		topo = topo->prox;
		delete tmp;
		return elemento;
	}
};



class Lista {
	Celula* primeiro;
	Celula* ultimo;
public:
	Lista() {
		primeiro = new Celula; 
		ultimo = primeiro;
	}
	
	int PopBack(){
		
		if(primeiro == ultimo){
			return 0;
		}
		
		int elemento = primeiro->elemento;
		Celula* tmp = primeiro;
		primeiro = primeiro->prox;
		delete tmp;
		
		return elemento;
	}
	
	void pushback(int x){
		Celula* tmp = new Celula(x);
		ultimo->prox = tmp;
		ultimo = ultimo->prox;
		delete tmp;
		
	}
};


int main (){
	
	
}

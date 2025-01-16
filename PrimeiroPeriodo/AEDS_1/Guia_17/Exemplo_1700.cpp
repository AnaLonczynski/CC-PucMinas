/*
Exemplo1700 - v0.0. - 25 / 06 / 2024
Author: Ana Clara Lonczynski
*/
// ----------------------------------------------- preparacao
// dependências
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
#include "io.hpp"
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

void pause ( std::string text )
{
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )

// ----------------------------------------------- definicoes globais

using namespace std;

/*
LIFO - Pilha
*/
class s_intStack
{ 
protected:
	int length;
	int *data; 
	
public:
	//construtor padrão
	s_intStack(){
		length = 0;
		data=nullptr;
	}
	
	//construtor inicial
	s_intStack(int tamanho, int valueinicial){
		s_intStack();
		if(tamanho>0){
			length = tamanho;
			data= new int [length];
			if(data){
				for(int i=0;i<length;i++){
					data[i]= valueinicial;
				}
			}
		}
	}
	
	//colocar valor na posição
	void set ( int position, int value ) {
		if ( 0 <= position && position < length ) {
			data [ position ] = value;
		} 
	} // end set ( )
	
	//pegar valor de posição
	int get ( int position ) {
		int value = -1;
		if ( 0 <= position && position < length ) {
			value = data [ position ];
		} 
		return ( value );
	} // end get ( )
	
	//retornar tamanho
	int getLength (){
		return (length);
	}
	
	//setar novo tamanho
	int setLength ( int n){
		this->length = n;
		return (length);
	}
	
	void print (s_intStack* stack){
		int tamanho = stack->getLength();
		
		cout << endl;
		for(int i=0;i<tamanho;i++){
			cout << "["<<i<<"] = "<< stack->data[i]<< endl;
		}
	}
	
	//metodo de adicionar ao final novo valor
	s_intStack* pushBack(s_intStack* stack, int value){
		int tamanho = stack->getLength();
		
		stack->length= tamanho;
		
		stack->length=setLength(tamanho+1);
		stack->set(tamanho, value);
		
		return (stack);
	}
	
	//metodo de remover valor no final
	s_intStack* popBack ( s_intStack* stack){
		int tamanho = stack->getLength();
		int novoTamanho = setLength(tamanho-1);
		int copia[novoTamanho];
		for (int i = 0; i < novoTamanho; i++) {
			copia[i] = stack->get(i);
		}
		for(int i=0;i<novoTamanho;i++){
			stack->set(i,copia[i]);
		}
		stack->setLength(novoTamanho);
		return (stack);
	}
	
	s_intStack* intStack_swap ( s_intStack* stack ){
		
		int tamanho = stack->getLength()-1;
		
		if(tamanho>2){
			int ultimo = stack->get(tamanho);
			int penultimo = stack->get(tamanho-1);
			int total = 0;
			
			//inverter valores
			total= ultimo + penultimo;
			penultimo = total - penultimo;
			ultimo = total - ultimo;
			
			stack->set(tamanho, ultimo);
			stack->set(tamanho-1, penultimo);
		}
		
		return stack;
	}
	
	s_intStack* intStack_invert(s_intStack* stack){
		
		int tamanho = stack->getLength()-1;
		int meio = tamanho/2;
		int posicao = tamanho;
		
		if(tamanho>2){
			for(int i=0;i<=meio;i++){
				int ultimo = stack->get(posicao);
				int primeiro = stack->get(i);
				int total = 0;
				
				//inverter valores
				total= ultimo + primeiro;
				primeiro = total - primeiro;
				ultimo = total - ultimo;
				
				stack->set(posicao, ultimo);
				stack->set(i, primeiro);
				posicao--;
			}
		}
		return stack;
	}
	
} intStack;
typedef s_intStack* ref_intStack;

/*
FIFO - Fila
*/
class s_intQueue 
{
protected:
	int length; 
	int *data;
	
public:
	//construtor padrao
	s_intQueue(){
		length=0;
		data=nullptr;
	}
	
	//construtor
	s_intQueue(int tamanho, int value){
		s_intQueue();
		if(tamanho>0){
			length = tamanho;
			data = new int [length];
			if(data){
				for(int i=0;i<length;i++){
					data[i]=value;
				}
			}	
		}
	}
	
	void set(int position, int value){
		if(position >= 0 && position < length){
			data[position] = value;
		}
	}
	
	int get(int position){
		int value = -1;
		if(position>=0 && position< length){
			value = data[position];
		}
		return value;
	}
	
	int getLength (){
		return(length);
	}
	
	int setLength(int x){
		length = x;
		return(length);
	}
	
	void print(s_intQueue* queue){
		int tamanho = queue->getLength();
		cout<<endl;
		for(int i=0;i<tamanho;i++){
			cout<<"["<< i <<"] = "<<queue->data[i]<<endl;
		}
	}
	
	s_intQueue* pushBack (s_intQueue* queue, int value){
		int tamanho = getLength();
		queue->length = setLength(tamanho +1);
		
		queue->set(tamanho, value);
		return(queue);
	}
	
	s_intQueue* popFront ( s_intQueue* queue){
		int tamanho = queue->getLength();
		int newLength = tamanho-1;
		int copia [tamanho];
		
		for(int i=0;i<tamanho;i++){
			copia[i] = queue->get(i);
		} 
		
		for(int i=0;i<tamanho;i++){
			queue->set(i, copia[i+1]);
		}
		queue->setLength(newLength);
		
		return (queue);
	}
	
	int intQueue_compare ( s_intQueue* p, s_intQueue* q ){
		int tamanho1 = p->getLength();
		int tamanho2 = q->getLength();
		int igual = 0, dife1 = 0, dife2= 0;
		
		if(tamanho2!=tamanho1){
			return(2); 
		}
		for(int i=0;i<tamanho1;i++){
			dife1 = dife1 - p->get(i);
			dife2 = dife2 - q->get(i);
			
			if(p->get(i)==q->get(i)){
				igual++;
			}
		}
		if(igual==tamanho2){
			return (0);
		}else if(dife1<dife2){
			return(1);
		}else if(dife1>dife2){
			return(-2);
		}
	}
	
	s_intQueue* intQueue_join (int tamanho1, int tamanho2, int newLength, s_intQueue* fusao, s_intQueue* p, s_intQueue* q ){
		fusao->data = new int[newLength];
		int j = 0;
		
		for(int i=0;i<tamanho1;i++){
			fusao->set(i, p->get(i));
		}
		for(int i=tamanho1;i<newLength;i++){
			fusao->set(i, q->get(j));
			j++;
		}
		return(fusao);
	}
	
	bool intQueue_search ( s_intQueue* queue, int value ){
		bool result = false;
		int tamanho = queue->getLength();
		int encontrar = 0;
		
		for(int i=0;i<tamanho;i++){
			if(queue->get(i)==value){
				encontrar++;
			}
		}
		if(encontrar>0){
			result=true;
		}
		return (result);
	}
	
	//Funcao para intercalar filas de inteiro
	s_intQueue* intQueue_merge (int newLength, s_intQueue* fusao){
		
		for(int i=0;i<newLength;i=i+2){
			
			int atual = fusao->get(i);
			int proximo = fusao->get(i+1);
			int total = 0;
			
			//inverter valores
			total= atual + proximo;
			proximo = total - proximo;
			atual = total - atual;
			
			fusao->set(i, atual);
			fusao->set(i+1, proximo);
		}
		
		return (fusao);
	}
	
	//Funcao para intercalar filas de inteiro de forma crescente
	s_intQueue* intQueue_mergeUp (int newLength, s_intQueue* fusao){
		
		for(int i=0;i<newLength;i=i+2){
			
			int atual = fusao->get(i);
			int proximo = fusao->get(i+1);
			int total = 0;
			
			//inverter valores
			total= atual + proximo;
			proximo = total - proximo;
			atual = total - atual;
			
			fusao->set(i, atual);
			fusao->set(i+1, proximo);
		}
		
		return (fusao);
	}
	
} intQueue;
typedef s_intQueue* ref_intQueue;

// ----------------------------------------------- metodos

/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

/**
  Method_01 - Testar definicoes da classe.
 */
void method_01 ( )
{
// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	ref_intStack stack = new s_intStack(1, 1);
	
	cout << endl << "Arranjo inicial:" << endl;
	stack->print(stack);
	
	stack->pushBack(stack, 2);
	stack->pushBack(stack, 3);
	stack->pushBack(stack, 4);
	
	cout << endl << "Novo arranjo com Pushback:" << endl;
	stack->print(stack);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Testar definicoes da classe.
 */
void method_02 ( )
{
// definir dados
// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	
	ref_intStack stack = new s_intStack(1, 1);
	
	stack->pushBack(stack, 2);
	stack->pushBack(stack, 3);
	stack->pushBack(stack, 4);
	
	cout << endl << "Arranjo inicial:" << endl;
	stack->print(stack);
	
	stack->popBack(stack);
	
	cout << endl << "Novo arranjo usando PushBack:" << endl;
	stack->print(stack);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Testar definicoes da classe.
 */
void method_03 ( )
{
// definir dados
	int x = 0;
	int tamanho = 0;
// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	
	ref_intStack stack = new s_intStack(1, 1);
	stack->pushBack(stack, 2);
	stack->pushBack(stack, 3);
	stack->pushBack(stack, 4);
	
	//pegar tamanho
	tamanho = stack->getLength();
	
	//pegar valor na posição final
	x = stack->get(tamanho-1);
	
	cout << endl << "Arranjo inicial:" << endl;
	stack->print(stack);
	
	stack->pushBack(stack, x);
	stack->pushBack(stack, x);
	
	cout << endl << "Novo arranjo duplicado:" << endl;
	stack->print(stack);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Testar definicoes da classe.
 */
void method_04 ( )
{
// definir dados
	int tamanho = 0;
	
// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
	
	ref_intStack stack = new s_intStack(1, 1);
	
	stack->pushBack(stack, 2);
	stack->pushBack(stack, 3);
	stack->pushBack(stack, 4);
	
	cout << endl << "Arranjo inicial:" << endl;
	stack->print(stack);
	
	//pegar tamanho
	tamanho = stack->getLength();
	stack->intStack_swap(stack);
	
	cout << endl << "Arranjo com final invertido:" << endl;
	stack->print(stack);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  method_05 - Testar definicoes da classe.
 */
void method_05 ( )
{
// definir dados
	int tamanho = 0;
	
// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
	
	ref_intStack stack = new s_intStack(1, 1);
	
	stack->pushBack(stack, 2);
	stack->pushBack(stack, 3);
	stack->pushBack(stack, 4);
	stack->pushBack(stack, 5);
	
	cout << endl << "Arranjo inicial:" << endl;
	stack->print(stack);
	
	//pegar tamanho
	tamanho = stack->getLength();
	stack->intStack_invert(stack);
	
	cout << endl << "Arranjo invertido:" << endl;
	stack->print(stack);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06 - Testar definicoes da classe.
 */
void method_06 ( )
{
// definir dados
// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,1);
	
	cout<< endl<< "Arranjo inicial:"<<endl;
	queue->print(queue);
	
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 5);
	
	cout<< endl<< "Arranjo apos pushBack:"<<endl;
	queue->print(queue);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Testar definicoes da classe.
 */
void method_07 ( )
{
// definir dados
// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,1);
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 5);
	
	cout<< endl<< "Arranjo inicial:"<<endl;
	queue->print(queue);
	
	queue->popFront(queue);
	
	cout<< endl<< "Arranjo apos popFront:"<<endl;
	queue->print(queue);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  nMethod_08 - Testar definicoes da classe.
 */
void method_08 ( )
{
// definir dados
	int result = 0;
// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,5);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 1);
	
	
	ref_intQueue queue2 = new s_intQueue(1,1);
	queue2->pushBack(queue2, 2);
	queue2->pushBack(queue2, 3);
	queue2->pushBack(queue2, 4);
	queue2->pushBack(queue2, 5);
	
	cout<< endl<< "Arranjo1:"<<endl;
	queue->print(queue);
	
	cout<< endl<< "Arranjo2:"<<endl;
	queue2->print(queue2);

	
	result = queue->intQueue_compare(queue, queue2);
	if(result == 2)
	{
		cout<<endl<<"/ERRO/ Tamanhos diferentes!"<<endl;
	}else if(result==0)
	{
		cout<<endl<<"Os arranjos sao iguais"<<endl;
	}else if(result>0)
	{
		cout<<endl<<"Os arranjos diferentes e o valor da diferenca menor esta' na primeira fila"<<endl;
	}else
	{
		cout<<endl<<"Os arranjos diferentes e o valor da diferenca maior esta' na primeira fila"<<endl;
	}
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09 - Testar definicoes da classe.
 */
void method_09 ( )
{
// definir dados
	int x = 0, y =0, z = 0;
// identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,5);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 1);
	
	
	ref_intQueue queue2 = new s_intQueue(1,1);
	queue2->pushBack(queue2, 2);
	queue2->pushBack(queue2, 3);
	queue2->pushBack(queue2, 4);
	queue2->pushBack(queue2, 5);
	
	cout<< endl<< "Arranjo1:"<<endl;
	queue->print(queue);
	
	cout<< endl<< "Arranjo2:"<<endl;
	queue2->print(queue2);
	
	x = queue->getLength();
	y = queue2->getLength();
	z = x + y;
	ref_intQueue newqueue = new s_intQueue();
	newqueue->setLength(z);
	
	newqueue->intQueue_join(x, y, z, newqueue, queue, queue2);
	cout<< endl<< "Juncao dos arranjos:"<<endl;
	newqueue->print(newqueue);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10 - Testar definicoes da classe.
 */
void method_10 ( )
{
// definir dados
	bool resultado = false;
// identificar
	cout << "\nMethod_10 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,1);
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 5);
	
	cout<< endl<< "Arranjo inicial:"<<endl;
	queue->print(queue);
	
	resultado = queue->intQueue_search(queue, 4);
	
	if(resultado==true){
		cout<< endl<< "Valor encontrado"<<endl;
	}else{
		cout<< endl<< "Valor nao encontrado"<<endl;	
	}
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/**
  Method_E1 - Testar definicoes da classe.
 */
void method_E1 ( )
{
// definir dados
	int x = 0, y =0, z = 0;
// identificar
	cout << "\nMethod_E1 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,1);
	queue->pushBack(queue, 2);
	queue->pushBack(queue, 3);
	queue->pushBack(queue, 4);
	queue->pushBack(queue, 5);
	
	
	ref_intQueue queue2 = new s_intQueue(1,6);
	queue2->pushBack(queue2, 7);
	queue2->pushBack(queue2, 8);
	queue2->pushBack(queue2, 9);
	queue2->pushBack(queue2, 10);
	
	cout<< endl<< "Arranjo1:"<<endl;
	queue->print(queue);
	
	cout<< endl<< "Arranjo2:"<<endl;
	queue2->print(queue2);
	
	x = queue->getLength();
	y = queue2->getLength();
	z = x + y;
	ref_intQueue newqueue = new s_intQueue();
	newqueue->setLength(z);
	
	newqueue->intQueue_join(x, y, z, newqueue, queue, queue2);
	newqueue->intQueue_merge(z, newqueue);
	cout<< endl<< "Intercalacao dos arranjos:"<<endl;
	newqueue->print(newqueue);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_E1 ( )

/**
  Method_E2 - Testar definicoes da classe.
 */
void method_E2 ( )
{
// definir dados
	int x = 0, y =0, z = 0;
// identificar
	cout << "\nMethod_E2 - v0.0\n" << endl;
	ref_intQueue queue = new s_intQueue(1,10);
	queue->pushBack(queue, 9);
	queue->pushBack(queue, 8);
	queue->pushBack(queue, 7);
	queue->pushBack(queue, 6);
	
	
	ref_intQueue queue2 = new s_intQueue(1,5);
	queue2->pushBack(queue2, 4);
	queue2->pushBack(queue2, 3);
	queue2->pushBack(queue2, 2);
	queue2->pushBack(queue2, 1);
	
	cout<< endl<< "Arranjo1:"<<endl;
	queue->print(queue);
	
	cout<< endl<< "Arranjo2:"<<endl;
	queue2->print(queue2);
	
	x = queue->getLength();
	y = queue2->getLength();
	z = x + y;
	ref_intQueue newqueue = new s_intQueue();
	newqueue->setLength(z);
	
	newqueue->intQueue_join(x, y, z, newqueue, queue, queue2);
	newqueue->intQueue_mergeUp(z, newqueue);
	cout<< endl<< "Intercalacao dos arranjos:"<<endl;
	newqueue->print(newqueue);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_E2 ( )

// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do
	{
		// identificar
		cout << "EXEMPLO1700 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << "  0 - parar " << endl;
		cout << "  1 - Method_1 " << endl;
		cout << "  2 - Method_2 " << endl;
		cout << "  3 - Method_3 " << endl;
		cout << "  4 - Method_4 " << endl;
		cout << "  5 - Method_5 " << endl;
		cout << "  6 - Method_6 " << endl;
		cout << "  7 - Method_7 " << endl;
		cout << "  8 - Method_8 " << endl;
		cout << "  9 - Method_9 " << endl;
		cout << " 10 - Method_10 " << endl;
		cout << " 11 - Method_E1 " << endl;
		cout << " 12 - Method_E2 " << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
		case 0:
			method_00 ( );
			break;
		case 1:
			method_01 ( );
			break;
		case 2:
			method_02 ( );
			break;
		case 3:
			method_03 ( );
			break;
		case 4:
			method_04 ( );
			break;
		case 5:
			method_05 ( );
			break;
		case 6:
			method_06 ( );
			break;
		case 7:
			method_07 ( );
			break;
		case 8:
			method_08 ( );
			break;
		case 9:
			method_09 ( );
			break;
		case 10:
			method_10 ( );
			break;
		case 11:
			method_E1 ( );
			break;
		case 12:
			method_E2 ( );
			break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

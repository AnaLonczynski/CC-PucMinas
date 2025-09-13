/*
Exemplo1600 - v0.0. - 19 / 06 / 2024
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
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
// outras dependencias
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

//------------------------------------------------ Classes

#include <iostream>
using namespace std;

class s_charStack { 
protected:
	int length;
	char *data; 
	
public:
	// Construtor padrão
	s_charStack() {
		length = 0;
		data = nullptr;
	}
	
	// Construtor inicial
	s_charStack(int tamanho, char valueinicial) {
		length = 0;
		data = nullptr;
		if (tamanho > 0) {
			length = tamanho;
			data = new char[length];
			if (data) {
				for (int i = 0; i < length; i++) {
					data[i] = valueinicial;
				}
			}
		}
	}
	
	~s_charStack() {
		free();
	}
	
	// Método para liberar memória alocada
	void free() {
		if (data) {
			delete[] data;
			data = nullptr;
			length = 0;
		}
	}
	
	// Colocar valor na posição
	void set(int position, char value) {
		if (0 <= position && position < length) {
			data[position] = value;
		}
	}
	
	// Pegar valor de posição
	char get(int position) {
		char value = '\0';
		if (0 <= position && position < length) {
			value = data[position];
		}
		return value;
	}
	
	// Retornar tamanho
	int getLength() {
		return length;
	}
	
	// Setar novo tamanho
	void setLength(int n) {
		if (n != length) {
			char *newData = new char[n];
			int copyLength = (n < length) ? n : length;
			for (int i = 0; i < copyLength; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			length = n;
		}
	}
	
	// Método para imprimir a stack
	void print() {
		cout << endl;
		for (int i = 0; i < length; i++) {
			cout << "[" << i << "] = " << data[i] << endl;
		}
	}
	
	// Método para adicionar ao final um novo valor
	void pushBack(char value) {
		setLength(length + 1);
		set(length - 1, value);
	}
	
	// Método para remover o valor no final
	void popBack() {
		if (length > 0) {
			setLength(length - 1);
		}
	}
	
	s_charStack* pushFront (s_charStack* cadeia, char value){
		int tamanho = getLength();
		tamanho = tamanho + 1;
		cadeia->setLength(tamanho);
		
		for(int i=tamanho-1;i>=0;i--){
			char ultimo = cadeia->get(i-1);
			cadeia->set(i, ultimo);
		}
		
		cadeia->set(0, value);
		return (cadeia);	
	}
	
	void popFront(){
		int tamanho = getLength();
		char copia[tamanho];
		
		for (int i = 0; i < tamanho; i++) {
			copia[i] = get(i);
		}
		for(int i=0;i<tamanho;i++){
			set(i,copia[i+1]);
		}
		tamanho = tamanho - 1;
		setLength(tamanho);
	}
	
	s_charStack* str_push_mid (s_charStack* cadeia, char value){
		int tamanho = getLength();
		tamanho = tamanho + 1;
		cadeia->setLength(tamanho);
		int meio = tamanho/2;
		
		for(int i=tamanho-1;i>=meio;i--){
			char ultimo = cadeia->get(i-1);
			cadeia->set(i, ultimo);
		}
		
		cadeia->set(meio, value);
		
		return (cadeia);
	}
	
	void popMid (){
		int tamanho = getLength();
		int meio = tamanho/2;
		int posicao = meio;
		
		for(int i=tamanho-1;i>0;i--){
			char ultimo = get(i-1);
			set(posicao, ultimo);
			posicao++;
		}
		
		tamanho = tamanho - 1;
		setLength(tamanho);
	}
	
}charStack;
typedef s_charStack* ref_charStack;

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
// definir dados
// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	
	cout << endl << "Nova cadeia com Pushback:" << endl;
	STRING->print();
	
	STRING->free();
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02
 */
void method_02 ( )
{
// definir dados
// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING->popBack();
	
	cout << endl << "Nova cadeia com popBack:" << endl;
	STRING->print();

	STRING->free();
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03
 */
void method_03 ( )
{
// definir dados
// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING = STRING->pushFront(STRING,'A');
	
	cout << endl << "Nova cadeia com pushFront:" << endl;
	STRING->print();

	STRING->free();
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04
 */
void method_04 ( )
{
// definir dados
// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING->popFront();
	
	cout << endl << "Nova cadeia com popFront:" << endl;
	STRING->print();
	
	STRING->free();
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05
 */
void method_05 ( )
{
// definir dados
// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING = STRING->str_push_mid(STRING,'A');
	
	cout << endl << "Nova cadeia com pushMid:" << endl;
	STRING->print();
	
	STRING->free();
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06
 */
void method_06 ( )
{
// definir dados
// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	ref_charStack STRING = new s_charStack(1,'a');
	STRING->pushBack('b');
	STRING->pushBack('c');
	STRING->pushBack('d');
	STRING->pushBack('e');
	
	cout << endl << "Cadeia inicial:" << endl;
	STRING->print();
	
	STRING->popMid();
	
	cout << endl << "Nova cadeia com popMid:" << endl;
	STRING->print();

	STRING->free();	
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07
 */
void method_07 ( )
{
// definir dados
// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08
 */
void method_08 ( )
{
// definir dados
// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09
 */
void method_09 ( )
{
// definir dados
// identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10
 */
void method_10 ( )
{
// definir dados
// identificar
	cout << "\nMethod_10 - v0.0\n" << endl;
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

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
		cout << "EXEMPLO1600 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << "  0 - Method 0 " << endl;
		cout << "  1 - Method 1 " << endl;
		cout << "  2 - Method 2 " << endl;
		cout << "  3 - Method 3 " << endl;
		cout << "  4 - Method 4 " << endl;
		cout << "  5 - Method 5 " << endl;
		cout << "  6 - Method 6 " << endl;
		cout << "  7 - Method 7 " << endl;
		cout << "  8 - Method 8 " << endl;
		cout << "  9 - Method 9 " << endl;
		cout << " 10 - Method 10 " << endl;
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
			method_05( );
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
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )


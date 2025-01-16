/*
Exercicio_1411_1420 - v0.0. - 09 / 06 / 2024
Author: Ana Clara Lonczynski
*/

// ----------------------------------------------- preparacao
// dependencias
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

// ----------------------------------------------- classes
#include "Erro.hpp" // classe para tratar erros

class GetInt : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ caracteres invalidos";
	}
	
	int* getInt(const std::string& palavra, int& outSize)
	{
		int tamanho = palavra.length();
		int* array = new int[tamanho];
		int x = 0;
		
		for (int i = 0; i < tamanho; i++)
		{
			if (palavra[i] >= '0' && palavra[i] <= '9')
			{
				array[x] = palavra[i] - '0';
				x++;
			}
		}
		
		if (x == 0)
		{
			setErro(-1);
			delete[] array;
			return nullptr;
		}
		
		outSize = x;
		return array;
	}
};

class GetDouble : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ caracteres invalidos";
	}
	
	double* getdouble(const std::string& palavra, int& outSize)
	{
		int tamanho = palavra.length();
		double* array = new double[tamanho];
		int x = 0;
		
		for (int i = 0; i < tamanho; i++)
		{
			if (palavra[i] >= '0' && palavra[i] <= '9')
			{
				int num = palavra[i] - '0';
				array[x] = static_cast<double>(num);
				
				x++;
			}
		}
		
		if (x == 0)
		{
			setErro(-1);
			delete[] array;
			return nullptr;
		}
		
		outSize = x;
		return array;
	}
};
class GetBollean : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ /valor invalido/ valores validos: { true, false, T, F, 0, 1 }";
	}
	
	bool Getbollean(string palavra)
	{
		
		bool p = false;
		if (palavra == "true" || palavra == "T" || palavra == "1")
			p = true;
		else if (palavra == "false" || palavra == "F" || palavra == "0")
			p = false;
		else
			setErro(-1);
		
		return(p);
	}
};

class Contains : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ Paravra nao encontrada";
	}
	
	bool contains(string palavra)
	{
		bool teste = false;
		// Cria um objeto ifstream
		std::ifstream file("E4.txt");
		
		// Lê o conteúdo do arquivo linha por linha
		std::string line;
		
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
			if (line == palavra)
			{
				teste = true;
				file.close();
				return(teste);
			}
		}
		
		// Fecha o arquivo
		file.close();
		return teste;
	}
};

class toUpperCase : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ caracteres invalidos";
	}
	
	void touppercase (string& palavra)
	{
		bool teste = false;
		int tamanho = palavra.length();
		
		
		for(int i = 0; i < tamanho; i++)
		{
			//verificar diferenca na tabela ascii 
			if (palavra[i] >= 'a' && palavra[i] <= 'z')
			{	int dif = palavra[i] - 'a' ;
				//colocar o valor maiusculo da tabela ascii equivalente 
				palavra[i] = 'A' + dif;
				//verificar se tem letras minusculas
				teste = true;
			}
		}
		if(!teste)
		{
			setErro(-1);
		}
		
	}
};

class tolowerCase : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ caracteres invalidos";
	}
	
	void tolowercase (string& palavra)
	{
		bool teste = false;
		int tamanho = palavra.length();
		
		
		for(int i = 0; i < tamanho; i++)
		{
			//verificar diferenca na tabela ascii 
			if (palavra[i] >= 'A' && palavra[i] <= 'Z')
			{	int dif = palavra[i] - 'A' ;
				//colocar o valor maiusculo da tabela ascii equivalente 
				palavra[i] = 'a' + dif;
				//verificar se tem letras minusculas
				teste = true;
			}
		}
		if(!teste)
		{
			setErro(-1);
		}
		
	}
};

class Replace: public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ palavra nao encontrada";
	}
	
	string replace(string valor, char original, char novo) 
	{
		bool teste = false;
		for (size_t i = 0; i < valor.size(); ++i) {
			if (valor[i] == original) 
			{
				valor[i] = novo;
				teste = true;
			}
		}
		
		if(!teste)
		{
			setErro(-1);
		}
		
		return(valor);
	}
};

class Cifra : public Erro
{
public:
	// Inserir mensagem de erro
	std::string getErroMsg() const override
	{
		return "/ERRO/ caracteres invalidos";
	}
	
	void cifra (string& palavra)
	{
		
		int tamanho = palavra.length();
		
		
		for(int i = 0; i < tamanho; i++)
		{
			//verificar se sao todas letras
			if (palavra[i] >= 'a' && palavra[i] <= 'z')
			{
				if ( palavra[i] == 'x')
					palavra[i] = 'a';
				
				else if ( palavra[i] == 'y')
					palavra[i] = 'b';
				
				else if ( palavra[i] == 'z')
					palavra[i] = 'c';
				
				else 
					palavra[i] = palavra[i] + 3;
					
			}
			else
			{
				setErro(-1);
			}
		}
		
	}
};

// ----------------------------------------------- metodos
/**
  Method_00 - nao faz nada.
 */
void method_00()
{
	// nao faz nada
} // end method_00

/**
  Method_01 
 */
void method_01()
{
	// definir dados
	GetInt teste;
	std::string palavra1 = "1a2b3c4d5e"; // Exemplo de string para teste
	std::string palavra2 = "abcde"; // Exemplo de string para teste
	int size = 0;
	
	// identificar
	std::cout << "\nMethod_01 - v0.0\n" << std::endl;
	
	// testar atribuicoes
	int* result = teste.getInt(palavra1, size);
	std::cout << "Primeria palavra: " << palavra1 << std::endl;
	if (!teste.hasError())
	{
		std::cout << "Encontrei os digitos: ";
		for (int i = 0; i < size; ++i)
		{
			std::cout << result[i] << " ";
		}
		std::cout << std::endl;
		delete[] result; // Libera a memória alocada dinamicamente
	}
	else
	{
		std::cout << teste.getErroMsg() << std::endl;
	}
	std::cout  << std::endl;
	size = 0;
	result = teste.getInt(palavra2, size);
	std::cout << "Segunda palavra: " << palavra2 << std::endl;
	if (!teste.hasError()) {
		std::cout << "Encontrei os digitos: ";
		for (int i = 0; i < size; ++i) {
			std::cout << result[i] << " ";
		}
		std::cout << std::endl;
		delete[] result; // Libera a memória alocada dinamicamente
	} else {
		std::cout << teste.getErroMsg() << std::endl;
	}
	// encerrar
	pause("Apertar ENTER para continuar");
}

void method_02()
{
	// Definir dados
	GetDouble teste;
	std::string palavra = "1a2b3c4d5e"; // Exemplo de string para teste
	std::string palavra2 = "abcde"; // Exemplo de string para teste
	int size = 0;
	
	// Identificar
	std::cout << "\nMethod_02 - v0.0\n" << std::endl;
	
	// Testar atribuições
	double* result = teste.getdouble(palavra, size);
	std::cout << "Primeira palavra: " << palavra << std::endl;
	if (!teste.hasError()) {
		std::cout << "Apos a convercao: ";
		for (int i = 0; i < size; ++i) {
			// Use printf para formatar a saída de double
			printf("%7.2lf ", result[i]);
		}
		std::cout << std::endl;
		delete[] result; // Libera a memória alocada dinamicamente
	} else {
		std::cout << teste.getErroMsg() << std::endl;
	}
	std::cout << std::endl;
	
	size = 0;
	result = teste.getdouble(palavra2, size);
	std::cout << "Segunda palavra: " << palavra2 << std::endl;
	if (!teste.hasError()) {
		std::cout << "Apos a convercao: ";
		for (int i = 0; i < size; ++i) {
			// Use printf para formatar a saída de double
			printf("%7.2lf ", result[i]);
		}
		std::cout << std::endl;
		delete[] result; // Libera a memória alocada dinamicamente
	} else {
		std::cout << teste.getErroMsg() << std::endl;
	}
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_03()
{
	// Definir dados
	GetBollean teste;
	std::string palavra; // Exemplo de string para teste
	
	// Identificar
	std::cout << "\nMethod_03 - v0.0\n" << std::endl;
	
	// Entrada do usuário
	std::cout << "Digite um valor para converter para valor logico: ";
	std::cin >> palavra;
	
	// Testar atribuições
	bool result = teste.Getbollean(palavra);
	std::cout << std::endl;
	if (!teste.hasError()) {
		std::cout << "Valor convertido: " << (result ? "true" : "false") << std::endl;
	} else {
		std::cout << teste.getErroMsg() << std::endl;
	}
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_04()
{
	// Definir dados
	Contains teste;
	std::string palavra; // Exemplo de string para teste
	
	// Identificar
	std::cout << "\nMethod_04 - v0.0\n" << std::endl;
	
	std::cout << "Digite a palavra procurada: ";
	cin >> palavra;
	
	// Testar atribuições
	bool result = teste.contains(palavra);
	cout << endl;
	if (result)
	{
		cout << "Essa palavra esta no arquivo" << endl;
		
	}
	else
	{
		std::cout << teste.getErroMsg() << std::endl;
	}
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_05()
{
	// Definir dados
	toUpperCase teste;
	std::string palavra; // Exemplo de string para teste
	
	// Identificar
	std::cout << "\nMethod_05 - v0.0\n" << std::endl;
	
	std::cout << "Entrar com palavra: ";
	cin >> palavra;
	
	// Testar atribuições
	teste.touppercase(palavra);
	cout << endl;
	if (!teste.hasError())
	{
		
		cout << "Palavra modificada: " << endl;
		cout << palavra << endl;	
	}
	else
	{
		std::cout << teste.getErroMsg() << std::endl;
	}
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_06()
{
	// Definir dados
	tolowerCase teste;
	std::string palavra; // Exemplo de string para teste
	
	// Identificar
	std::cout << "\nMethod_06 - v0.0\n" << std::endl;
	
	std::cout << "Entrar com palavra: ";
	cin >> palavra;
	
	// Testar atribuições
	teste.tolowercase(palavra);
	cout << endl;
	if (!teste.hasError())
	{
		
		cout << "Palavra modificada: " << endl;
		cout << palavra << endl;	
	}
	else
	{
		std::cout << teste.getErroMsg() << std::endl;
	}
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_07( )
{
	Replace teste;
	string texto;
	char original;
	char novo;
	// Identificar
	std::cout << "\nMethod_07 - v0.0\n" << std::endl;
	
	cout << "Entrar com o texto que voce deseja modificar: ";
	cin >> texto;
	
	cout << "Entrar com a letra que sera substituida: ";
	cin >> original;
	
	cout << "Entrar com a letra que voce deseja substituir: ";
	cin >> novo;
	
	cout << teste.getErro() << endl; 
	if (!teste.hasError())
	{
		std::string resultado = teste.replace(texto, original, novo);
		std::cout << "Texto original: " << texto << std::endl;
		std::cout << "Texto modificado: " << resultado << std::endl;
	}
	else
	{
		std::cout << teste.getErroMsg() << std::endl;
	}
	// Encerrar
	pause("Apertar ENTER para continuar");
	
}

void method_08()
{
	// Definir dados
	tolowerCase teste;
	Cifra cod;
	std::string palavra; // Exemplo de string para teste
	
	// Identificar
	std::cout << "\nMethod_08 - v0.0\n" << std::endl;
	
	std::cout << "Entrar com palavra: ";
	cin >> palavra;
	
	teste.tolowercase(palavra);
	cod.cifra(palavra);
	
	if (!cod.hasError())
	{
		
		cout << "Palavra modificada: " << endl;
		cout << palavra << endl;	
	}
	else
	{
		std::cout << cod.getErroMsg() << std::endl;
	}
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_09()
{
	// Identificar
	std::cout << "\nMethod_09 - v0.0\n" << std::endl;

	// Encerrar
	pause("Apertar ENTER para continuar");
}

void method_10()
{
	// Identificar
	std::cout << "\nMethod_10 - v0.0\n" << std::endl;
	
	// Encerrar
	pause("Apertar ENTER para continuar");
}

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
		cout << "EXEMPLO1411 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << " 0 - parar " << endl;
		cout << " 1 - Method_01 " <<endl;
		cout << " 2 - Method_02 " <<endl;
		cout << " 3 - Method_03 " <<endl;
		cout << " 4 - Method_04 " <<endl;
		cout << " 5 - Method_05 " <<endl;
		cout << " 6 - Method_06 " <<endl;
		cout << " 7 - Method_07 " <<endl;
		cout << " 8 - Method_08 " <<endl;
		cout << " 9 - Method_09 " <<endl;
		cout << "10 - Method_10 " <<endl;
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
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

/*
Exemplo1211 - v0.0. - 26 / 05 / 2024
Author: Ana Clara Lonczynski
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- classes / pacotes
#include "Contato.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )
/**
  Method_01 - Mostrar certa quantidade de valores.
 */
void method_01 ( )
{
	// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	
	// definir dados
	Contato pessoa1;
	string  nome = "";
	
	cout << endl << "Insira o nome:";
	cin >> nome; getchar();

	pessoa1.setNome(nome); 
	
	if ( ! pessoa1.hasErro( ) ){
		cout << "pessoa1 - " << pessoa1.getNome ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}

	// encerrar
	pause ( "Apertar ENTER para continuar" );
	
} // end method_01 ( )

/**
  Method_02.
 */
void method_02 ( )
{
	// identificar
	cout << endl << "Method_02 - v0.0" << endl;
	
	Contato pessoa1;
	string  Fone = "";
	
	cout << endl << "Insira o telefone:";
	cin >> Fone; getchar();
	
	pessoa1.setFone(Fone); 
	
	if ( ! pessoa1.hasErro( ) ){
		cout << "pessoa1 - " << pessoa1.getFone ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
	
} // end method_02 ( )

/**
  Method_03.
 */
void method_03 ( )
{
	// identificar
	std::cout << std::endl << "Method_03 - v0.0" << std::endl;
	
	Contato pessoa1;
	string  Fone = "";
	
	cout << endl << "Insira o telefone:";
	cin >> Fone; getchar();
	
	pessoa1.telefonevalido (Fone);
	pessoa1.setFone(Fone); 
	
	if ( ! pessoa1.hasErro( ) ){
		cout << "pessoa1 - " << pessoa1.getFone ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04.
 */
void method_04 ( )
{
	// identificar
	std::cout << std::endl << "Method_04 - v0.0" << std::endl;
	
	Contato pessoa1;
	string  nome = "";
	string filename = "Pessoa1.txt";
	
//	nome = readFromFile(filename, nome);
	
	pessoa1.setNome(nome); 
	
	if ( ! pessoa1.hasErro( ) ){
		cout << "pessoa1 - " << pessoa1.getNome ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )


/**
  Method_05.
 */
void method_05 ( )
{
	// identificar
	std::cout << std::endl << "Method_05 - v0.0" << std::endl;
	
	Contato pessoa1;
	string  nome = "";
	
	cout << endl << "Insira o nome:";
	cin >> nome; getchar();
	
	pessoa1.writeNameToFile("Pessoa1.txt", nome);
	
	pessoa1.setNome(nome); 
	
	if ( ! pessoa1.hasErro( ) ){
		cout << "pessoa1 - " << pessoa1.getNome ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )
/**
  Method_06.
 */
void method_06 ( )
{
	// identificar
	std::cout << std::endl << "Method_06 - v0.0" << std::endl;
	
	//definir dados
	Contato pessoa1;
	string  nome = "";
	string  fone = "";
	ref_Contato pessoa2 = nullptr;
	string  fone2 = "";

	cout << endl << "Insira o nome:";
	cin >> nome; getchar();
	
	cout << endl << "Insira o telefone:";
	cin >> fone; getchar();
	
	pessoa1.setNome ( nome );
	pessoa1.setFone ( fone );
	
	
	if ( ! pessoa1.hasErro( ) ){
	cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
	}else{
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	}
	
	pessoa2 = new Contato ( pessoa1 );
	
	cout << endl << "Insira o novo telefone:";
	cin >> fone2; getchar();
	
	pessoa2->setFone (fone2);
	
	if ( pessoa2 ){
		cout << "Novo contato - " << pessoa2->toString( ) << endl;
	}else{
		cout << "O novo contato tem erro (" << pessoa2->getErro( ) << ")" << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07.
 */
void method_07 ( )
{
	// identificar
	std::cout << std::endl << "Method_07 - v0.0" << std::endl;
	
	// definir dados
	Contato pessoa1;
	pessoa1.readFromFile ( "Pessoa1.txt" );
	
	cout << "O arquivo Pessoa1.txt possui " << pessoa1.getsize ( ) - 1<< " numeros" << endl;
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )
/**
  Method_08.
 */
void method_08 ( )
{
	// identificar
	std::cout << std::endl << "Method_08 - v0.0" << std::endl;
	
	// definir dados
	ref_Contato pessoa2 = new Contato ( );
	int resposta; 
	string  nome = "";
	string  fone = "";
	
	cout << endl << "Insira o nome:";
	cin >> nome; getchar();
	
	cout << endl << "Insira o telefone:";
	cin >> fone; getchar();
	
	pessoa2->setNome ( nome );
	pessoa2->setFone ( fone );
	
	cout << endl <<"Voce deseja ler outro numero?" << endl;
	cout << "Coloque 0 para nao e 1 para sim! ";
	cin >> resposta;
	
	if (resposta > 0)
	{
		cout << endl << "Insira outro telefone:";
		cin >> fone; getchar();
		pessoa2->setFone ( fone );
		
		if(!pessoa2->hasErro())
		{ cout << endl; cout  << pessoa2->toString2 ( ) << endl; }
		else 
			if (!pessoa2->isPhone())
				cout << "Numero invalido" << endl;
		else
			cout << "Erro ao ler! " << endl;
	}
	else
	{
		if(!pessoa2->hasErro())
			cout << "pessoa2 - " << pessoa2->toString ( ) << endl;
		else 
			if (!pessoa2->isPhone())
				cout << "Numero invalido" << endl;
		else
			cout << "Erro ao ler! " << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )
/**
  Method_09.
 */
void method_09 ( )
{
	// identificar
	std::cout << std::endl << "Method_09 - v0.0" << std::endl;
	
	// definir dados
	Contato pessoa1;
	string Fone;
	string telefone;
	pessoa1.readFromFile ( "Pessoa1.txt" );

	cout << "Nome: " << pessoa1.getNome ( ) << endl;
	cout << endl;
	cout << "Telefone(s): " << pessoa1.getFone() << "," << pessoa1.getFone2() << endl; 
	cout << endl;
	
	if(pessoa1.getsize( ) >=  2 )
	{ 
		cout << "Alterar segundo telefone: " << endl; 
		cin >> telefone;
		pessoa1.changeFone( telefone, 1);
		
		
		pessoa1.writeToFile ( "Pessoa1.txt" , pessoa1.getsize() + 1 );
		cout << "Arquivo alterado: " << endl; 
		cout << endl;
		pessoa1.printfones ( );
	}
	else
	{
		cout << "Nao e possivel alterar o segundo numero, pois o arquivo possui apenas um numero cadastrado! " << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )
/**
  Method_10.
 */
void method_10 ( )
{
	// identificar
	std::cout << std::endl << "Method_10 - v0.0" << std::endl;
	//definir dados
	Contato pessoa1;
	pessoa1.readFromFile ( "Pessoa1.txt" );
	
	cout << "Nome: " << pessoa1.getNome ( ) << endl;
	cout << endl;
	cout << "Telefone(s): " << endl; 
	cout << endl;
	pessoa1.printfones ( );
	if(pessoa1.getsize( ) >=  2 )
	{ 
		cout << endl;
		cout << "Remover segundo telefone: " << endl; 
		pessoa1.removeFone (  1 );
		
		pessoa1.writeToFile ( "Pessoa1.txt" , pessoa1.getsize( ) + 1 );
		cout << "Arquivo alterado: " << endl; 
		cout << endl;
		pessoa1.printfones ( );
	}
	else
	{
		cout << "Nao e possivel alterar o segundo numero, pois o arquivo possui apenas um numero cadastrado! " << endl;
	}	
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
		cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << " 0 - parar - method_00 " << endl;
		cout << " 1 -  1311 - method_01" << endl;
		cout << " 2 -  1312 - method_02" << endl;
		cout << " 3 -  1313 - method_03" << endl;
		cout << " 4 -  1314 - method_04" << endl;
		cout << " 5 -  1315 - method_05" << endl;
		cout << " 6 -  1316 - method_06" << endl;
		cout << " 7 -  1317 - method_07" << endl;
		cout << " 8 -  1318 - method_08" << endl;
		cout << " 9 -  1319 - method_09" << endl;
		cout << "10 -  1320 - method_10" << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
			case 0: method_00 ( ); break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break;
			case 3: method_03 ( ); break;
			case 4: method_04 ( ); break;
			case 5: method_05 ( ); break;
			case 6: method_06 ( ); break;
			case 7: method_07 ( ); break;
			case 8: method_08 ( ); break;
			case 9: method_09 ( ); break;
			case 10: method_10 ( ); break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

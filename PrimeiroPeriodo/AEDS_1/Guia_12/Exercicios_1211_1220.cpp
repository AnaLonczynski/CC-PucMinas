/*
Exemplo1211 - v0.0. - 26 / 05 / 2024
Author: Ana Clara Lonczynski
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "mymatrix.hpp"
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
	int linhas, colunas;
	
	cout << "\nQuantas linhas: ";
	cin >> linhas; getchar();
	cout << "\nQuantas colunas: ";
	cin >> colunas; getchar();
	
	Matrix <int> int_matrix ( linhas, colunas, 0 );
	
	int_matrix.randomIntGenerate (  ); //gerar numeros aleatorios
	int_matrix.print ( );              //printar matrix
	int_matrix.fprint( "DADOS1.TXT" );  //gravar dados
	
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
	
	// definir dados
	Matrix <int> matrix  ( 2, 2, 0 );
	Matrix <int> matrix2 ( 2, 2, 0 );
	
	//ler dados
	matrix.fread ( "DADOS1.TXT" );
	matrix2 = matrix;
	
	// multiplicar cada valor pelo argumento
	matrix2 = matrix.scalar ( 3 ); 

	cout << endl << "Original: " << endl;
	matrix.print ( ); getchar();
	cout << endl << "Apos: "     << endl;
	matrix2.print ( ); getchar();
	
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
	
	// definir dados
	Matrix <int> int_matrix ( 3, 3, 0 );
	int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 0 ); 
	int_matrix.set ( 0, 2, 0 ); int_matrix.set ( 1, 0, 0 ); 
	int_matrix.set ( 1, 1, 1 ); int_matrix.set ( 1, 2, 0 );
	int_matrix.set ( 2, 0, 0 ); int_matrix.set ( 2, 1, 0 );  
	int_matrix.set ( 2, 2, 1 ); bool Result;
	
	//gerar bool
	Result = int_matrix.identidade ( );
	
	//mostrar resultado
	std::cout << std::endl << "Identidade: " << Result << std::endl;
	int_matrix.print ( );
	
	//ler dados
	int_matrix.fread ( "DADOS1.TXT" );
	Result = int_matrix.identidade ( );
	
	//mostrar resultado
	std::cout << std::endl << "Identidade: " << Result << std::endl;
	int_matrix.print ( ); 
	
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
	
	// definir dados
	Matrix <int> int_matrix1 ( 1, 1, 0 );
	Matrix <int> int_matrix2 ( 1, 1, 0 );
	bool result;
	
	// ler dados
	int_matrix1.fread ( "DADOS1.TXT" );
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	int_matrix1.print ( );
	
	// ler dados da segunda matrix
	int_matrix1.fread ( "DADOS2.TXT" );
	std::cout << "[Matiz 2 - DADOS2]"<<std::endl;
	int_matrix1.print ( );
	
	result = int_matrix1 == int_matrix1;
	cout << "Bool = " << result << endl;
	
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
	
	// definir dados
	Matrix <int> matrix1 ( 1, 1, 0 );
	Matrix <int> matrix2 ( 1, 1, 0 );
	Matrix <int> soma        ( 1, 1, 0 );

	matrix1.fread ( "DADOS1.TXT" );
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	matrix2.fread ( "DADOS2.TXT" );
	std::cout << "[Matiz 2 - DADOS2]"<<std::endl;
	matrix2.print ( );
	
	soma = matrix1.add (matrix2);
	
	std::cout << "A soma das matrizes e':" << std::endl;
	soma.print ( );
	
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
	
	Matrix <int> matrix1 ( 1, 1, 0 );
	Matrix <int> soma    ( 1, 1, 0 );
	
	matrix1.fread ( "DADOS1.TXT" );
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	soma = matrix1.addRows(-1);
	
	std::cout << "Subtracao:" << std::endl;
	soma.print ( );
	
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
	
	Matrix <int> matrix1 ( 1, 1, 0 );
	Matrix <int> soma    ( 1, 1, 0 );
	
	matrix1.fread ( "DADOS1.TXT" );
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	soma = matrix1.subtractRows(2);
	
	std::cout << "Diferencas:" << std::endl;
	soma.print ( );
	
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
	
	Matrix <int> matrix1 ( 1, 1, 0 ); 
	int linha;         int procurado;

	matrix1.fread ( "DADOS1.TXT" );
	
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	std::cout << "Procurado:" << std::endl;
	std::cin >> procurado; getchar();
	
	linha = matrix1.searchRows(procurado);
	
	if (linha == -1 ){
		std::cout << std::endl << "ERRO// Nao encontrado" << std::endl;
	}else{
		std::cout << std::endl << procurado <<  " esta na linha: " << linha << std::endl;
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
	
	Matrix <int> matrix1 ( 1, 1, 0 ); 
	int linha; int coluna; int procurado;
	
	matrix1.fread ( "DADOS1.TXT" );
	
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	std::cout << "Procurado:" << std::endl;
	std::cin >> procurado; getchar();
	
	coluna = matrix1.searchColumns(procurado);
	linha  = matrix1.searchRows(procurado);
	
	if (linha == -1 ){
		std::cout << std::endl << "ERRO// Nao encontrado" << std::endl;
	}else{
		std::cout << std::endl << procurado <<  " esta na linha: " << linha << " e na coluna: "<< coluna << std::endl;
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
	
	Matrix <int> matrix1 ( 1, 1, 0 ); int sobrepor;
	matrix1.fread ( "DADOS1.TXT" );
	
	std::cout << "[Matiz 1 - DADOS1]"<<std::endl;
	matrix1.print ( );
	
	sobrepor = matrix1.transpose();
	
	if(sobrepor == 0){
		std::cout << "[Matriz 1 - Transposta]"<<std::endl;
		matrix1.print ( );
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
		cout << " 1 -  1211 - method_01" << endl;
		cout << " 2 -  1212 - method_02" << endl;
		cout << " 3 -  1213 - method_03" << endl;
		cout << " 4 -  1214 - method_04" << endl;
		cout << " 5 -  1215 - method_05" << endl;
		cout << " 6 -  1216 - method_06" << endl;
		cout << " 7 -  1217 - method_07" << endl;
		cout << " 8 -  1218 - method_08" << endl;
		cout << " 9 -  1219 - method_09" << endl;
		cout << "10 -  1220 - method_10" << endl;
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

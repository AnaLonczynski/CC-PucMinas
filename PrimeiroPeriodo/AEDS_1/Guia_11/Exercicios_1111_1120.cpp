/*
Exemplo1100 - v0.0. - 15 / 05 / 2024
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
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos

int searchFirstOddx3 ( string filename , int tamanho)
{
	int minOddx3 = 0;
	bool found = false;
	
	for(int i=0;i<=tamanho;i++) //percorrer o arquivo
	{
		int num = filename[i];
		if (num % 2 != 0 && num % 3 == 0) 
		{
			minOddx3 = num;
			found = true;
			//std::cout << minOddx3 << std::endl;
		}
	}
	
	if (found) {
		return minOddx3;
	} else {
		return -1; // Retornar -1 se não encontrar nenhum valor ímpar múltiplo de 3
	}
}

int somararray ( string filename, int tamanho){
	
	std::ifstream inputFile(filename);	
	int soma = 0, valor;
	
	if (!inputFile.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		for(int i=0;i<=tamanho;i++){
			inputFile >> valor;
			soma = soma + valor;
			std::cout <<"Valor = " << valor <<std::endl<< "Soma  = "<< soma << std::endl;
		}
	}
	inputFile.close();
	return soma;
	
}

int arraynegativa ( string filename, int tamanho){
	
	int valor, resultado = 0;
	std::ifstream inputFile(filename);
	
	if (!inputFile.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		//sempre havera pelo menos um valor positivo(numero de linhas)
		for(int i=0;i<=tamanho;i++){
			inputFile >> valor;
			std::cout <<"Valor = " << valor <<std::endl;
			if(valor > 0){
				std::cout << valor<< "e' positivo"<<std::endl; 
				resultado ++;
			}else{
				std::cout << valor<< "e' negativo"<<std::endl; 
			}
		}
	}	
	inputFile.close();
	return resultado;
	
}

bool arrayordenada ( string filename, int tamanho){
	
	int valorAnterior, valorAtual;
	std:: ifstream file (filename);
	
	if (!file.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
		return false;
	}
	
	file >> valorAnterior; // Lendo o primeiro valor
	while (file >> valorAtual) {
		if (valorAtual < valorAnterior) {
			file.close();
			return false; // Se encontrar um valor menor, a ordem não está correta
		}
		valorAnterior = valorAtual;
	}
	
	file.close();
	return true; 
}

void showarray ( string filename, int tamanho){
	int valor;
	std::ifstream file (filename);
	
	if(!file.is_open()){
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		for(int i=0;i<=tamanho;i++){
			file >> valor;
			std::cout << i <<" = "<< valor <<std::endl;
		}
		file.close();
	}
}

void verificarposicao ( string filename, int tamanho, int minimo, int maximo, int valorprocurado){
	
	int valor;
	std::ifstream file (filename);
	
	if(!file.is_open()){
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		for(int i=0;i<=tamanho;i++){
			file >> valor;
			
			if(valor == valorprocurado){	
				
				if(valor >= minimo && valor <= maximo){
					std::cout << valor<< " esta dentro do intervalo [ "<<minimo <<":"<<maximo <<" ]"<<std::endl; 
				}else{
					std::cout << valor<< " esta fora do intervalo [ "<<minimo <<":"<<maximo <<" ]"<<std::endl; 
				}
			}
		}
		file.close();
	}
}

int multiplicarconstante ( string filename, int tamanho, int minimo, int maximo, int constante){
	
	int valor, resultado = 0;
	std::ifstream file (filename);
	
	if(!file.is_open()){
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		for(int i=0;i<=tamanho;i++){
			file >> valor;
			if(minimo < i && i <= maximo){
				std::cout << std::endl << "Valor = " << valor << std::endl;
				resultado = resultado + (valor* constante);
			}
		}
		file.close();
	}
	return resultado;
}

/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

/**
  Method_01.
 */
void method_01 ( )
{
	// identificar
	std::cout << std::endl << "Method_01 - v0.6" << std::endl;
	
	//definir dados
	int x;
	int y;
	
	//ler dados
	std::cout << "Insira o numero de valores a serem gerados: ";
	std::cin >> x; getchar(); 
	
	std::cout << "X = " << x << std::endl;
	
	//definir arranjo
	Array <int> int_Array (x, 0); 
	
	// Inicializa o gerador de números aleatórios
	std::srand(x);

	//gerar valores para o arranjo
	for(int i=0;i<=x;i++){
		y = (std::rand( ) %301)-100;
		int_Array.set(i , y);
	}
	
	//printar na tela e criar arquivo 
	int_Array.print();
	int_Array.fprint ( "DADOS.TXT" );
	
	// reciclas espaço
	int_Array.free();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02.
 */
void method_02 ( )
{
	// identificar
	std::cout << std::endl << "Method_02 - v0.0" << std::endl;
	
	// definir dados
	Array <int> int_array (5, 0); //será sobreposta pelo arranjo lido
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:"<<int_array.getLength ( )<<std::endl;
	
	for(int i=0;i<int_array.getLength ( );i++){
		if(int_array[i]%2==0){
			std::cout << int_array[i]<<std::endl;
		}
	}
	
	// reciclar espaco
	int_array.free ( ); 
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )


/**
  Method_03.
 */
void method_03 ( )
{
	// identificar
	std::cout << std::endl << "Method_03 - v0.5" << std::endl;
	
	//definir dados
	int menor, tamanho;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:"<<int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	menor = searchFirstOddx3 ("DADOS.TXT", tamanho);
	
	//std::cout << menor << std::endl;
	
	if (menor == -1) {
		std::cout << "Nenhum valor impar multiplo de 3 encontrado no arranjo." << std::endl;
	} else {
		std::cout << "O menor valor impar multiplo de 3 no arranjo e': " << menor << std::endl;
	}

	// reciclar espaco
	int_array.free ( ); 
	
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
	
	//definir dados
	int soma, tamanho;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<<int_array.getLength ( )<<std::endl<< std::endl;
	tamanho = int_array.getLength();
	
	soma = somararray("DADOS.TXT", tamanho);
	
	std::cout<<std::endl<< "A soma dos valores do arranjo e':  "<<soma<<std::endl;
	
	// reciclar espaco
	int_array.free ( ); 
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05.
 */
void method_05 ( )
{
// identificar
	std::cout << std::endl << "Method_05 - v0.1" << std::endl;
	//definir dados
	int soma, tamanho, media;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<<int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	soma = somararray("DADOS.TXT", tamanho);
	
	media = soma/tamanho;
	
	std::cout<<std::endl<< "A media dos valores do arranjo e':  "<< media <<std::endl;
	
	// reciclar espaco
	int_array.free ( ); 
	
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
	int  tamanho, resultado;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<<int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	resultado = arraynegativa("DADOS.TXT", tamanho);
	
	//mostrar resultado
	if(resultado > 1){
		std::cout<<std::endl<<"So' ha' valores positivos" <<std::endl;
	}else{
		std::cout<<std::endl<<"Todos valores sao negativos" <<std::endl;
	}
	
	// reciclar espaco
	int_array.free ( ); 
	
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
	
	//definir dados
	int  tamanho; 
	bool resultado;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<<int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	resultado = arrayordenada("DADOS.TXT", tamanho);
	
	//mostrar resultado
	if(resultado == true){
		std::cout<<std::endl<<"Os valores estao ordenados" <<std::endl;
	}else{
		std::cout<<std::endl<<"Os valores nao estao ordenados" <<std::endl;
	}
	
	// reciclar espaco
	int_array.free ( ); 
	
	// encerrar	
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )


/**
  Method_08.
 */
void method_08 ( )
{
	// identificar
	std::cout << std::endl << "Method_08 - v0.4" << std::endl;
	
	int menorvalor, maiorvalor, valorprocurado, tamanho;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	tamanho = int_array.getLength();
	std::cout << std::endl << "Tamanho do arranjo:  " << tamanho << std::endl;
	
	//mostrar arranjo
	showarray("DADOS.TXT", tamanho);
	
	//Inserir dados
	std::cout << std::endl << "Insira o valor procurado: "<< std::endl;
	std::cin  >> valorprocurado;
	
	std::cout << std::endl << "Insira o valor minimo: "   << std::endl;
	std::cin  >> menorvalor;
	
	std::cout << std::endl << "Insira o valor maximo: "   << std::endl;
	std::cin  >> maiorvalor;
	
	std::cout << "O intervalo e' ["<< menorvalor <<":"<< maiorvalor <<"]"<< std::endl
	<< "O valor procurado e':" << valorprocurado << std::endl; 
	
	//executar funcao
	verificarposicao("DADOS.TXT", tamanho, menorvalor, maiorvalor, valorprocurado);
	
	// reciclar espaco
	int_array.free ( ); 
	
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
	int menorvalor, maiorvalor, constante, tamanho, resultado;
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	tamanho = int_array.getLength();
	std::cout << std::endl << "Tamanho do arranjo:  " << tamanho << std::endl;
	
	//mostrar arranjo
	showarray("DADOS.TXT", tamanho);
	
	//Inserir dados
	std::cout << std::endl << "Insira o valor da constante: "<< std::endl;
	std::cin  >> constante;
	
	std::cout << std::endl << "Insira a posicao minima: "   << std::endl;
	std::cin  >> menorvalor;
	
	std::cout << std::endl << "Insira a posicao maxima: "   << std::endl;
	std::cin  >> maiorvalor;
	
	//executar funcao
	resultado = multiplicarconstante("DADOS.TXT", tamanho, menorvalor, maiorvalor, constante);
	
	std::cout << std::endl << "O resultado e': " << resultado << std::endl;
	
	// reciclar espaco
	int_array.free ( ); 
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

void ArraySortDown ( string filename, int tamanho){
	
	int valorAnterior, valorAtual;
	std:: ifstream file (filename);
	
	if (!file.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		file >> valorAnterior; // Lendo o primeiro valor
		//std::cout <<"Valor = " << valorAnterior <<std::endl;
		do {
			if(valorAnterior < valorAtual){
				valorAnterior = valorAnterior + valorAtual; // Inverte os valores das variaveis
				valorAtual    = valorAnterior - valorAtual; 
				valorAnterior = valorAnterior - valorAtual; 
			}
			std::cout << "valor = " << valorAtual <<std::endl;
		}while (file >> valorAtual);
		file.close();
	}
}

/**
  Method_10.
 */
void method_10 ( )
{
	// identificar
	std::cout << std::endl << "Method_10 - v0.0" << std::endl;
	
	//definir dados
	int  tamanho; 
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//mostrar arranjo
	std::cout<<std::endl<< "Antigo arranjo:  "<<std::endl;
	showarray("DADOS.TXT", tamanho);
	
	std::cout<<std::endl<< "Antigo ordenado:  "<<std::endl;
	ArraySortDown("DADOS.TXT", tamanho);
	
	// reciclar espaco
	int_array.free ( ); 
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )
/**
  Method_E1.
 */
void method_E1 ( )
{
	// identificar
	std::cout << std::endl << "Method_E1 - v0.0" << std::endl;
	
	//definir dados
	int other [ ] = { 1, 2, 3 };
	Array <int> int_array1 ( 5, other );
	Array <int> int_array2 ( 5, other );

	std::cout << endl;
	std::cout << "Inserir valores para Array_1" <<std::endl;
	int_array1.read ( );

	std::cout << "Inserir valores para Array_2"<<std::endl;
	int_array2.read ( );
	// mostrar comparacao
	std::cout << "Igualdade = " << (int_array1==int_array2) << std::endl;
	
	// reciclar espaco
	int_array1.free ( ); 
	int_array2.free ( );

	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_E1 ( )

void calculardiferencas (Array <int> array1, Array <int> array2, int tamanho1, int tamanho2){
	
	int valor1, valor2, diferencas = 0;
	
	if (tamanho1 != tamanho2) {
		std::cout << "Os arrays devem ter o mesmo tamanho."<<std::endl;
	}else{
		for(int i=0;i<tamanho1;i++){
			valor1 = array1[i];
			valor2 = array2[i];
			if(valor1 < valor2 || valor2 < valor1){
				std::cout << "Valor1 = " << valor1 << "       Valor2 = " << valor2 << std::endl;
				diferencas = valor1 - valor2;
				std::cout << "Diferencas = " << diferencas<< "\n" << std::endl;
			}
		}
	}
}
/**
  Method_E2.
 */
void method_E2 ( )
{
	// identificar
	std::cout << std::endl << "Method_E2- v0.0" << std::endl;
	
	//definir dados
	int tamanho1, tamanho2;
	Array <int> int_array1 ( 5, 0 );
	Array <int> int_array2 ( 5, 0 );
	
	tamanho1 = int_array1.getLength();
	tamanho2 = int_array2.getLength();
	
	std::cout << endl;
	std::cout << "Inserir valores para Array_1" <<std::endl;
	int_array1.read ( );
	
	std::cout << "Inserir valores para Array_2"<<std::endl;
	int_array2.read ( );
	
	// mostrar comparacao
	calculardiferencas (int_array1, int_array2, tamanho1, tamanho2);		
	
	// reciclar espaco
	int_array1.free ( ); 
	int_array2.free ( );

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
		std::cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		std::cout << "Opcoes " << endl;
		std::cout << " 0 - parar " << endl;
		std::cout << " 1 - Exercicio 1111 - Gerar Arranjo" << std::endl;
		std::cout << " 2 - Exercicio 1112" << std::endl;
		std::cout << " 3 - Exercicio 1113" << std::endl;
		std::cout << " 4 - Exercicio 1114" << std::endl;
		std::cout << " 5 - Exercicio 1115" << std::endl;
		std::cout << " 6 - Exercicio 1116" << std::endl;
		std::cout << " 7 - Exercicio 1117" << std::endl;
		std::cout << " 8 - Exercicio 1118" << std::endl;
		std::cout << " 9 - Exercicio 1119" << std::endl;
		std::cout << "10 - Exercicio 1120" << std::endl;
		std::cout << "11 - Exercicio 11E1" << std::endl;
		std::cout << "12 - Exercicio 11E2" << std::endl;
		// ler do teclado
		std::cout << std::endl << "Entrar com uma opcao: ";
		std::cin >> x;
		// escolher acao
		switch ( x )
		{
			case 0:  method_00 ( ); break;
			case 1:  method_01 ( ); break;
			case 2:  method_02 ( ); break;
			case 3:  method_03 ( ); break;
			case 4:  method_04 ( ); break;
			case 5:  method_05 ( ); break;
			case 6:  method_06 ( ); break;
			case 7:  method_07 ( ); break;
			case 8:  method_08 ( ); break;
			case 9:  method_09 ( ); break;
			case 10: method_10 ( ); break;
			case 11: method_E1 ( ); break;
			case 12: method_E2 ( ); break;
			default:
			std::cout << std::endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

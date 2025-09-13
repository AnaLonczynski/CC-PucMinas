/*
Exemplo1100 - v0.0. - 17 / 06 / 2024
Author: Ana Clara Lonczynski
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
#include <vector> // para fazer uso de vetores em alguns casos
#include <cmath>
#include "myarray.hpp"
#include "mymatrix.hpp"
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

#define MAX_SIZE 10 //definir tamanho maximo para questao 8 
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
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

void ArraySortDown ( string filename, int tamanho){
	
	int valorAnterior, valorAtual;
	std:: ifstream file (filename);
	
	if (!file.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		file >> valorAnterior; // Lendo o primeiro valor
		//std::cout <<"Valor = " << valorAnterior <<std::endl;
		while (file >> valorAtual) {
			if(valorAnterior < valorAtual){
				valorAnterior = valorAnterior + valorAtual; // Inverte os valores das variaveis
				valorAtual    = valorAnterior - valorAtual; 
				valorAnterior = valorAnterior - valorAtual; 
			}
			std::cout << "valor = " << valorAtual <<std::endl;
		}
		
		file.close();
	}
}

void method_01 ( )
{
// definir dados
// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	
	//definir dados
	int  tamanho; 
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS1.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//mostrar arranjo
	std::cout<<std::endl<< "Antigo arranjo:  "<<std::endl;
	showarray("DADOS1.TXT", tamanho);
	
	std::cout<<std::endl<< "Arranjo ordenado:  "<<std::endl;
	ArraySortDown("DADOS1.TXT", tamanho);
	
	int_array.fprint("DECRESCENTE.TXT");
	
	// reciclar espaco
	int_array.free ( ); 
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

void arrayordenada ( string filename, int tamanho){
	
	int valorAnterior, valorAtual;
	std:: ifstream file (filename);
	
	if (!file.is_open()) {
		std::cerr << "Erro ao abrir o arquivo." << std::endl;
	}else{
		
		file >> valorAnterior; // Lendo o primeiro valor
		//std::cout <<"Valor = " << valorAnterior <<std::endl;
		while (file >> valorAtual) {
			for (int i = 0; i < tamanho; ++i)  {
					if (valorAnterior > valorAtual) {						
					// Troca de valores 
					int temp =valorAtual;
					valorAnterior = valorAtual;
					valorAtual = temp;
				}
			}
			std::cout << "valor = " << valorAtual <<std::endl;
		}
		
		file.close();
	}
	
}

/**
  Method_02.
 */
void method_02 ( )
{
// identificar
	cout << endl << "Method_02 - v0.0" << endl;
	
	//definir dados
	int  tamanho; 
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS1.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//mostrar arranjo
	std::cout<<std::endl<< "Antigo arranjo:  "<<std::endl;
	showarray("DECRESCENTE.TXT", tamanho);
	
	std::cout<<std::endl<< "Arranjo ordenado:  "<<std::endl;
	arrayordenada("DESCRESCENTE.TXT", tamanho);
	
	int_array.fprint("INVERTIDOS.TXT");
	
	// reciclar espaco
	int_array.free ( ); 
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

double findmediana ( Array <int> int_array, int tamanho){
	
	double mediana;
	
	if (tamanho % 2 == 0) {
		// Se o número de elementos for par
		mediana = (int_array[tamanho / 2 - 1] + int_array[tamanho / 2]) / 2.0;
	} else {
		// Se o número de elementos for ímpar
	mediana = int_array[tamanho / 2];
	}
	
	return mediana;
}
/**
  Method_03.
 */
void method_03 ( )
{
// identificar
	cout << endl << "Method_03 - v0.0" << endl;
	
//definir dados
	int  tamanho; 
	Array <int> int_array (5, 0);
	
	//ler arranjo
	int_array.fread("DADOS1.TXT");
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//mostrar arranjo
	std::cout<<std::endl<< "Arranjo:  "<<std::endl;
	showarray("DADOS1.TXT", tamanho);
	
	double mediana = findmediana(int_array, tamanho);
	std::cout<<std::endl<< "Mediana:  "<< mediana <<std:: endl;
	
	// reciclar espaco
	int_array.free ( ); 
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

Array <int> arrayfilter (Array <int> int_array, Array <int> int_array2, int tamanho){
	
	Array <int> new_array(5,0);
	int value = 0;
	
	for(int i=0;i<tamanho;i++){
		for(int j=0;j<tamanho;j++){
			if(int_array[i] == int_array2[j]){
				value = int_array[i];
			//	new_array.set(i, value);
			}
		}
	}
	
	for(int i=0;i<=tamanho;i++){
		value = new_array[i];
		std::cout << i <<" = "<< value <<std::endl;
	}
	
	return new_array;
}

/**
  Method_04.
 */
void method_04 ( )
{
// identificar
	cout << endl << "Method_04 - v0.0" << endl;
	
	//definir dados
	int  tamanho; 
	Array <int> int_array (5, 0);
	Array <int> int_array2 (5,0);
	Array <int> array_filtrado(5,0);
	
	//ler arranjo
	int_array.fread("DADOS1.TXT");
	int_array2.fread("DADOS2.TXT");
	
	//pegar tamanho
	std::cout<<std::endl<< "Tamanho do arranjo dos arranjos:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//mostrar arranjo
	std::cout<<std::endl<< "Arranjo 1:  "<<std::endl;
	showarray("DADOS1.TXT", tamanho);
	
	std::cout<<std::endl<< "Arranjo 2:  "<<std::endl;
	showarray("DADOS2.TXT", tamanho);
	
	std::cout<<std::endl<< "Arranjo Filtrado:  "<<std::endl;
	array_filtrado = arrayfilter(int_array, int_array2, tamanho);
	
	// reciclar espaco
	int_array.free ( ); 
	
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

vector<int> lerBinarios(string filename) {
	ifstream arquivo(filename);
	vector <int> binario;   //unico meio que encontrei foi com o uso da vector
	string linha;
	int contador = 0;
	
	if (arquivo.is_open()) {
		while (getline(arquivo, linha)) {
			for (char c : linha) {
				if (c == '0' || c == '1') {
					binario.push_back(c - '0');
				}
			}
		}
		arquivo.close();
	}
	return binario;
}

// Função para converter um vetor de inteiros binários para um número decimal
int binarioParaDecimal(const vector<int>& binario) {
	int decimal = 0;
	int potencia = 1;
	
	for (auto it = binario.rbegin(); it != binario.rend(); ++it) {
		decimal += (*it) * potencia;
		potencia *= 2;
	}
	
	return decimal;
}


/**
  Method_05.
 */
void method_05 ( )
{
// identificar
	cout << endl << "Method_05 - v0.0" << endl;
	
	//definir dados
	int  tamanho; 
	Array <int> int_array (0, 0);
	
	std::cout<<std::endl<< "Tamanho do arranjo:  "<< int_array.getLength ( )<<std::endl;
	tamanho = int_array.getLength();
	
	//ler arranjo
	int_array.fread("BINARIOS1.TXT");
	
	//mostrar arranjo
	std::cout<<std::endl<< "Dados do arquivo:  "<<std::endl;
	showarray("BINARIOS1.TXT", tamanho);
	
	vector<int> binario = lerBinarios("BINARIOS1.TXT");
	std::cout << "O valor decimal e': " << binarioParaDecimal(binario) << std::endl;
	
	// reciclar espaco
	int_array.free ( );
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

void montarMatrixTridiagonal(int N, int** int_matrix) {
	
	int valor = 1;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j || i == j - 1 || i == j + 1) {
				int_matrix[i][j] = valor++;
			} else {
				int_matrix[i][j] = 0;
			}
		}
	}
}

void mostrarMatriz(int** int_matrix, int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << int_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void fprintsecundaria(int** matriz, int N, string fileName) {
	ofstream file(fileName);
	
	if (file.is_open()) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				file << matriz[i][j] << " ";
			}
			file << std::endl;
		}
		file.close();
	} 
	
}

/**
  Method_06.
 */
void method_06 ( )
{
// identificar
	cout << endl << "Method_06 - v0.0" << endl;
	
	// definir dados
	int N;
	
	cout << "\nN: ";
	cin >> N; getchar();
	
	int** new_int_matriz = new int*[N];
	for (int i = 0; i < N; ++i) {
		new_int_matriz[i] = new int[N];
	}
	
	montarMatrixTridiagonal(N, new_int_matriz);
	std::cout << "Matriz Tridiagonal Crescente:" << std::endl;
	mostrarMatriz(new_int_matriz, N);
	
	fprintsecundaria(new_int_matriz,N,"MATRIX1.TXT");
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

void montarMatrixTridiagonalInversa(int N, int** int_matrix) {
	
	int valor = N * 3 - 2;  // maior valor possivel
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i + j == N - 1 || i + j == N - 2 || i + j == N) {
				int_matrix[i][j] = valor--;
			} else {
				int_matrix[i][j] = 0;
			}
		}
	}
}
/**
  Method_07.
 */
void method_07 ( )
{
// identificar
	cout << endl << "Method_07 - v0.0" << endl;
	
	// definir dados
	int N;
	
	cout << "\nN: ";
	cin >> N; getchar();
	
	int** new_int_matriz = new int*[N];
	for (int i = 0; i < N; ++i) {
		new_int_matriz[i] = new int[N];
	}
	
	montarMatrixTridiagonalInversa(N, new_int_matriz);
	std::cout << "Matriz Tridiagonal Inversa:" << std::endl;
	mostrarMatriz(new_int_matriz, N);
	
	fprintsecundaria(new_int_matriz,N,"MATRIX2.TXT");
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )


void freadsecundaria(const std::string& filename, int matrix[MAX_SIZE][MAX_SIZE], int& size) {
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
	}
	
	size = 0;
	std::string line;
	while (std::getline(infile, line) && size < MAX_SIZE) {
		std::istringstream iss(line);
		int value;
		int colIndex = 0;
		while (iss >> value && colIndex < MAX_SIZE) {
			matrix[size][colIndex] = value; // Preenche por coluna ao invés de linha
			colIndex++;
		}
		size++;
	}
	infile.close();
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
	std::cout << "Matriz lida:" << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool isPowerLine(int* line, int length) {
	if (length < 2) return false;
	
	int base = line[0];
	for (int i = 1; i < length; ++i) {
		if (line[i] != pow(base, i)) {
			return false;
		}
	}
	return true;
}

/**
  Method_08.
 */
void method_08 ( )
{
// identificar
	cout << endl << "Method_08 - v0.0" << endl;
	
	int matrix[MAX_SIZE][MAX_SIZE], size = 4;
	
	freadsecundaria("MATRIX3.TXT", matrix, size);
	printMatrix(matrix, size);
	
	bool allLinesArePowers = true;
	for (int i = 0; i < size; ++i) {
		if (!isPowerLine(matrix[i], size)) {
			allLinesArePowers = false;
			break;
		}
	}
	
	if (allLinesArePowers) {
		std::cout << "A matriz lida apresenta potencia por linha" << std::endl;
	} else {
		std::cout << "A matriz lida nao apresenta potencia por linha" << std::endl;
	}
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )



bool isPowerColumn(int matrix[MAX_SIZE][MAX_SIZE], int size) {
	for (int j = 0; j < size; ++j) {
		int base = matrix[j][0];
		for (int i = 1; i < size; ++i) {
			if (matrix[i][j] != pow(base, i)) {
				return false;
			}
		}
	}
	return true;
}

/**
  Method_09.
 */
void method_09 ( )
{
// identificar
	cout << endl << "Method_09 - v0.0" << endl;
	
	int matrix[MAX_SIZE][MAX_SIZE], size;
	
	freadsecundaria("MATRIX4.TXT", matrix, size);
	printMatrix(matrix, size);
	
	if (isPowerColumn(matrix, MAX_SIZE)) {
		std::cout << "A matriz e' uma matriz de potencias por coluna." << std::endl;
	} else {
		std::cout << "A matriz NAO e' uma matriz de potencias por coluna." << std::endl;
	}
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

struct Supermercado {
	string nome;
	int codigo;
	double precoProduto;
};

vector<Supermercado> lerDadosArquivo(string nomeArquivo) {
	vector<Supermercado> supermercados;
	ifstream arquivo(nomeArquivo);
	
	if (!arquivo.is_open()) {
		cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
	}
	
	int N;
	arquivo >> N;  // Número de supermercados
	
	supermercados.resize(N+1); // Redimensiona o vetor para conter N supermercados
	
	// Lendo os dados de cada supermercado
	for (int i = 0; i <= N; ++i) {
		arquivo >> supermercados[i].nome >> supermercados[i].codigo >> supermercados[i].precoProduto;
	}
	
	arquivo.close();
	
	return supermercados;
}

int returnN (string nomeArquivo) {
	vector<Supermercado> supermercados;
	ifstream arquivo(nomeArquivo);
	
	if (!arquivo.is_open()) {
		cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
	}
	
	int N;
	arquivo >> N;  // Número de supermercados

	arquivo.close();
	
	return N;
}

/**
  Method_10.
 */
void method_10 ( )
{
// identificar
	cout << endl << "Method_10 - v0.0" << endl;
	
	vector<Supermercado> supermercados = lerDadosArquivo("DADOS3.TXT");
	// Calculando o preço médio do produto
	int N = returnN("DADOS3.TXT");
	double somaPrecos = 0.0;
	int encontrados = 0;
	
	for (int i = 0; i < N; ++i) {
		somaPrecos += supermercados[i].precoProduto;
	}
	
	double precoMedio = somaPrecos / N;
	
	// Encontrando pelo menos dois supermercados com preços inferiores à média
	cout << "Preco medio do produto: R$ "<< precoMedio << endl;
	cout << endl<< "Dois mercados com preço menor que a media: "<< precoMedio << endl;

	for (int i = 0; i <= N; ++i) {
		if (supermercados[i].precoProduto < precoMedio) {
			cout << supermercados[i].nome << " (Codigo: " << supermercados[i].codigo << ") - R$ " << supermercados[i].precoProduto << endl;
			encontrados++;
			if (encontrados == 2) break; // Quando encontrar dois supermercados, para de procurar
		}
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
		cout << " 0 - parar " << endl;
		cout << " 1 - Questao 1 " << endl;
		cout << " 2 - Questao 2" << endl;
		cout << " 3 - Questao 3" << endl;
		cout << " 4 - Questao 4" << endl;
		cout << " 5 - Questao 5" << endl;
		cout << " 6 - Questao 6" << endl;
		cout << " 7 - Questao 7" << endl;
		cout << " 8 - Questao 8" << endl;
		cout << " 9 - Questao 9" << endl;
		cout << "10 - Questao 10" << endl;
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
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/

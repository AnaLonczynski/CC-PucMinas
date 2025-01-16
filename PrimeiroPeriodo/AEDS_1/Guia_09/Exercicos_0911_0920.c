/**
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Autor:   Matricula: 0860668  Nome: Ana Clara Lonczynski
 * Versao:  1.0                Data: 19/03/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

const int MAX = 10; // tamanho maximo

void init_int_matrix ( int value, 
	int m, int n, int matrix [ ][MAX] )
{
	int   x = 0, y = 0;
	for ( x=0; x<m; x=x+1 )
	{   for ( y=0; y<n; y=y+1 )
	{   matrix [x][y] = value;  }
	}
} // end init_int_matrix ( )

void print_int_matrix ( int m, int n, int matrix [ ][MAX] )
{
	int x = 0, y = 0;
	for ( x=0; x<m; x=x+1 )
	{   for ( y=0; y<n; y=y+1 )
	{   printf ( "%d\t", matrix [x][y] );  }
		printf ( "\n" );
	}
} // end print_int_matrix( )

void scan_int_matrix ( int m, int n, int matrix [ ][MAX] )
{
	// definir dados 
	int x = 0, y = 0, z = 0;
	
	for ( x=0; x < m; x++){
		for ( y=0; y<n; y=y+1 )
		{
			// ler dado
			printf ("Insira Valor:");
			scanf  ("%d", &z ); getchar ( );
			// guardar dado
			matrix [x][y] = z;
		} // end for
		
	}
}
/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01 - Exemplo 0911" );
	
	int l = 0;
	int c = 0;
	int matrix [10][MAX];
	
	printf("\nDigite a quantidade de linhas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nDigite a quantidade de colunas:");
	scanf("%d", &c); getchar ( );
	
	while(c <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de colunas:");
		scanf("%d", &c); getchar ( );
	}
	
    scan_int_matrix  (        l, c, matrix );
	print_int_matrix (        l, c, matrix );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

void fscan_int_matrix ( char filename [ ], int m, int n, int matrix [ ][MAX] )
{
	// definir dados locais
	
	int x = 0, y = 0, z = 0;
	
	FILE *arquivo = fopen ( filename, "w" );
	
	fscanf  ( arquivo, "%d", &m );  
	fscanf  ( arquivo, "%d", &n );
	
	for ( x=0; x < m; x++){
		for ( y=0; y<n; y=y+1 )
		{
			// ler dado
			fscanf  ( arquivo, "%d", &z );
			// guardar dado
			matrix [x][y] = z;
		} // end for
	}
	
	// fechar arquivo 
	fclose ( arquivo );
} // end fscan_int_matrix( )

/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo02 - Exemplo 0912\n" );
	
	
	int n = 3;
	int m = 3;
	int matrix [10][MAX];
	char filename [] = "ARQUIVO.TXT";
	
	
	fscan_int_matrix ( filename, m, n, matrix);
	print_int_matrix (           m, n, matrix);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

void printDiagonalDoubleMatrix ( int m, int n, int matrix [ ][MAX] )
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i != j) {
				matrix[i][j] = 0;
			}
		}
	}
} // end print_int_matrix( )

/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 - Exemplo 0913" );
	
	int l = 0;
	int matrix [10][MAX];
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	
	scan_int_matrix 		   (l, l, matrix );
	printDiagonalDoubleMatrix  (l, l, matrix );
	print_int_matrix 		   (l, l, matrix );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )


void printSDiagonalDoubleMatrix ( int m, int matrix [ ][MAX] ){
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (j != (m - i - 1)) {
				matrix[i][j] = 0;
				
			}
		}
	}
}
/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04 - Exemplo 0914" );
	
	int l = 0;
	int matrix [10][MAX];
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	
	init_int_matrix			   ( 3, l , l, matrix);
	printSDiagonalDoubleMatrix ( l, matrix 		 );
	print_int_matrix           (l, l, matrix 	 );

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05 - Exemplo 0915" );
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value >= 0){
		printf("\nERRO: Insira apenas valores negativos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printDiagonalDoubleMatrix  (l, l, matrix 		);
	print_int_matrix           (l, l, matrix 		);

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06 - Exemplo 0916" );
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value < 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printDiagonalDoubleMatrix  (l, l, matrix 		);
	print_int_matrix           (l, l, matrix 		);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo07 - Exemplo 0917" );
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value >= 0){
		printf("\nERRO: Insira apenas valores negativos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printSDiagonalDoubleMatrix (l,    matrix 		);
	print_int_matrix           (l, l, matrix 		);

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo08 - Exemplo 0918" );
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value < 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printSDiagonalDoubleMatrix (l,   matrix 		);
	print_int_matrix           (l, l, matrix 		);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

bool allZerosLTriangleDoubleMatrix(int n, int matrix[][10]) {
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 - Exemplo 0919" );
	
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value > 0){
		printf("\nERRO: Insira apenas valores negativos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printSDiagonalDoubleMatrix (l,    matrix 		);
	print_int_matrix           (l, l, matrix 		);
	
	
	bool result = allZerosLTriangleDoubleMatrix(l, matrix);
	
	if(result) {
		printf("\nTodos os valores abaixo da diagonal principal sao zeros.\n");
	} else {
		printf("\nAlguns valores abaixo da diagonal principal nao sao zeros.\n");
	}
	
} // fim metodo09 ( )

/**
 * Metodo10.
 */
void metodo10 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo10 - Exemplo 0920" );
	
	int l = 0;
	int matrix [10][MAX];
	int value = 0;
	
	printf("\nDigite a quantidade de linhas e colunas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nvalue = ");
	scanf("%d", &value); getchar ( );
	
	while(value < 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nvalue = ");
		scanf("%d", &value); getchar ( );
	}
	
	init_int_matrix			   (value, l , l, matrix);
	printSDiagonalDoubleMatrix (l,   matrix 		);
	print_int_matrix           (l, l, matrix 		);
	
	
	bool result10 = allZerosLTriangleDoubleMatrix(l, matrix);
	
	if(result10) {
		printf("\nTodos os valores abaixo da diagonal principal sao zeros.\n");
	} else {
		printf("\nAlguns valores abaixo da diagonal principal nao sao zeros.\n");
	}

	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo10 ( )

void init_int_matrixE1(int **matriz, int linhas, int colunas) {
	int valor = 1;
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = valor++;
		}
	}
}

void fprintf_int_matrix( char filename [ ], int m, int n, int **matrix )
{
	// definir dados locais
	
	int x = 0, y = 0;
	
	FILE *arquivo = fopen ( filename, "w" );
	
	fprintf  ( arquivo, "%d\n", m );  
	fprintf  ( arquivo, "%d\n", n );
	
	for ( x=0; x < m; x++){
		for ( y=0; y<n; y=y+1 )
		{
			fprintf(arquivo, "%d ", matrix[x][y]);
		}
		fprintf(arquivo, "\n");
		 // end for
	}
	// fechar arquivo 
	fclose ( arquivo );
}

void metodo11 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo11 - Exemplo 09E1" );
	
	int l = 0;
	int c = 0;
	char filename [] = "ARQUIVOE1.TXT";
	
	printf("\nDigite a quantidade de linhas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nDigite a quantidade de colunas:");
	scanf("%d", &c); getchar ( );
	
	while(c <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de colunas:");
		scanf("%d", &c); getchar ( );
		
	int **matrix = (int **)malloc(l * sizeof(int *));
	for (int i = 0; i < l; i++) {
		matrix[i] = (int *)malloc(c * sizeof(int));
	}
		
	}
	
	int **matrix = (int **)malloc(l * sizeof(int *));
	for (int i = 0; i < l; i++) {
		matrix[i] = (int *)malloc(c * sizeof(int));
	}
	init_int_matrixE1  (  matrix, l , c);
	fprintf_int_matrix ( filename, l, c, matrix);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo11 ( )

void init_int_matrixE2(int **matriz, int linhas, int colunas) {
	int valor = linhas * colunas;
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = valor--;
		}
	}
}

void metodo12 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo12 - Exemplo 09E2" );
	
	int l = 0;
	int c = 0;
	char filename [] = "ARQUIVOE2.TXT";
	
	printf("\nDigite a quantidade de linhas:");
	scanf("%d", &l); getchar ( );
	
	while(l <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de linhas:");
		scanf("%d", &l); getchar ( );
	}
	
	printf("\nDigite a quantidade de colunas:");
	scanf("%d", &c); getchar ( );
	
	while(c <= 0){
		printf("\nERRO: Insira apenas valores positivos.");
		printf("\nDigite a quantidade de colunas:");
		scanf("%d", &c); getchar ( );
		
		int **matrix = (int **)malloc(l * sizeof(int *));
		for (int i = 0; i < l; i++) {
			matrix[i] = (int *)malloc(c * sizeof(int));
		}
		
	}
	
	int **matrix = (int **)malloc(l * sizeof(int *));
	for (int i = 0; i < l; i++) {
		matrix[i] = (int *)malloc(c * sizeof(int));
	}
	init_int_matrixE2  (  matrix, l , c);
	fprintf_int_matrix ( filename, l, c, matrix);
	
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo12 ( )


// -------------------------- definicao do metodo principal

int main ( void )
{
	// definir dados/resultados
	int opcao = 0;
	
	// repetir ate' desejar parar
	do
	{
		// identificar
		printf ( "\n" );             // para saltar linha
		printf ( "%s\n", "Lista_04 - v.0.1 - 25/03/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski" );
		
		// mostrar opcoes
		printf ( "%s\n", "Opcoes:"         );
		printf ( "%s\n", "  0 - parar"      );
		printf ( "%s\n", "  1 - metodo 01   2 - metodo 02" );
		printf ( "%s\n", "  3 - metodo 03   4 - metodo 04" );
		printf ( "%s\n", "  5 - metodo 05   6 - metodo 06" );
		printf ( "%s\n", "  7 - metodo 07   8 - metodo 08" );
		printf ( "%s\n", "  9 - metodo 09  10 - metodo 10" );
		printf ( "%s\n", " 11 - metodo 11  12 - metodo 12" );
		printf ( "%s\n", "" );        // para saltar linha
		
		// ler opcao
		printf ( "%s", "Qual a sua opcao? " );
		scanf  ( "%d", &opcao ); getchar ( );
		printf ( "%d",  opcao );
		
		// escolher acao
		switch ( opcao )
		{
			case  0:               break;
			case  1: metodo01 ( ); break;
			case  2: metodo02 ( ); break;
			case  3: metodo03 ( ); break;
			case  4: metodo04 ( ); break;
			case  5: metodo05 ( ); break;
			case  6: metodo06 ( ); break;
			case  7: metodo07 ( ); break;
			case  8: metodo08 ( ); break;
			case  9: metodo09 ( ); break;
			case 10: metodo10 ( ); break;
			case 11: metodo11 ( ); break;
			case 12: metodo12 ( ); break;
		default:
			printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
			break;
		} // fim escolher
	}
	while ( opcao != 0 );
	
	// encerrar execucao
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	
} // end main ( )



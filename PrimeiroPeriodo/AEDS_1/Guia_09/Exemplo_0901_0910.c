/**
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Autor:   Matricula: 0860668  Nome: Ana Clara Lonczynski
 * Versao:  1.0                Data: 02/05/2024
 */

#include "io.h"


/**
  printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
  @param rows - quantidade de linhas
  @param columns - quantidade de colunas
  @param matrix - grupo de valores inteiros
 */

void printIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
	// definir dado local
		int x = 0;
		int y = 0;
	// mostrar valores na matriz
	for ( x=0; x<rows; x=x+1 )
	{
		for ( y=0; y<columns; y=y+1 )
		{
			// mostrar valor
			IO_printf ( "%3d\t", matrix [ x ][ y ] );
		} // end for
		IO_printf ( "\n" );
	} // end for
} // end printIntMatrix ( )

/**
 * Metodo01.
 */
void metodo01 ( void )
{	
	// definir dado
			int matrix [ ][3] = { 
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};
	// identificar
			IO_id ( "Metodo01 - Exemplo 0901" );
	// executar o metodo auxiliar
			printIntMatrix ( 3, 3, matrix );
		
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )



/**
  readIntMatrix - Ler arranjo bidimensional com valores inteiros.
  @param rows - quantidade de linhas
  @param columns - quantidade de colunas
  @param matrix - grupo de valores inteiros
 */
void readIntMatrix ( int rows, int columns, int matrix[ ][columns] )
	{
	// definir dados locais
		int x = 0;
		int y = 0;
		int z = 0;
		chars text = IO_new_chars ( STR_SIZE );
		
	// ler e guardar valores em arranjo
	for ( x=0; x<rows; x=x+1 )
	{
		for ( y=0; y<columns; y=y+1 )
		{
			// ler valor
			strcpy ( text, STR_EMPTY );
			z = IO_readint ( IO_concat (
				IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),
				IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
			// guardar valor
			matrix [ x ][ y ] = z;
		} // end for
	} // end for
} // end readIntMatrix ( )


/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// definir dados
		int n = 2; // quantidade de valores
		int matrix [ n ][ n ];
	// identificar
		IO_id ( "Metodo02 - Exemplo 0902" );
	// ler dados
		readIntMatrix ( n, n, matrix );
	// mostrar dados
		IO_printf ( "\n" );
		printIntMatrix ( n, n, matrix );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )


/**
  fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
  @param fileName - nome do arquivo
  @param rows - quantidade de linhas
  @param columns - quantidade de colunas
  @param matrix - grupo de valores inteiros
 */
void fprintIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
	FILE* arquivo = fopen ( fileName, "wt" );
	int x = 0;
	int y = 0;
// gravar quantidade de dados
	IO_fprintf ( arquivo, "%d\n", rows );
	IO_fprintf ( arquivo, "%d\n", columns );
// gravar valores no arquivo
	for ( x=0; x<rows; x=x+1 )
	{
		for ( y=0; y<columns; y=y+1 )
		{
			// gravar valor
			IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
		} // end for
	} // end for
// fechar arquivo
	fclose ( arquivo );
} // end fprintIntMatrix ( )


/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// definir dados
	int rows = 0;
	int columns = 0;

	// identificar
	printf ( "\n%s"  , "Metodo03 - Exemplo 0903" );
	
	// ler dados
	rows = IO_readint ( "\nrows = " );
	columns = IO_readint ( "\ncolumns = " );
	IO_printf ( "\n" );
	if ( rows <= 0 || columns <= 0 )
	{
		IO_println ( "\nERRO: Valor invalido." );
	}
	else
	{
		// reservar espaco
		int matrix [ rows ][ columns ];
		// ler dados
		readIntMatrix ( rows, columns, matrix );
		// mostrar dados
		IO_printf ( "\n" );
		printIntMatrix ( rows, columns, matrix );
		// gravar dados
		IO_printf ( "\n" );
		fprintIntMatrix( "MATRIX1.TXT", rows, columns, matrix );
	} // end if
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )


/**
  freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
  @return quantidade de linhas da matriz
  @param fileName - nome do arquivo
 */
int freadMatrixRows ( chars fileName )
{
// definir dados locais
	int n = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
//	ints array = NULL;
// ler a quantidade de dados
	IO_fscanf ( arquivo, "%d", &n );
	if ( n <= 0 )
	{
		IO_println ( "ERRO: Valor invalido." );
		n = 0;
	} // end if
// retornar dado lido
	return ( n );
} // end freadMatrixRows ( )
/**
  freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
  @return quantidade de colunas da matriz
  @param fileName - nome do arquivo
 */
int freadMatrixColumns ( chars fileName )
{
// definir dados locais
	int n = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
	IO_fscanf ( arquivo, "%d", &n );
	IO_fscanf ( arquivo, "%d", &n );
	if ( n <= 0 )
	{
		IO_println ( "ERRO: Valor invalido." );
		n = 0;
	} // end if
// retornar dado lido
	return ( n );
} // end freadMatrixColumns ( )

/**
  freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
  @param fileName - nome do arquivo
  @param rows - quantidade de valores
  @param columns - quantidade de valores
  @param matrix - grupo de valores inteiros
 */
void freadIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
	int x = 0;
	int y = 0;
	int z = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
	IO_fscanf ( arquivo, "%d", &x );
	IO_fscanf ( arquivo, "%d", &y );
	if ( rows <= 0 || rows > x ||
		columns <= 0 || columns > y )
	{
		IO_println ( "ERRO: Valor invalido." );
	}
	else
	{
		// ler e guardar valores em arranjo
		x = 0;
		while ( ! feof ( arquivo ) && x < rows )
		{
			y = 0;
			while ( ! feof ( arquivo ) && y < columns )
			{
				// ler valor
				IO_fscanf ( arquivo, "%d", &z );
				// guardar valor
				matrix [ x ][ y ] = z;
				// passar ao proximo
				y = y+1;
			} // end while
			// passar ao proximo
			x = x+1;
		} // end while
	} // end if
// fechar arquivo
	fclose ( arquivo );
} // end freadIntMatrix ( )

/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04 - Exemplo 0904" );
	
	
// definir dados
	int rows = 0;
	int columns = 0;
	
// ler dados
	rows = freadMatrixRows ( "MATRIX1.TXT" );
	columns = freadMatrixColumns ( "MATRIX1.TXT" );
	
	if ( rows <= 0 || columns <= 0 )
	{
		IO_println ( "\nERRO: Valor invalido." );
	}
	else
	{
		// definir armazenador
		int matrix [ rows ][ columns ];
		// ler dados
		freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
		// mostrar dados
		IO_printf ( "\n" );
		printIntMatrix ( rows, columns, matrix );
	} // end if
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )


/**
  copyIntMatrix - Copiar matriz com valores inteiros.
  @param rows - quantidade de valores
  @param columns - quantidade de valores
  @param matrix - grupo de valores inteiros
 */
void copyIntMatrix ( int rows, int columns,
	int matrix2[ ][columns], int matrix1[ ][columns] )
{
// definir dados locais
	int x = 0;
	int y = 0;
	if ( rows <= 0 || columns <= 0 )
	{
		IO_println ( "ERRO: Valor invalido." );
	}
	else
	{
		// copiar valores em matriz
		for ( x = 0; x < rows; x = x + 1 )
		{
			for ( y = 0; y < columns; y = y + 1 )
			{
				// copiar valor
				matrix2 [ x ][ y ] = matrix1 [ x ][ y ];
			} // end for
		} // end for
	} // end if
} // end copyIntMatrix ( )


/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05 - Exemplo 0905" );
	
	{
// definir dados
		int rows = 0;
		int columns = 0;
		
// ler dados
		rows = freadMatrixRows ( "MATRIX1.TXT" );
		columns = freadMatrixColumns ( "MATRIX1.TXT" );
		
		if ( rows <= 0 || columns <= 0 )
		{
			IO_println ( "\nERRO: Valor invalido." );
		}
		else
		{
			// definir armazenadores
			int matrix [ rows ][ columns ];
			int other [ rows ][ columns ];
			// ler dados
			freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
			// copiar dados
			copyIntMatrix ( rows, columns, other, matrix );
			// mostrar dados
			IO_printf ( "\nOriginal\n" );
			printIntMatrix ( rows, columns, matrix );
			// mostrar dados
			IO_printf ( "\nCopia\n" );
			printIntMatrix ( rows, columns, other );
		} // end if
	
	}
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

	
	/**
	  transposeIntMatrix - Transpor valores inteiros em matriz.
	  @param rows - quantidade de valores
	  @param columns - quantidade de valores
	  @param matrix2 - grupo de valores inteiros (transposto)
	  @param matrix1 - grupo de valores inteiros
	 */
	void transposeIntMatrix ( int rows, int columns,
		int matrix2[ ][rows] , int matrix1[ ][columns] )
	{
// definir dados locais
		int x = 0;
		int y = 0;
// percorrer a matriz
		for ( x = 0; x<rows; x=x+1 )
		{
			for ( y = 0; y<columns; y=y+1 )
			{
				matrix2[ y ][ x ] = matrix1 [ x ][ y ];
			} // end for
		} // end for
	} // end transposeIntMatrix ( )

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06 - Exemplo 0906" );

	
// definir dados
		int matrix1 [ ][2] = { {1, 0} ,
			{0, 1} };
		int matrix2 [ ][2] = { {0, 0} ,
			{0, 0} };
		int matrix3 [ ][3] = { {1, 2, 3} ,
			{4, 5, 6} };
		int matrix4 [ ][3] = { {1, 2, 3} ,
			{4, 5, 6} ,
			{7, 8, 9} };
		
// testar dados
		IO_println ( "\nMatrix1 " );
		printIntMatrix( 2, 2, matrix1 );
		transposeIntMatrix ( 2, 2, matrix2, matrix1 );
		IO_println ( "\nMatrix2" );
		printIntMatrix( 2, 2, matrix2 );
		IO_println ( "\nMatrix3" );
		printIntMatrix( 2, 3, matrix3 );
		transposeIntMatrix ( 2, 3, matrix4, matrix3 );
		IO_println ( "\nMatrix4" );
		printIntMatrix( 3, 2, matrix4 );

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

/**
  isIdentity - Testar se matriz identidade.
  @return - true, se todos os dados forem iguais a zero;
  false, caso contrario
  @param rows - quantidade de valores
  @param columns - quantidade de valores
  @param matrix - grupo de valores inteiros
 */
bool isIdentity ( int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
	bool result = false;
	int x = 0;
	int y = 0;
// testar condicao de existencia
	if ( rows <= 0 || columns <= 0 ||
		rows != columns )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
	}
	else
	{
		// testar valores na matriz
		x = 0;
		result = true;
		while ( x<rows && result )
		{
			y = 0;
			while ( y<columns && result )
			{
				// testar valor
				if ( x == y )
				{
					result = result && ( matrix [ x ][ y ] == 1 );
				}
				else
				{
					result = result && ( matrix [ x ][ y ] == 0 );
				} // end if
				// passar ao proximo
				y = y + 1;
			} // end while
			// passar ao proximo
			x = x + 1;
		} // end while
	} // end if
// retornar resposta
	return ( result );
} // end isIdentity ( )

/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo07 - Exemplo 0907" );
	
	// definir dados
	int matrix1 [ ][2] = { {0, 0} ,
		{0, 0} };
	int matrix2 [ ][3] = { {1, 2, 3} ,
		{4, 5, 6} };
	int matrix3 [ ][2] = { {1, 0} ,
		{0, 1} };
	
// testar dados
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
	IO_printf ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 3, matrix2 );
	IO_printf ( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) );
	IO_println ( "\nMatrix3" );
	printIntMatrix( 2, 2, matrix3 );
	IO_printf ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

/**
  isEqual - Testar se matrizes iguais.
  @return - true, se todos os dados forem iguais;
  false, caso contrario
  @param rows - quantidade de valores
  @param columns - quantidade de valores
  @param matrix1 - grupo de valores inteiros (1)
  @param matrix2 - grupo de valores inteiros (2)
 */
bool isEqual ( int rows, int columns,
	int matrix1[ ][columns], int matrix2[ ][columns] )
{
// definir dados locais
	bool result = true;
	int x = 0;
	int y = 0;
// mostrar valores na matriz
	x = 0;
	while ( x<rows && result )
	{
		y = 0;
		while ( y<columns && result )
		{
			// testar valor
			result = result && 
			( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );
			// passar ao proximo
			y = y + 1;
		} // end while
		// passar ao proximo
		x = x + 1;
	} // end while
// retornar resposta
	return ( result );
} // end isEqual ( )

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// definir dados
	int matrix1 [ ][2] = { {0, 0} ,
		{0, 0} };
	int matrix2 [ ][2] = { {1, 2} ,
		{3, 4} };
	int matrix3 [ ][2] = { {1, 0} ,
		{0, 1} };
// identificar
	IO_id ( "Method_08 - v0.0" );
// testar dados
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 2, matrix2 );
	IO_printf ( "isEqual (matrix1, matrix2) = %d",
		isEqual (2, 2, matrix1, matrix2) );
	copyIntMatrix ( 2, 2, matrix1, matrix3 );
	copyIntMatrix ( 2, 2, matrix2, matrix3 );
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 2, matrix2 );
	IO_printf ( "isEqual (matrix1, matrix2) = %d",
		isEqual (2, 2, matrix1, matrix2) );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )


/**
  addIntMatrix - Somar matrizes com inteiros.
  @param rows - quantidade de valores
  @param columns - quantidade de valores
  @param matrix3 - grupo de valores inteiros resultante
  @param matrix1 - grupo de valores inteiros (1)
  @param k - constante para multiplicar o segundo termo
  @param matrix2 - grupo de valores inteiros (2)
 */
void addIntMatrix ( int rows, int columns,
	int matrix3[ ][columns],
	int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
// definir dados locais
	int x = 0;
	int y = 0;
// mostrar valores na matriz
	for ( x=0; x<rows; x=x+1 )
	{
		for ( y = 0; y < columns; y = y + 1 )
		{
			// somar valores
			matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];
		} // end for
	} // end for
} // end addIntMatrix ( )

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 - Exemplo 0909" );
	// definir dados
	int matrix1 [ ][2] = { {1, 2},
		{3, 4} };
	int matrix2 [ ][2] = { {1, 0},
		{0, 1} };
	int matrix3 [ ][2] = { {0, 0},
		{0, 0} };
// testar dados
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 2, matrix2 );
// somar matrizes
	addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );
	IO_println ( "\nMatrix3" );
	printIntMatrix( 2, 2, matrix3 );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

/**
  mulIntMatrix - Multiplicar matrizes com inteiros.
  @param rows3 - quantidade de linhas da matriz (3)
  @param columns3 - quantidade de colunas da matriz (3)
  @param matrix3 - grupo de valores inteiros resultante
  @param rows1 - quantidade de linhas da matriz (1)
  @param columns1 - quantidade de colunas da matriz (1)
  @param matrix1 - grupo de valores inteiros (1)
  @param rows2 - quantidade de linhas da matriz (2)
  @param columns2 - quantidade de colunas da matriz (2)
  @param matrix2 - grupo de valores inteiros (2)
 */
void mulIntMatrix ( int rows3, int columns3,
	int matrix3[ ][columns3],
	int rows1, int columns1,
	int matrix1[ ][columns1], 
	int rows2, int columns2,
	int matrix2[ ][columns2] )
{
// definir dados locais
	int x = 0;
	int y = 0;
	int z = 0;
	int soma = 0;
	if ( rows1 <= 0 || columns1 <= 0 ||
		rows2 <= 0 || columns2 <= 0 ||
		rows3 <= 0 || columns3 <= 0 ||
		columns1 != rows2 ||
		rows1 != rows3 ||
		columns2 != columns3 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
	}
	else
	{
		// percorrer valores na matriz resultante
		for ( x=0; x<rows3; x=x+1 )
		{
			for ( y = 0; y < columns3; y = y + 1 )
			{
				// somar valores
				soma = 0;
				for ( z = 0; z < columns1; z = z + 1 ) // ou (z < rows2)
				{
					soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];
				} // end for
				// guardar a soma
				matrix3 [ x ][ y ] = soma;
			} // end for
		} // end for
	} // end if
} // end mulIntMatrix ( )

/**
 * Metodo10.
 */
void metodo10 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo10 - Exemplo 0910" );
	// definir dados
	int matrix1 [ ][2] = { {1, 2},
		{3, 4} };
	int matrix2 [ ][2] = { {1, 0},
		{0, 1} };
	int matrix3 [ ][2] = { {0, 0},
		{0, 0} };
// identificar
	IO_id ( "EXEMPLO0910 - Method_09 - v0.0" );
// testar produto
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 2, matrix2 );
// multiplicar matrizes
	mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );
	IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );
	printIntMatrix( 2, 2, matrix3 );
// outro teste
	IO_println ( "\nMatrix2" );
	printIntMatrix( 2, 2, matrix2 );
	IO_println ( "\nMatrix1" );
	printIntMatrix( 2, 2, matrix1 );
// multiplicar matrizes
	mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );
	IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );
	printIntMatrix( 2, 2, matrix3 );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo10 ( )


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
		printf ( "%s\n", "Lista_09 - v.0.1 - 02/05/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski" );
		
		// mostrar opcoes
		printf ( "%s\n", "Opcoes:"         );
		printf ( "%s\n", " 0 - parar"      );
		printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
		printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
		printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
		printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
		printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
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

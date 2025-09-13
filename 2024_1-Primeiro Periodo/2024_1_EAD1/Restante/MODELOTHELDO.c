/**
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Autor:   Matricula: 0860668  Nome: Ana Clara Lonczynski
 * Versao:  1.0                Data: 06/05/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01" );
	
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo02" );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 " );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )

/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04" );
	
	
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
	printf ( "\n%s"  , "Metodo05" );
	
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )


/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06" );
	
	
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
	printf ( "\n%s"  , "Metodo07 " );
	
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
	printf ( "\n%s"  , "Metodo08 " );
	
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 ");
	
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

/**
 * Metodo10.
 */
void metodo10 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo10 " );
	
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
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
		printf ( "%s\n", "Lista_04 - v.0.1 - 06/05/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski" );
		
		// mostrar opcoes
		printf ( "%s\n", "  Opcoes:"         );
		printf ( "%s\n", "  0 - parar"      );
		printf ( "%s\n", "  1 - metodo 01   2 - metodo 02" );
		printf ( "%s\n", "  3 - metodo 03   4 - metodo 04" );
		printf ( "%s\n", "  5 - metodo 05   6 - metodo 06" );
		printf ( "%s\n", "  7 - metodo 07   8 - metodo 08" );
		printf ( "%s\n", "  9 - metodo 09  10 - metodo 10" );
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


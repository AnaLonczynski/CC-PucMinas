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

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01 - Exercicio 0311" );
	
	int i = 0;
	char palavra[30];
	printf("\nFavor, inserir uma palavra: ");
	scanf ("%s", palavra);
	printf("\nAs letras maiusculas sao:\n");
	
	while(palavra[i] != '\0'){
	
		if (palavra[i] >= 'A' && palavra[i] <= 'Z') 
		{
			printf("%c\n", palavra[i]);
		}
		i = i + 1;
	}

	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

/**
 * Metodo02.
 */
void metodo02 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo02 - Exercicio 0312" );
	
	int i = 0;
	int cont = 0;
	char palavra[30];
	printf("\nFavor, inserir uma palavra: ");
	scanf ("%s", palavra);
	printf("\nAs letras maiusculas sao:\n");
	
	while(palavra[i] != '\0'){
		
		if (palavra[i] >= 'A' && palavra[i] <= 'Z') 
		{
			printf("%c\n", palavra[i]);
			
			cont++;
		}
		i = i + 1;
	}
	printf("\n O numero de letras maiusculas e': %d\n", cont);
	getchar();
	
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
	printf ( "\n%s"  , "Metodo03 - Exercicio 0313" );
	

	char palavra[30];
	int a = 0;
	int cont = 0;
	printf("\nFavor, inserir uma palavra: ");
	scanf ("%s", palavra);
	printf("\nAs letras maiusculas sao:\n");
	a = strlen ( palavra);
	
	for (int x = a; x >= 0; x--)
	{
		if (palavra[x] >= 'A' && palavra[x] <= 'Z') 
		{
			printf("%c\n", palavra[x]);
			cont++;
		}
	}
	printf(" \nO numero de letras maiusculas e': %d\n", cont);
	getchar();
	
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
	printf ( "\n%s"  , "Metodo04 - Exercicio 0314");
	
	char palavra[30];
	int a = 0;
	int cont = 0;
	printf("\nFavor, inserir uma palavra: ");
	scanf ("%s", palavra);		 getchar ( );
	a = strlen ( palavra);
	printf("\nVoce inseriu: %s", palavra);
	
	for (int x = a; x >= 0; x--)
	{
		if (palavra[x] >= 'A' && palavra[x] <= 'z')
		{
			printf("\n%c\n", palavra[x]);
			cont++;
		}
	}
	printf(" \nO numero de letras sao: %d\n", cont);
	getchar();
	
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
	printf ( "\n%s"  , "Metodo05 - Exercicio 0315" );

	
	char palavra [30];
	int a = 0;
	int cont = 0;
	int i = 0;
	
	
	printf("\nFavor, inserir uma palavra:\n");
	scanf("%s", palavra);		 getchar (  );

	
	a = strlen(palavra) - 1;
	
	printf("\npalavra = [%s]\n", palavra);
	
	do{
		for(i = a;	i>=0;	i--){
			printf("\n[%c]", palavra[i]);
			cont ++;
		}
	}while(palavra[i] != '\0');
	
	
	printf("\nO numero de simbolos e': %d", cont);
	
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	printf ( "\n%s"  , "Metodo06 - Exercicio 0316" );

	char palavra [30];
	int a = 0;
	int cont = 0;
	int i = 0;	
	
	printf(" Favor, insira uma palavra: " );
	scanf("%s", palavra); 		getchar ( );
	
	
	a = strlen(palavra) - 1;
	
	
	printf("A palavra inserida foi : [%s]", palavra);
	
	
	do{
		for(i = a;	i>=0;	i--){
			if (!(palavra[i] >= 'A' && palavra[i] <= 'z'))
			{
				printf("\n[%c]", palavra[i]);
				cont ++;
			}
		}
	}while(palavra[i] != '\0');
	
	
	printf("\nO numero de simbolos e': %d", cont);
	
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

/**
 * Metodo07.
 */
void metodo07 ( void )
{
	printf ( "\n%s"  , "Metodo07 - Exercicio 0317" );
	
	int a = 0;
	int b = 0;
	int n = 0;
	int x = 0;
	
	printf("\nInsira um valor minimo: ");
	scanf("%d", &a);	     getchar ( );
	
	printf("\nInsira um valor maximo: ");
	scanf("%d", &b); 	     getchar ( );
	
	printf("\n O intervalo e' [%d : %d]\n", a, b);
	
	printf("\nInsira a quantidade de valores a ser testada: ");
	scanf("%d", &n);       getchar ( );
	
	
	for (int i = 1; i <= n; i++)
	{
		printf("\nInsira um valor: ");
		scanf("%d", &x);  getchar ( );
		
		if ((x >= a && x <= b) && x % 6 == 0)
		{
			printf("\nO valor pertence ao intervalo e e' multiplo de 6\n");
		}
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	printf ( "\n%s"  , "Metodo08 - Exercicio 0318" );

	int a = 0;
	int b = 0;
	int n = 0;
	int x = 0;
	int cont = 0;
	
	printf("\nInsira um valor minimo: ");
	scanf("%d", &a);	     getchar ( );
	
	printf("\nInsira um valor maximo: ");
	scanf("%d", &b); 	     getchar ( );
	
	printf("\n O intervalo e' [%d : %d]\n", a, b);
	
	printf("\nInsira a quantidade de valores a ser testada: ");
	scanf("%d", &n);       getchar ( );
	
	for (int i = 1; i <= n; i++)
	{
		printf("\nInsira um valor: ");
		scanf("%d", &x);  getchar ( );
		
		if ((x >= a && x <= b) && (x % 4 == 0 && x % 5 != 0))
		{
			printf("\n O valor e' multiplo de 4, nao e' multiplos de 5 e pertence ao intervalo\n");
			cont ++;
		}
	}
	
	printf("O numero de valores validos e': %d", cont);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	printf ( "\n%s"  , "Metodo09 - Exercicio 0319" );

	
	double a = 0;
	double b = 0;
	int n = 0;
	double x = 0;
	int cont = 0;
	
	printf("\nInsira um valor minimo: ");
	scanf("%lf", &a);	     getchar ( );
	
	printf("\nInsira um valor maximo: ");
	scanf("%lf", &b); 	     getchar ( );
	
	printf("\n O intervalo e' [%lf : %lf]\n", a, b);
	
	printf("\nInsira a quantidade de valores a ser testada: ");
	scanf("%d", &n);       getchar ( );
	
	for (int i = 1; i <= n; i++)
	{
		printf("\nInsira um valor: ");
		scanf("%lf", &x);  getchar ( );
		
		int partint = x;
		
		if ((x > a && x < b) && (partint % 2 == 0))
		{
			printf("\n pertencente ao do intervalo e a parte inteira e' pares\n");
			cont ++;
		}
	}
	
	printf("O numero de valores validos e': %d", cont);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

/**
 * Metodo10.
 */
void metodo10 ( void )
{
	printf ( "\n%s"  , "Metodo10 - Exercicio 0320" );
	
	double a = 0;
	double b = 0;
	int n = 0;
	double x = 0;
	int cont = 0;
	
	printf("\nInsira um valor minimo: ");
	scanf("%lf", &a);	     getchar ( );
	
	if(0 < a && a <1){
		printf("OK");
	}else{
		
		printf("\nInsira outro valor minimo que esteja entre 0 < a < 1: ");
		scanf("%lf", &a);	     getchar ( );
	}
	
	printf("\nInsira um valor maximo: ");
	scanf("%lf", &b); 	     getchar ( );
	
	if(0 < b && b < 1){
		printf("OK");
	}else{
		printf("\nInsira outro valor maximo que esteja entre 0 < b < 1: ");
		scanf("%lf", &b);	     getchar ( );
	}
	
	
	printf("\n O intervalo e' [%lf : %lf]\n", a, b);
	
	printf("\nInsira a quantidade de valores a ser testada: ");
	scanf("%d", &n);       getchar ( );
	
	
	for (int i = 1; i <= n; i++)
	{
		printf("\nInsira um valor: ");
		scanf("%lf", &x);  getchar ( );
		
		int partint = x;
		float y = x - partint; 
		
		if (y <= a || y >= b) 
		{
			printf("\n Sua parte fracionaria pertencente fora do intervalo\n");
			cont ++;
		}
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo10 ( )


int main ( void )
{
	// definir dados/resultados
	int opcao = 0;
	
	// repetir ate' desejar parar
	do
	{
		// identificar
		printf ( "\n" );             // para saltar linha
		printf ( "%s\n", "\nLista_03 - v.0.1 - 19/03/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski\n" );
		
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


/*
----------------------------- documentacao complementar


----------------------------- notas / observacoes / comentarios


----------------------------- previsao de testes


----------------------------- historico

Versao	Data		      Modificacao
0.1	__/__		      esboco

---------------------------- testes

Versao	Teste
0.1	01. ( OK )	      identificacao de programa

*/

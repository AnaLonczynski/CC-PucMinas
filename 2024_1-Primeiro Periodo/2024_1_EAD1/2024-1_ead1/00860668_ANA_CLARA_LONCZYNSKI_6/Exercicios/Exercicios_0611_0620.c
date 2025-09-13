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



void recursivoM1 ( int x)
{
	if ( x > 0 )
	{
		recursivoM1 ( x - 1 ); // motor da recursividade
		
		printf ( "%s%d\n", "Valor = ", x*6 );
		// passar ao proximo
	}
}

/**
 * Metodo01.
 */
void metodo01 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo01 - Exemplo 0611\n" );
	
	int x = 0;
	
	printf("\n Inserir valor inteiro: ");
	scanf("%d", &x);
	getchar();
	
	recursivoM1 ( x );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )



void recursivoM2 ( int x)
{
	if ( x > 0 )
	{
		printf ( "%s%d\n", "Valor = ", 6 * x);
		
		recursivoM2 ( x - 1 ); // motor da recursividade
	}
}
/**
 * Metodo02.
 */
void metodo02 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo02 - Exemplo 0612\n" );
	
	int x = 0;
	
	printf("\n Inserir valor inteiro: ");
	scanf("%d", &x);
	getchar();
	
	recursivoM2 ( x );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )



void recursivoM3 ( int x)
{
	if ( x > 0 )
	{
		recursivoM3 ( x - 1 ); // motor da recursividade
		
		printf ( "%s%d\n", "Valor = 1/", x*6);
	}
}
/**
 * Metodo03.
 */
void metodo03 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 - Exemplo 0613\n" );
	
	int x = 0;
	
	printf("\n Inserir valor inteiro: ");
	scanf("%d", &x);
	getchar();
	
	x--;
	
	printf("Valor = 1/1\n");
	recursivoM3( x );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )



void recursivoM4 ( int x)
{
	if ( x > 0 )
	{
		printf ( "%s%d\n", "Valor = 1/", x*6);
		
		recursivoM4 ( x - 1 ); // motor da recursividade
	}
}
/**
 * Metodo04.
 */
void metodo04 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo04 - Exemplo 0614\n" );
	
	int x = 0;
	
	printf(" Inserir valor inteiro: ");
	scanf("%d", &x);
	getchar();
	x--;
	
	recursivoM4( x );
	printf("Valor = 1/1");
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )



int recursivoM5a ( int y, int x, int p, int q, int soma )
{
	if ( y <= x )
	{
		soma = soma + q + p;
		
		printf("y = %d  x = %d p = %d  q = %d  Soma = %d\n", y, x, p, q + p, soma);
		soma = recursivoM5a ( y + 1 , x , p + 2, q + p ,soma ); // motor da recursividade
	}
	return soma;
}

int recursivoM5 ( int y, int x, int q)
{
	int p = 2 * (y-1);
	int soma = 0;
	if ( y <= x )
	{
		printf("y = %d  x = %d q = %d  \n", y, x, q + p);
		soma = q + p + recursivoM5 ( y + 1 , x , q + p ); 
	}
	return soma;
}

/**
 * Metodo05.
 */
void metodo05 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo05 - Exemplo0615\n" );
	
	int x = 0;
	int y = 0;
	
	printf("\n Inserir valor inteiro: ");
	scanf("%d", &x);
	getchar();
	
	y = recursivoM5 ( 1, x , 6);
	printf("y = %d\n", y) ;
 
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )



double recursivoM6 ( double x, int y, double z , double soma)
{
	if ( y <= x )
	{
		double	p = y * 6;
		
		z = 1 / p;
		
		printf("1 / %4.2lf = %lf\n", p, z);	
		
		soma = z + recursivoM6 ( x , y + 1  , z , soma);
	}
	return soma;
}

/**
 * Metodo06.
 */
void metodo06 (  )
{
	printf ( "\n%s"  , "Metodo06 - Exemplo 0616\n" );
	
	double x = 0;
	double soma = 0;
	
	printf("\n Inserir valor inteiro: ");
	scanf("%lf", &x);
	getchar();
	
	soma = recursivoM6 ( x, 1, 0, soma);
	printf("\nSoma = %lf\n", soma);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )



void mostrar (char s[], int n)
{
	if( n >= 0 )
	{
		printf("\n%c", s[n]);
		n--;
		mostrar ( s, n);
	}
}

/**
 * Metodo07.
 */
void metodo07 (  )
{
	printf ( "\n%s"  , "Metodo07 - Exemplo 0617\n" );
	
	char s [80];
	
	printf("\n Insira uma palavra = ");
	scanf("%s", s);        getchar ( );
	printf("\ns = [%s]", s);
	
	mostrar ( s, strlen(s)-1);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )



void mostrarM8 (char s[], int n)
{
	if( n >= 0 )
	{
		if((!(s[n] >= 'A' && s[n] <= 'z')) && (s[n] % 2 == 0)){
			printf("\n%c\n", s[n]);
		}
		n--;
		mostrarM8 ( s, n);
	}
}

/**
 * Metodo08.
 */
void metodo08 (  )
{
	printf ( "\n%s"  , "Metodo08 - Exemplo0618\n" );
	
	char s [80];
	
	printf("\n Insira uma palavra = ");
	scanf("%s", s);        getchar ( );
	printf    ("\ns = [%s]", s);
	
	mostrarM8 ( s, strlen(s)-1);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )



int mostrarM9 (char s[], int n, int cont)
{
	if( n >= 0 )
	{
		if((s[n] >= 'A' && s[n] <= 'L'))
		{
			printf("\n%c\n", s[n]);
			cont= cont+1;
		}
		n--;
		cont = mostrarM9 ( s, n, cont);
	}
	return cont;
}

/**
 * Metodo09.
 */
void metodo09 (  )
{
	printf ( "\n%s"  , "Metodo09 - Exemplo0619\n" );
	
	char s [80];
	int cont = 0;
	
	printf("\n Insira uma palavra = ");
	scanf("%s", s);        getchar ( );
	printf  	     ("\ns = [%s]", s);
	
	cont = mostrarM9 ( s, strlen(s)-1, cont);
	printf("\nO numero de maiusculas menores que 'L' e: %d", cont);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )


int fibonacci(int n) 
{
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fibonacci_par(int n)
{
	int i = 1;
	while (1) {
		int fib = fibonacci(i);
		if (fib % 2 == 0) {
			if (--n == 0) {
				return fib;
			}
		}
		i++;
	}
}

/**
 * Metodo10.
 */
void metodo10 (  )
{
	printf ( "\n%s"  , "Metodo10 - Exemplo 0620\n" );
	
	int x;
	printf("Insira um valor ");
	scanf("%d", &x);
	getchar();
	
	for (int i = 1; i <= x; i++)
	{
		printf("[%d]: %d\n", i, fibonacci_par(i));
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo10 ( )

int main (  )
{
	int opcao = 0;
	
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
	
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	
} 

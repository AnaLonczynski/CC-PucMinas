//author: Ana Clara Lonczynski Matrícula: 0860668

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void method_1a (int x)
{
	int cont = 1;
	int y = 0;
	int z = 6;
	
	int mult = 1;
	
	while (cont <= x)
	{
		y = z * mult;
		
		printf ( "[%d]: %d\n", cont, y );
		
		mult = mult + 1;
		
		cont = cont + 1;
	}
}

/**
 * Metodo01.
 */
void metodo01 (  )
{
	int x = 0;
	
	printf  ( "\n%s"  , "Metodo01 - Exemplo 0511" );
	
	printf  ("%s", " Favor inserir um valor inteiro:"   );
	scanf   ( "%d", &x );
	getchar (  );
	
	method_1a ( x );
	
	printf  ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar ( );
} 

void method_02a ( int x )
{
	int cont = 1;
	int y = 0;
	int z = 15;
	
	int mult = 1;
	
	while (cont <= x)
	{
		y = z * mult;
		
		printf ( "[%d]: %d\n", cont, y );
		
		mult = mult + 1;
		
		cont = cont + 1;
	}
}

/**
 * Metodo02.
 */
void metodo02 (  )
{
	printf ( "\n%s"  , "Metodo02 - Exemplo 0512" );

	int x = 0;
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	method_02a ( x );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
}

void method_03a ( int x)
{
	int y = 0;
	int z = x;
	
	while (z > 0)
	{
		y = pow(4 , z);
		
		printf ( "%d: %d\n", x, y );
		
		z = z - 1;
		x = x - 1;
	}
}
 
/**
 * Metodo03.
 */
void metodo03 (  )
{
	printf ( "\n%s"  , "Metodo03 - Exemplo 0513" );
	int x = 0;
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	method_03a ( x );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} 

void method_04a ( int x)
{
	int cont = 1;
	double y = 0.0;
	double z = 1.0;
	double cima = 1.0;
	
	while (cont <= x)
	{
		y = z * 7.0;
		
		printf ( "[%d]: %5.0lf/%3.2lf \n", cont, cima, y );

		cont = cont + 1;
		z = z + 1;
	}
}

/**
 * Metodo04.
 */
void metodo04 ( )
{
	printf ( "\n%s"  , "Metodo04 - Exemplo 0514" );
	
	int x = 0; 
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	method_04a ( x );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} 

void method_05a (int x)
{
	int cont = 1;
		int cima = 1;
	int b = 0;
	int z = 1;
	double y = 0.0;

	printf ("%s", " \nFavor inserir um valor inteiro:");
	scanf  ( "%d", &b );
	getchar ( );
	
	while (cont <= x)
	{
		y = pow(b,z);
		
		printf ( "[%d]: %d/%lf \n", cont, cima, y );
		
		cont = cont + 1;
		z = z + 1;
	}
}

/**
 * Metodo05.
 */
void metodo05 (  )
{
	printf ( "\n%s"  , "Metodo05 - Exemplo 0515" );
	
	int x = 0; 
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	method_05a ( x );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} 

int method_06a (int x)
{
	int cont = 0;
	int soma = 0;
	int a = 1;
	int b = 0;
	
	while (cont <= x)
	{
		if(a % 5 == 0)
		{
			a = a + 1;
		}
		
		b = a * 3;
		a = a + 1;

		cont = cont + 1;
		
		printf ( "[%d]: %d\n", cont, b );
		
		soma = soma + b;
	}
	return soma;
}

/**
 * Metodo06.
 */
void metodo06 (  )
{
	printf ( "\n%s"  , "Metodo06 - Exemplo 0516" );
	
	int x = 0; 
	int soma = 0;
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	soma = method_06a ( x );

	printf ( "soma = %d\n", soma );

	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} 

double method_07a (int x)
{
	int cont = 0;
	int cima = 1;
	int a = 1;
	double b = 0.0;
	double z = 0.0;
	double soma = 0;

	while (cont <= x)
	{
		if(a % 5 == 0)
		{
			a = a + 1;
		}
		
		b = a * 6;
		a = a + 1;
		z = cima / b;
		
		cont = cont + 1;
		
		printf ( "[%d]: %d/%lf = %lf \n", cont, cima , b, z );
		
		soma = soma + z;
	}
	return soma;
}

/**
 * Metodo07.
 */
void metodo07 (  )
{
	printf ( "\n%s"  , "Metodo07 - Eemplo 0517" );
	
	int x = 0; 
	double soma = 0;
	
	printf ("%s", " Favor inserir um valor inteiro:");
	scanf  ( "%d", &x );
	getchar ( );
	
	soma = method_07a ( x );
	
	printf ( "soma = %lf\n", soma );

	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} 

int method_08a (int x)
{
	int cont = 1;
	int a = 6;
	int b = 0;
	int c = 0;
	int d = 0;
	int soma = 0;
	
	while (cont <= x)
	{
		b = a + c;
		
		printf ( "[%d]: %d \n", cont , b );
		
		d = d + 1;
		c = c + d;
		
		cont = cont + 1;
		soma = soma + b;
	}
	return soma;
}

/**
 * Metodo08.
 */
void metodo08 (  )
{
	printf ( "\n%s"  , "Metodo08 - Exemplo 0518" );
	
	int x = 0; 
	int soma = 0;
	
	printf  ( "%s", " Favor inserir um valor inteiro:");
	scanf   ( "%d", &x );
	getchar (  );
	
	soma = method_08a ( x );
	
	printf ( "soma = %d\n", soma );
	
	printf  ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar (  );
	
}

int method_09a (int x)
{	
	int cont = 1;
	int a = 6;
	int b = 0;
	int c = 0;
	int soma = 0;
	
	while (cont <= x)
	{
		b = a + c;
		b = pow(b, 2);
		
		printf ( "[%d]: %d \n", cont , b );
		
		c = c + 1;
		
		cont = cont + 1;
		soma = soma + b;
	}
	return soma; 	
}
/**
 * Metodo09.
 */
void metodo09 (  )
{
	printf ( "\n%s"  , "Metodo09 - Exemplo 0519" );
	
	int x = 0; 
	int soma = 0;
	
	printf  ( "%s", " Favor inserir um valor inteiro:");
	scanf   ( "%d", &x );
	getchar (  );
	
	soma = method_09a ( x );
	
	printf ( "soma = %d\n", soma );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

double method_10a (int x)
{
	int cont = 1;
	double a = 6.0;
	double b = 0.0;
	double c = 0.0;
	double d = 0.0;
	double e = 0.0;
	int cima = 1;
	double soma = 0;
	
	while (cont <= x)
	{
		b = a + c;
		
		e = cima / b;
		
		printf ( "[%d]: %d/%4.2lf = %lf \n", cont , cima, b, e );
		
		d = d + 1;
		c = c + d;
		
		cont = cont + 1;
		soma = soma + e;
	}
	return soma;
}

/**
 * Metodo10.
 */
void metodo10 (  )
{
	printf ( "\n%s"  , "Metodo10 - Exemplo 0520" );
	
	int x = 0; 
	double soma = 0;
	
	printf  ( "%s", " Favor inserir um valor inteiro:");
	scanf   ( "%d", &x );
	getchar (  );
	
	soma = method_10a ( x );
	
	printf ( "soma = %lf\n", soma );
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} 

void method_E1a ( int x)
{
	int contador = 2;
	int fatorial = 1;
	
	while(contador <= x)
	{
		fatorial = fatorial * contador;
		contador = contador + 1;
	}
	printf("%d!: %d\n", x, fatorial);
	

}

void metodoE1 ( )
{
	printf ( "\n%s"  , "MetodoE1 - Exemplo 05E1" );
	
	int x = 0; 
	
	printf  ( "%s", " Favor inserir um valor inteiro:");
	scanf   ( "%d", &x );
	getchar (  );
	
	if (x > 0)
	{
		method_E1a ( x );
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
}

int fatorial(int n) {
	
	int acum = 1;
	
	for(int i=1; i <= n; i++) {
		acum = acum * i;
	}
	
	return acum;
}


int method_E2 ( int n)
{
	int acum = 1;
	float f_n = 0;
	int denominador = 5;
	int fatorial_denominador = 0;
	
	for(int i=1; i <= n; i++) {
		if (i > 1) {
			denominador = denominador + 2;
		}
			
		fatorial_denominador = fatorial(denominador);

		f_n =  1 + (pow(2, i) / fatorial_denominador);
		acum = acum * f_n;
		
	}
	
	printf( " f(n) = 1 + 2^%d / %d = %f\n", n , n, f_n);
	return acum;
}

void metodoE2 ( )
{
	printf ( "\n%s"  , "MetodoE2 - Exemplo 05E2" );
	
	int n = 0; 
	
	printf  ( "%s", " Favor inserir um valor inteiro:");
	scanf   ( "%d", &n );
	getchar (  );
	
	if (n > 0)
	{
		method_E2 ( n );
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
}

int main (  )
{
	int opcao = 0;
	
	do
	{
		// identificar
		printf ( "\n" );             // para saltar linha
		printf ( "%s\n", "Lista_05 - v.0.0 - 03/04/2024"       );
		printf ( "%s\n", "Matricula: 860668 Nome: Ana Clara Lonczynski" );
		
		// mostrar opcoes
		printf ( "%s\n", "Opcoes:"         );
		printf ( "%s\n", " 0  - parar"      );
		printf ( "%s\n", " 1  - metodo 01   2 - metodo 02" );
		printf ( "%s\n", " 3  - metodo 03   4 - metodo 04" );
		printf ( "%s\n", " 5  - metodo 05   6 - metodo 06" );
		printf ( "%s\n", " 7  - metodo 07   8 - metodo 08" );
		printf ( "%s\n", " 9  - metodo 09  10 - metodo 10" );
		printf ( "%s\n", " 11 - metodo E1  12 - metodo E2" );
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
			case 11: metodoE1 ( ); break;
			case 12: metodoE2 ( ); break;
		default:
			printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
			break;
		} // fim escolher
	}
	while ( opcao != 0 );
	
	// encerrar execucao
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	
}

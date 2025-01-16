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

void valores ( double z, double x, double y)
{
	int cont = 1;
	double valor = 0;
	
	while(cont <= z){
		
		printf("\n Favor insira um valor: ");
		scanf("%lf", &valor);
		
		if(valor <= x && valor >= y) {
			printf("%lf valor esta dentro do intervalo\n", valor);
		}
		else{
			printf("%lf valor esta fora do intervalo\n", valor);
		}
		
		cont = cont + 1;
	}
}

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01 - Exercicio 0411" );
	
	double x = 0;
	double y = 0;
	double z = 0;
	
	printf("\n Favor, inserir o valor para o limite inferior para o intervalo fechado : ");
	scanf("%lf", &x);
	
	printf("\n Favor, inserir o valor para o limite superior para o intervalo fechado : ");
	scanf("%lf", &y);

	printf(" O intervalo e' : [%lf : %lf]", x, y);
	
	printf("\n Favor, inserir um numero de valores: ");
	scanf("%lf", &z);
	
	valores(x, y, z);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

int contMaiuscula ( char palavra []){
	int cont = 0;
	int a = 0;
	a = strlen(palavra);
	
	for(int i=0 ; i < a ; i++){
		if('L' <= palavra[i] && palavra[i] <= 'Z' ){
			cont++;
			printf("\n[%c]", palavra[i]);
		}
	}
	return cont;
}

/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo02 - Exercicio 0412" );
	
	char palavra [80];
	int cont = 0;
	
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	cont = contMaiuscula(palavra);
	
	printf("\n\nO numero de mausculas maiores que L e': %d", cont);
	
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
	printf ( "\n%s"  , "Metodo03 -  Exercicios 0413" );
	
	char palavra [80];
	int cont = 0; 
	
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	
	cont = contMaiuscula(palavra);
	
	printf("\n\nO numero de mausculas maiores que L e': %d", cont);
	
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
	printf ( "\n%s"  , "Metodo04 - Exercicios 0414" );
	
	char palavra [80];
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	contMaiuscula(palavra);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

int contlL ( char palavra []){
	int cont = 0;
	int a = 0;
	a = strlen(palavra);
	
	for(int i=0 ; i < a ; i++){
		if('L' <= palavra[i] && palavra[i] <= 'l' ){
			cont++;
			printf("\n°[%c]", palavra[i]);
		}
	}
	
	return cont;
}

/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05 - Exercicio 0415" );
	
	char palavra [80];
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	contlL(palavra);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )


int contkL ( char palavra []){
	int cont = 0;
	int a = 0;
	a = strlen(palavra);
	
	for(int i=0 ; i < a ; i++){
		if('L' <= palavra[i] && palavra[i] <= 'k' ){
			cont++;
			printf("\n°[%c]", palavra[i]);
		}
	}
	
	return cont;
}

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06 - Exercicio 0416" );
	
	char palavra [80];
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	contkL(palavra);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

int contarpares (char palavra[]){
	int cont = 0;
	char simbolo = 0;
	int digitos = 0;
	
	for(int i=0;palavra[i] != '\0';i++){
		
		simbolo = palavra[i];
		
		if(( simbolo >= '0' ) && ( simbolo <='9' )){
			
			digitos = (int)simbolo;
			
			if(digitos % 2 == 0){
				
				printf("\n°[%c] = PAR", palavra[i]);
				cont++;
			}
		}
	}
	return cont;
}

/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo07 - Exercicio 0417" );
	
	char palavra [80];
	int cont = 0;
	
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	cont = contarpares(palavra);
	
	printf("\n\nO numero de pares e': %d", cont);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

void naoalfanum (char palavra[]){
	
	char simbolo;
	
	for(int i=0;palavra[i] != '\0';i++){
		
		simbolo = palavra[i];
		
		if(((simbolo <= '0') && (simbolo <= '9')) && ((simbolo <= 'A') && (simbolo <= 'z'))){
			printf("\n°[%c]", simbolo);
		}
	}
}

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo08 - Exercicio 0418" );
	
	char palavra [80];
	
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	naoalfanum(palavra);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

int alfanum (char palavra[]){
	
	char simbolo;
	int cont = 0;
	
	for(int i=0;palavra[i] != '\0';i++){
		
		simbolo = palavra[i];
		
		if( ((simbolo >= 'A') && (simbolo <= 'z')) || ((simbolo >= '0') && (simbolo <= '9'))){
			printf("\n°[%c]", simbolo);
			cont ++;
		}
	}
	return cont;
}

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 - Exercicio 0419" );
	
	char palavra [80];
	
	printf("\nPALAVRA = ");
	scanf("%s", palavra); getchar( );
	
	alfanum(palavra);
	
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
	printf ( "\n%s"  , "Metodo10 - Exercicio 0420" );
	
	int n = 0;
	int cont = 0;
	int soma = 0;
	char palavra [80];
	
	printf("\nInsira a quantidade de palavras = ");
	scanf("%d", &n); getchar( );
	
	for(int i=0;i<n;i++){
		
		printf("\nznPALAVRA = ");
		scanf("%s", palavra); getchar( );
		
		cont = alfanum(palavra);
		
		printf("\nCont = %d", cont);
		soma = soma + cont;
	}
	
	printf("\nO numero de simboloso alfanumericos e': %d", soma);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo10 ( )

void metodoE1 ( void )
{
	// identificar
	printf ( "\n%s"  , "MetodoE1 - Exercicio 04E1" );
	
	int n = 0;
	int cont = 0;
	int soma = 0;
	char palavra [80];
	
	printf("\nInsira a quantidade de palavras = ");
	scanf("%d", &n); getchar( );
	
	for(int i=0;i<n;i++){
		
		printf("\nznPALAVRA = ");
		scanf("%s", palavra); getchar( );
		
		fgets(palavra, sizeof(palavra), stdin);
		
		if (palavra[strlen(palavra) - 1] == '\n') 
		{	palavra[strlen(palavra) - 1] = '\0';}
		
		cont = alfanum(palavra);
		
		printf("\nCont = %d", cont);
		soma = soma + cont;
	}
	
	printf("\nO numero de simboloso alfanumericos e': %d", soma);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodoE1 ( )

int contchar(char palavra[]){
	int cont = 0;
	
	for(int i=0;palavra[i] != '\0';i++){
		cont++;
	}
	return cont;
}

void metodoE2 ( void )
{
	// identificar
	printf ( "\n%s"  , "MetodoE2 - Exercicio 04E2" );
	
	char Palavra1[80];
	int  palavra1 = 0;
	char Palavra2[80];
	int  palavra2 = 0;

	printf("\nPRIMEIRA PALAVRA = ");
	scanf("%s", Palavra1); getchar( );
	
	palavra1 = contchar(Palavra1);
	
	printf("\nSEGUNDA PALAVRA = ");
	scanf("%s", Palavra2); getchar( );
	
	palavra2 = contchar(Palavra2);
	
	if(palavra1 > palavra2){
		printf("\nA primeira palavra e' maior");
	}else{
		printf("\nA segunda palvra e' maior");
	}
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodoE2 ( )


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
	
} // end main ( )


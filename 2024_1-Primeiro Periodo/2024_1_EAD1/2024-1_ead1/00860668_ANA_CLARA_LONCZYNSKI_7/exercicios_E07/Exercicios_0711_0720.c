/**
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Autor:   Matricula: 0860668  Nome: Ana Clara Lonczynski
 * Versao:  1.0                Data: 15/05/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "io.h"

void writeint (char filename [], int x){
	
	FILE* arquivo = fopen(filename, "wt");
	int m4 = 0;
	
	if(arquivo){
		
		for(int i=1;i<=x;i++){
			
			m4 = i * 4;
			
			if(m4 % 2 == 0){
				fprintf(arquivo, "%d", m4);
				fprintf(arquivo, "\n");
			}
		}
		fclose(arquivo);
	}
}

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01" );
	
	int vl = 0;
	char filename [] = "E1.TXT";
	
	
	printf("%s", "\nInserir valor inteiro:");
	scanf("%d", &vl); getchar( );
	
	
	writeint(filename, vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

void writeintE2 (char filename [], int x){
	
	int y = 0;
	FILE* arquivo = fopen(filename, "wt");
	
	if(arquivo){
		for(int i=x;i>=0;i--){
			y = 5 * i;
			
			if(y % 2 != 0){
				fprintf(arquivo, "%d", y);
				fprintf(arquivo, "\n");
			}
		}
		fclose(arquivo);
	}
}
/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo02" );
	
	int vl = 0;
	char filename [] = "E2.TXT";
	
	printf("%s", "\nInserir valor inteiro:");
	scanf("%d", &vl); getchar( );
	
	writeintE2(filename, vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

void writeintE3 ( char filename [], int x){
	int y = 0;
	FILE* arquivo = fopen(filename, "wt");
	
	if(arquivo){
		
		for(int i=0;i<=x;i++){
			y = pow(5, i);
			fprintf(arquivo, "%d", y);
			fprintf(arquivo, "\n");
		}
		fclose(arquivo);
	}
}
/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 " );
	
	int vl = 0;
	char filename [] = "E3.TXT";
	
	printf("%s", "\nInserir valor inteiro:");
	scanf("%d", &vl); getchar( );
	
	writeintE3(filename, vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )

void writeintE4(char filename [], int x){
	
	double y = 0.0;
	FILE* arquivo = fopen ( filename, "wt"); 
	
	if(arquivo){
		for(int i=0;i<=x;i++){
			y = 1/pow(5, i);
			
			fprintf(arquivo, "%lf\n", y);
		}
		fclose (arquivo);
	}
}
/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04" );
	
	int vl = 0;
	char filename [] = "E4.TXT";
	
	printf("%s", "\nInserir valor inteiro:");
	scanf("%d", &vl); getchar( );
	
	writeintE4(filename, vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

void writeintE5 ( char filename [], int x, double vr){

	FILE* arquivo = fopen(filename, "wt");
	int up = 3;
	double z = 0.0;
	
	if(arquivo){
		
		for(int i=0;i<=x;i++){
			z = 1 /pow(vr, up);
			fprintf(arquivo, "%lf\n", z);
			up = up + 2;
		}
		fclose(arquivo);
	}
}
/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05" );
	
	int vl = 0;
	double vrl = 0;
	char filename [] = "E5.TXT";
	
	printf("%s", "\nInserir valor inteiro:");
	scanf("%d", &vl)  ; getchar( );
	
	printf("%s", "\nInserir valor real:");
	scanf("%lf", &vrl); getchar( );
	
	writeintE5 (filename, vl, vrl);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

void somavaloresE6 ( char filename [], char filesoma[], int x){
	
	FILE* arquivo = fopen(filename, "rt");
	FILE* resultado = fopen(filesoma, "wt");
	double y = 0.0, soma = 0.0, z = 0.0;
	int contador = 0;
	
	fscanf(arquivo, "%lf", &z);
	soma = soma + z;
	
	while (contador < x && !feof(arquivo))
	{
		fscanf(arquivo, "%lf", &y);
		soma = soma + y;
		contador++;
	}
	fclose(arquivo);
	
	
	fprintf(resultado, "%d\n", x);
	fprintf(resultado, "%lf\n", soma);
	
	fclose(resultado);
}
/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06" );
	
	int vl = 0;
	
	printf("%s", "\nInserir o numero de valores a serem inteiro:");
	scanf("%d", &vl)  ; getchar( );
	
	somavaloresE6 ("E5.TXT", "RESULTADO06.TXT", vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

void somainvE7 (char filename [], char filesoma [], int x){
	
	FILE* arquivo = fopen(filename, "rt");
	FILE* resultado = fopen (filesoma, "wt");
	double soma = 0.0, y = 0;
	int cont =0;
	
	fscanf(arquivo, "%lf", &y);
	
	while( cont < x && !feof(arquivo)){
		fscanf(arquivo, "%lf", &y);
		soma = soma + y;
		cont++;
	}fclose(arquivo);
	
	fprintf(resultado, "%d\n", x);
	fprintf(resultado, "%lf\n", soma);
	fclose(resultado);
}
/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo07 " );
	
	int vl = 0;
	
	printf("%s", "\nInserir o numero de valores a serem inteiro:");
	scanf("%d", &vl)  ; getchar( );
	
	somainvE7 ("E4.TXT", "RESULTADO07.TXT", vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

void gravarfibonacci (char filename [], int n){
	
	FILE* arquivo = fopen(filename, "wt");
	int cont = 0, n1 = 0, n2 = 1, n3=0;
	
	fprintf(arquivo,"%d\n", n1);
	fprintf(arquivo,"%d\n", n2);
	
	while(cont < n && !feof(arquivo)){
		n3=n1+n2;    
		fprintf(arquivo, "%d\n",n3);    
		n1=n2;    
		n2=n3; 
		cont++;
	}fclose(arquivo);
	
}

void writeE8 (char fileIn[], char fileOut [], int n){
	
	FILE* arquivo   = fopen ( fileIn, "rt");
	FILE* resultado = fopen (fileOut, "at");
	int x = 0, cont = 0;
	
	fprintf(resultado, "\n Quantidade:[%d]\n", n);
	fscanf(arquivo, "%d", &x);
	
	while(cont < n && !feof(resultado)){
		
		fprintf ( resultado, "%d\n", x );
		printf ( "%d\n",  x );
		fscanf ( arquivo, "%d", &x );
		cont++;
		
	}fclose (arquivo);
	fclose(resultado);
}
/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo08 " );
	
	int vl = 0;
	
	printf("%s", "\nInserir valor:");
	scanf("%d", &vl)  ; getchar( );

	gravarfibonacci("fibonacci.txt", vl);
	writeE8("fibonacci.txt", "RESULTADO08.TXT", vl);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

int gravarumasting (char filename[], char palavra[]){
	
	FILE* arquivo = fopen(filename, "wt");
	int contlinhas = 0;
	int contmaiusc = 0;
	
	if(!feof(arquivo)){
		
		printf( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
		
		while ( strcmp ("PARAR", palavra ) != 0 ){
			
			scanf("%s", palavra);     getchar();
			
			if(strcmp ("PARAR", palavra ) != 0){
				fprintf ( arquivo, "%s\n", palavra );
				
				for(int i=0;i<strlen(palavra);i++){
					if('A'<= palavra[i] && palavra[i] <= 'Z'){
						contmaiusc++;
					}
				}
				contlinhas ++;
				fprintf(arquivo, "Maiusculas=%d\n", contmaiusc);
			}
		}
	}
	contlinhas = contlinhas*2;
	fclose(arquivo);
	return contlinhas;
}

void gravarsctrings (char fileIn[], char fileOut[], int linhas){
	
	FILE* arquivo = fopen(fileIn, "rt");
	FILE* resultado = fopen(fileOut, "at");
	char x [30];
	int cont = 0;
	
	while(!feof(arquivo) && cont < linhas){
		
		fscanf(arquivo, "%s", x);
		fprintf(resultado, " [%s]\n", x);
		cont ++;
	}
	
	fclose(arquivo);
	fclose(resultado);
}
/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 ");
	char palavra [30];
	int linhas = 0;
	
	linhas = gravarumasting ("DadosStringE9.txt", palavra);
	gravarsctrings ("DadosStringE9.txt","RESULTADO09.TXT", linhas);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

int contardigitos(char filename[]){
	
	FILE* arquivo = fopen(filename, "wt");
	char palavra [30];
	int contdigitos = 0;
	int linhas = 0;
	
	if(!feof(arquivo)){
		printf( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
		
		while ( strcmp ("PARAR", palavra ) != 0 ){
			
			scanf("%s", palavra);     getchar();
			if(strcmp ("PARAR", palavra ) != 0){
				fprintf ( arquivo, "%s\n", palavra );
				
				for(int i=0;i<strlen(palavra);i++){
					if('5'<= palavra[i]){
						contdigitos++;
					}
				}
				printf("Digitos = %d\n", contdigitos);
				linhas++;
				fprintf(arquivo, "Digitos=%d\n", contdigitos);
				
			}
		}
	}fclose(arquivo);
	linhas = linhas * 2;
	
	return linhas;
}
void gravardigitos (char fileIn[], char fileOut[], int linhas){
	
	FILE* arquivo = fopen(fileIn, "rt");
	FILE* resultado = fopen(fileOut, "at");
	char x [30];
	int cont = 0;
	
	while(!feof(arquivo) && cont < linhas){
		
		fscanf(arquivo, "%s", x);
		fprintf(resultado, " [%s]\n", x);
		cont ++;
	}
	
	fclose(arquivo);
	fclose(resultado);
}
/**
 * Metodo10.
 */
void metodo10 ( void )
{
	// identificar
	
	printf ( "\n%s"  , "Metodo10 " );
	int linhas = 0;
	
	linhas = contardigitos("E10.txt");
	gravardigitos ("E10.txt", "RESULTADO10.TXT", linhas);
	
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
		printf ( "%s\n", "Lista_07 - v.0.1 - 15/05/2024"       );
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


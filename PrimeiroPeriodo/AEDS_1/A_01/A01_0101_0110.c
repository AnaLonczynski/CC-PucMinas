/**
 * 
 *
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Autor:   Matricula: 0860668  Nome: Ana Clara Lonczynski
 * Versao:  1.0                Data: 01/05/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int f_01 (char p [])
{
	int  y = 0;
	bool r = false, s = false, t = false;
	bool u = false, v = false, w = false;
	
	for(int x=0;x<strlen(p);x++){
		r = ('a' <= p[x] && p[x]<='z');
		s = ('A' <= p[x] && p[x]<='Z');
		t = ('0' <  p[x] && p[x]<='9');
		u = (r || s) && !w;
		v = !u && t;
		w = !v;
		if(u){ y ++;}else{
			if(v){y --;}
		}
	}
	return (y);
}

/**
 * Questão 01.
 */
void metodo01 ( void ) {
	printf ( "\n%s", "Questao 01 - Fechada" );
	/*Qual saída esperada da função abaixo para printf("%d", f_01 ("5aP4+0_8r4nK0"));*/
	
	printf ("\n%d", f_01( "5aP4+0_8r4nK0" ));
	
	/*RESPOSTA: a) (-1) */
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo01 ( )


int f_02(int a, int b){
	
	if(a%2 == 0 &&  b%2 == 0){
		return (f_02(a/2, b/2));
	}	else{
		if(a%2!=0 && b%2!=0){
			return(f_02(b%a, b/2));
		}else{
			if(a%2==0 && b%2!=0){
				return (f_02 (a/2, a%b));
			}
		}
	}
	return ((a-1) % (b-1)/2);
}

/**
 * Questão 02.
 */
void metodo02 (  ) {
	printf ( "\n%s", "Questao 02 - Fechada" );
	/*Qual saída esperada da função abaixo para printf ("\nf_02 (30,72) = %d\n", f_02(30,72));*/
	
	printf ("\nf_02 (30,72) = %d\n", f_02(30,72));
	
	/*RESPOSTA:  OUTRA) 7 */
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

/**
 * Questão 03.
 */
void metodo03 ( void ) {
	printf ( "\n%s", "Questao 03 - Fechada" );
	/*Que expressões completam a segunda repetição para mostrar o mesmo resultado que a primeira?*/
	
	int a = 3;
	int b = 0;
	b = 5 * 3;
	
	for(int x=0;x<=5;x++){
		printf("\nX = %d", 2*x+1);
	}
	for(int x=a;x<=b;x=x+3){
		printf("\nx = %d,", (x-x)/3); //c
	}
	
	/*RESPOSTA: c) a = 3; b = 5*3; c = (2*x+3)/3 */
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )

/**
 * Questão 04.
 */
void metodo04 ( void ) {
	printf ( "\n%s", "Questão 04 - Fechada");
	
	/*Qual saída esperada do procedimento para n=5*/
	
	int x = 1, y = 1, v = 0, w = 0, m = 2, n = 0;
	
	printf("\nn="); scanf("%d", &n); getchar ( );
	
	printf("\n%d %d", x, y);
	
	while(m < n){
		v = x+y ; 
		m ++	;
		printf("\n%d", v);
		if(m < n-1){
			w = x + y + v  ;
			m ++;
			printf("\n%d", w);
		}
		x = v;
		y = w;
	}
	
	/*RESPOSTA: d) 1 1 2 4 6 */
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

int f_05 (char *s){
	
	int x = 0, y = strlen(s)-1;
	
	while(x <= y && s[x] == s[y]){
		x++;
		y--;
	}
	return (x-y + s[x]-s[y]);
}
/**
 * Questão 05.
 */
void metodo05 ( void ) {
	printf ( "\n%s", "Questao 05 - Fechada" );
	
	printf ("\n%d", f_05("14641"));
	
	/*RESPOSTA: d) f_05("14641") = 2 */
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )


int ehPrimo(int num) {
		if (num <= 1) return 0; // 0 e 1 não são primos
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) return 0; // Se for divisível, não é primo
		}
		return 1; // Se não for divisível por nenhum número até a raiz quadrada, é primo
	}

void espelhado( int x)
{
	//definir dados
	int d, u, d2, u2 = 0;
	int numero2 = 0;
	
	// separar as unidades e dezenas do primeiro numero 
	
	d = x / 10; //ex: 21 pega o 2
	u = x % 10;//ex: 21 pega o 1
	
	// separar as unidades e dezenas do segundo numero 
	
	d2 = x % 10; //ex: 21 pega o 1
	u2 = x / 10; //ex: 21 pega o 2
	
	numero2 = d2 * 10;
	
	numero2 = numero2 + u2;
	
	//mostrar espelhamento se for primo
	if (ehPrimo(x) && ehPrimo(numero2))
	{
		
		if (d == u2 && u == d2)
		{
			printf("\nOs numeros primos %d%d e %d%d sao espelhados.", d, u, d2, u2);
		}
		
	}
}

/**
 * Questão 06.
 */
void metodo06 ( void ) {  //void p_06 ( void )
	printf ( "\n%s", "Questão 06 - Aberta" );
	
	int x = 0;
	
	printf("\nInsira x:");
	scanf ("%d", &x); getchar();
	
	for(int x = 11; x <= 99; x++)
	{
		if (ehPrimo(x))
		{ 
			espelhado(x);
		}
	}

	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	//end p_06
} // fim metodo06 ( )  // end p_6

int f_07 (char *seq){
	int  i = 0;
	int tamanho = strlen(seq);
	int  t = 0, u = 0;
	int result = 0;
	
	for ( i = 0; i < tamanho; i--){
		
		char char_local = seq[i];
		
		if(char_local == 't'){
			t++;
		}
		if(char_local == 'u'){
			u++;
		}
		if(t != 0 && u ==0){
			result =  2;
		}else{
			if(t == 0 && u != 0){
				 result = 1;
			}else{
				result = -1;
			}
		}
	}
	return (result);
}

/**
 * Questão 07.
 */
void metodo07 ( void ) {
	printf ( "\n%s", "Questao 07 - Aberta" );
	
	char cadeia [70];
	
	printf     ("Insira a cadeia:");
	scanf ("%s", cadeia); getchar();
	
	printf   ("\n%d", f_07(cadeia));

	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

int testar(const char *cadeia) {
	int soma_quadrados = 0;
	int soma_cubos = 0;
	
	// Iterar sobre a cadeia de caracteres
	while (*cadeia != '\0') {
		// Verificar se o caractere atual é um dígito
		if (*cadeia >= '0' && *cadeia <= '9') {
			int digito = *cadeia - '0'; // Converter o caractere para inteiro
			
			// Adicionar o quadrado do dígito à soma dos quadrados
			soma_quadrados += digito * digito;
			
			// Adicionar o cubo do dígito à soma dos cubos
			soma_cubos += digito * digito * digito;
		} else {
			// Se encontrar um caractere que não é um dígito, retorna 0 (falso)
			return 0;
		}
		// Avançar para o próximo caractere
		cadeia++;
	}
	
	// Verificar se a soma dos quadrados é igual à soma dos cubos
	if (soma_quadrados == soma_cubos) {
		return 1; // Retorna 1 se a afirmação for verdadeira
	} else {
		return 0; // Retorna 0 se a afirmação for falsa
	}
}

/**
 * Questão 08.
 */
void metodo08 ( void ) {
	printf ( "\n%s", "Questao 08 - Aberta" );
	
	char exemplo1 [20];
	char exemplo2 [20];
	char exemplo3 [20];
	
	printf   ("\nInsira exemplo1 =");
	scanf("%s", exemplo1); getchar();
	
	printf   ("\nInsira exemplo2 =");
	scanf("%s", exemplo2); getchar();
	
	printf   ("\nInsira exemplo3 =");
	scanf("%s", exemplo3); getchar();
	
	printf(" 0 = FALSE / 1 = TRUE");
	printf("Exemplo 1: %d\n", testar(exemplo1));
	printf("Exemplo 2: %d\n", testar(exemplo2));
	printf("Exemplo 3: %d\n", testar(exemplo3));
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )


int main ( void ) {
	// definir dados/resultados
	
	int opcao = 0;
	
	// repetir ate' desejar parar
	do {
		// identificar
		printf ( "\n" );             // para saltar linha
		printf ( "%s\n", "\nRefação da Primeira Avaliação - v.0.1 - 01/05/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski\n" );
		
		// mostrar opcoes
		printf ( "%s\n", "Opcoes:"         );
		printf ( "%s\n", " 0 - parar"      );
		printf ( "%s\n", " 1 - Questao 01   2 - Questao 02" );
		printf ( "%s\n", " 3 - Questao 03   4 - Questao 04" );
		printf ( "%s\n", " 5 - Questao 05   6 - Questao 06" );
		printf ( "%s\n", " 7 - Questao 07   8 - Questao 08" );
		printf ( "%s\n", "" );           // para saltar linha
		
		// ler opcao
		printf ( "%s", "Qual a sua opcao? " );
		scanf  ( "%d", &opcao );
		getchar ( );
		printf ( "%d",  opcao );
		
		// escolher acao
		switch ( opcao ) {
		case  0:
			break;
		case  1:
			metodo01 ( );
			break;
		case  2:
			metodo02 ( );
			break;
		case  3:
			metodo03 ( );
			break;
		case  4:
			metodo04 ( );
			break;
		case  5:
			metodo05 ( );
			break;
		case  6:
			metodo06 ( );
			break;
		case  7:
			metodo07 ( );
			break;
		case  8:
			metodo08 ( );
			break;
		default:
			printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
			break;
		} // fim escolher
	} while ( opcao != 0 );
	
	// encerrar execucao
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	
} // end main ( )

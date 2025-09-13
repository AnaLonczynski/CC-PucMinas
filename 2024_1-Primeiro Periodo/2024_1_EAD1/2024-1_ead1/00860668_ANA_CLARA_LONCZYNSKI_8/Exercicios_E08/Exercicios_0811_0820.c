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
#include <time.h>


void IntArrayM1 ( int n, int array [])
{
	int a=0;
	int x = 0;
	
	for ( x=0; x < n; x=x+1 )
	{
		scanf("%d", &a);
		if(a%2==0 && a >0){
			array [ x ]= a;
			printf ( "%2d: %d\n", x,  array[x] ); getchar( );
		}else{
			printf("VALOR INVALIDO, TENTE NOVAMENTE: ");	
			scanf("%d", &a);
		}
	} 
}  

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01 - Exercicio 0811" );
	
	int y = 0;
	
	printf("\nInsira um valor:"  );
	scanf("%d", &y); getchar ( );
	
	int array [ y ];
	
	if(y>0){
		IntArrayM1 ( y, array);
	}
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

typedef struct ARRAY{
	int length;
	int* data;
}ARRAY;

void writefilearray (int array[], char filename[], char arrayfile[], int y){
	
	FILE* arquivo = fopen(filename, "rt");
	FILE* resultado = fopen (arrayfile, "wt");
	int z = 0, cont = 0;
	int arrray [20];
	
	fscanf(arquivo, "%d", &cont);
	while(cont < y && !feof(arquivo)){	
		
		fprintf(resultado, "%d\n", arrray[cont]);
		fscanf (arquivo, "%d", &arrray[cont]);
		cont++;
	}
	
	printf("%d", z);
	
	fclose (arquivo);
	fclose (resultado);
}
/**
 * Metodo02.
 */
void metodo02 (  )
{
	// identificar
	printf ( "\n%s"  , "Metodo02 - Exercicio 0812" );
	
	int y = 0;
	int array [y];
	
	printf("\nInsira um valor:"  );
	scanf("%d", &y); getchar ( );
	
	if(y < 0 || y%2 != 0){		
		printf("\nValor inválido, insira novamente:"  );
		scanf("%d", &y); getchar ( );
	}else{	
		writefilearray(array, "ARRAY.TXT", "E2.txt", y);
	}
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

ARRAY* randomInt(ARRAY* arr1, int v1, int v2, int y, char filename[]){

	FILE* arquivo = fopen (filename, "wt");
	arr1->data[0] = v1;
	arr1->data[arr1->length - 1] = v2;
	
	fprintf(arquivo, "%d\n", y);
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = rand() % v2;
		fprintf(arquivo, "%d\n", arr1->data[i]);
	}
	
	fclose(arquivo);
	return arr1;
}
/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 - Exercicio 0813" );
	
	int y = 0, v1 = 0, v2 = 0;
	
	printf("\nInsira um valor:"  );
	scanf("%d", &y); getchar ( );
	
	printf("\nInsira um valor para o intervalo:"  );
	scanf("%d", &v1); getchar ( );

	printf("\nInsira outro valor para o intervalo:"  );
	scanf("%d", &v2); getchar ( );

	ARRAY* array;
	array = (ARRAY*)malloc(sizeof(ARRAY));
	array->length = y;
	array->data = (int*)malloc(array->length * sizeof(int*));
	
	randomInt(array, v1, v2, y, "E3.txt");
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )

int acharmenorimpar ( int n, char filename[]){
	
	FILE* arquivo = fopen(filename, "rt");
	int z = 0, menor = 100;
	int arr[n];
	
	//criar um arranjo com os dados do arquivo
	
	for(int i=0;i<n;i++){
		
		fscanf(arquivo, "%d", &z);
		arr[i] = z;
		printf("[%d] = %d\n", i, arr[i]);
	}
	
	// menor = 100 para o primeiro numero poder entrar na condicao
	
	for(int i=0;i<n;i++){
		if (!(arr[i] % 2==0) && arr[i] < menor) { // Se o número for ímpar
			menor = arr[i];
		}
	}
	
	return menor;
	fclose(arquivo);
}
/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04 - Exercicio 0814");
	
	int n = 0, menor;
	
	printf("\nInsira um valor:"  );
	scanf("%d", &n); getchar ( );
	
	menor = acharmenorimpar (n, "E3.txt");
	
	if(menor > 0){
		printf("o menor impar e': [%d]", menor);
	}else{
		printf("nao ha' valores impares");
	}
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

int acharmaiorimpar ( int n, char filename[]){
	
	FILE* arquivo = fopen(filename, "rt");
	int z = 0, maior = 0;
	int arr[n];
	
	//criar um arranjo com os dados do arquivo
	
	for(int i=0;i<n;i++){
		
		fscanf(arquivo, "%d", &z);
		arr[i] = z;
		printf("[%d] = %d\n", i, arr[i]);
	}
	
	for(int i=0;i<n;i++){
		if (!(arr[i] % 2==0) && arr[i] > maior) { // Se o número for ímpar
			maior = arr[i];
		}
	}
	
	return maior;
	fclose(arquivo);
}

/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05 - Exercicio 0815" );
	
	int n = 0, maior = 0;
	
	printf("\nInsira um valor:"  );
	scanf("%d", &n); getchar ( );
	
	maior = acharmaiorimpar (n, "E3.txt");
	
	if(maior > 0){
		printf("o maior impar e': [%d]", maior);
	}else{
		printf("nao ha' valores impares");
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

int Mediaarray ( int n, char filename[]){
	//ler arquivo e definir dados
	FILE* arquivo = fopen(filename, "rt");
	int z = 0, soma = 0, media = 0;
	int arr[n];
	
	//criar um arranjo com os dados do arquivo
	
	for(int i=0;i<n;i++){
		
		fscanf(arquivo, "%d", &z);
		arr[i] = z;
		printf("[%d] = %d\n", i, arr[i]);
		soma = soma + z;
	}
	
	//calcular media
	media = soma/n;
	
	return media;
	fclose(arquivo);
}

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	printf ( "\n%s"  , "Metodo06 - Exercicio 0816" );
	
	int n = 0, media = 0; 
	
	printf("\nInsira um valor:"  );
	scanf("%d", &n); getchar ( );
	
	media = Mediaarray(n,"E3.txt");
	printf("\na media e' igual = [%d]", media);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

bool ordemdescarray ( int n, int array[]){
	int valorAnterior;
	bool resultado = false;
	
	for(int i=0;i<5;i++){
		printf("%d = [%d]\n",i, array[i]);
	}
	
	valorAnterior = array[0];
	
	for(int i=0;i<n;i++){
		if(valorAnterior > array[i]){
			valorAnterior = array[i]; // Inverte os valores das variaveis
			resultado = true;
		}
	}
	return resultado;
}
/**
 * Metodo07.
 */
void metodo07 ( void )
{
	printf ( "\n%s"  , "Metodo07 - Exercicio 0817" );
	
	int n = 0; 
	int array[5]={5,4,3,2,1};
	bool result;
	
	printf("\nInsira um valor:"  );
	scanf("%d", &n); getchar ( );
	
	result = ordemdescarray(n, array);
	
	if(result == true){
		printf("\nOs numeros estao em ordem decrescente");
	}else{
		printf("\nOs numeros nao estao em ordem descrente");
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

void lerarquivo ( int n, char filename[], int array[]){
	
	// definir dados locais
	int x = 0;
	int y = 0;
	FILE* arquivo = fopen ( filename, "rt" );
	
// ler a quantidade de dados
	fscanf ( arquivo, "%d", &x );
	if ( n <= 0 || n > x )
	{
		printf("ERRO: Valor invalido.");
	}
	else
	{
		// ler e guardar valores em arranjo
		x = 0;
		while ( ! feof ( arquivo ) && x < n )
		{
			// ler valor
			fscanf ( arquivo, "%d", &y );
			// guardar valor
			array [ x ] = y;
			// passar ao proximo
			x = x+1;
		} // end while
	} // end if
}

int acharvalor(int n , int array [ ] , int valor )
{
	//definir dados
	int posicao = 0;
	bool teste = false;
	bool position = false;
	//verificar arranjo
	for (int i = 0; i < n; i++)
	{
		//testando codigo
		//printf("\n%d e %d" , array[i] , valor);
		//vai executar se for igual
		if (array[i] == valor)
		{
			//verificar qual a posicao dele
			posicao = i;
			//informar ao usuario
			//printf("\n%s %d %s %d" , "O numero" , valor,"se encontra no arranjo na posicao: " , posicao);
			if (posicao == valor && !position)
			{
				printf("\n\n%s" , "O VALOR PODE SER NELE ENCONTRADO!! ");
				position = true;
			}
			//colocar que foi encontrado 
			teste = true;
		}
	}
	//se acertou a posicao ou nao
	if (!position && teste)
	{
		printf("\n\n%s" , "O valor NAO pode ser nele encontrado!! ");
	}
	//testar se o valor foi encontrado para dizer se é possivel encontrar nele ou nao
	if (!teste)
	{
		printf("\n\n%s" , "Esse valor NAO esta no arranjo!! ");
	}
	return (teste);
}
/**
 * Metodo08.
 */
void metodo08 ( void )
{
	printf ( "\n%s"  , "Metodo08 - Exercicio 0818" );
	
	int n, encontrar = 0;
	int array[n];
	
	printf("\nInsira o tamanho da array:");
	
	printf("\nInsira o valor a ser encontrado:");
	scanf("%d", &encontrar); getchar();
	
	scanf("%d", &n); getchar();
	
	lerarquivo(n, "E3.txt", array);
	acharvalor (encontrar, array, n);
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar();
} // fim metodo08 ( )

int procurarnaarray (int n , int array [ ] , int valor )
{
	int posicao = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == valor)
		{
			posicao = i;
		}
		
	}
	return (posicao);
}

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	printf ( "\n%s"  , "Metodo09 - Exercicio 0819" );
	int n = 0;
	int valor = 0;
	
	printf("\nInsira o tamanho da array:");
	scanf("%d", &n); getchar();
	
	int array [n];
	
	printf("Procurado: ");
	scanf("%d", &valor); getchar(); 

	
	lerarquivo(n, "E3.txt", array);
	
	int i = procurarnaarray(n , array ,  valor);
	
	if (array[i] == valor)
	{
		printf("\n%s %d %s %d" , "O numero" , valor,"se encontra no arranjo na posicao: " , i);
	}
	else {
		printf("\n\n%s" , "Esse valor NAO esta no arranjo!! ");
	}
	
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

int procurarE10 (int n , int array [ ] , int valor )
{
	int quantidade = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == valor)
		{
			quantidade++;
		}
		
	}
	return (quantidade);
}
/**
 * Metodo10.
 */
void metodo10 ( void )
{
	printf ( "\n%s"  , "Metodo10 - Exercicio 0820" );
	int n = 0;
	int valor = 0;
	
	printf("\nInsira o tamanho da array:");
	scanf("%d", &n); getchar();
	
	int array [n];
	
	printf("Procurado: ");
	scanf("%d", &valor); getchar(); 
	
	lerarquivo(n, "E3.txt", array);
	
	int quantidade = procurarE10(n , array ,  valor);
	
	if(quantidade == 0)
	{		
		printf("\n\n%s" , "Esse valor NAO esta no arranjo!! ");
	}
	else{
		if(quantidade == 1)
		{		
			printf("\n%s %d %s" , "O numero" , valor,"aparece uma vez no arranjo");
		}
		else{
			printf("\n%s %d %s %d %s" , "O numero" , valor,"aparece" , quantidade , "vezes no arranjo");
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

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
#include "io.h"

typedef struct Array
{
	int length;
	int* dados;
	
}Array;


Array* randomInt(Array* arr1){
	int val1, val2;
	printf("%s", "\nInsira valor minimo:");
	scanf("%d",&val1); getchar();
	printf("%s", "\nInsira valor maximo:");
	scanf("%d",&val2); getchar();
	arr1->dados[0] = val1;
	arr1->dados[arr1->length -1] = val2;
	
	for(int i = 1; i < arr1->length; i++){
		arr1->dados[i] = rand() % val2;
	}
	return arr1;
}

Array* GravarDados (Array* arr1 , char filename[]){
	
	FILE* arquivo = fopen(filename, "wt");
	int cont = 0;
	
	fprintf(arquivo, "%d\n", arr1->length);
	
	while(cont < arr1->length && !feof(arquivo)){	
		fprintf(arquivo,"%d\n", arr1->dados[cont]);
		cont++;
	}
	
	fclose(arquivo);
	return arr1;
}

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo01\n" );
	
	Array* arr1;
	arr1 = (Array*)malloc(sizeof(Array));
	arr1->length = 5;
	
	printf      ("%s", "\nInsira legth:");
	scanf("%d", &arr1->length); getchar();
	
	arr1->dados = (int*)malloc(arr1->length * sizeof(int));
	
	arr1 = randomInt(arr1);
	GravarDados(arr1, "DADOS.TXT");
	
	for(int i = 0; i < arr1->length; i++){
		printf("[%d] = %d\n",i, arr1->dados[i]);
	}
	
	printf("\n");
	free(arr1->dados);
	free(arr1);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

Array* readArrayFromFile (Array* arr1, char filename[]){
	
	FILE* arquivo = fopen(filename, "rt");
	
	for(int i=0;i<arr1->length;i++){
		
		fscanf  (arquivo, "%d", &arr1->dados[i]);
	}
	
	fclose(arquivo);
	return arr1;
}

Array* ProcurarDado (int procurado, Array* arr1){
	
	int encontrado = 0;
	
	for(int i=0;i<arr1->length;i++){
		if(arr1->dados[i] == procurado){
			printf("\nValor Encontrado! Valor = %d", arr1->dados[i]);
			encontrado++;
		}
	}
	
	if(encontrado == 0){
		printf("\n%s", "Valor nao encontrado");
	}
	
	return arr1;
}

/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo02" );
	
	Array* arr1;
	int procurado = 0;
	arr1 = (Array*)malloc(sizeof(Array));
	
	arr1->length = 5;
	printf      ("%s", "\nInsira length:");
	scanf("%d", &arr1->length); getchar();
	
	arr1->dados = (int*)malloc(arr1->length-1*sizeof(int));
	
	printf("%s", "\nInsira o valor procurado:");
	scanf ("%d", &procurado);         getchar();
	
	arr1 = readArrayFromFile (arr1, "DADOS.TXT");
	ProcurarDado  (procurado, arr1);
	
	printf("\n");
	free(arr1->dados);
	free(arr1);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

void CompararArranjos ( Array* arr1, Array* arr2){
	
	int cont = 0;
	
	if(arr1->length==arr2->length){
		
		for(int i=0;i<arr1->length;i++){
			for(int j=0;j<arr2->length;j++){
				if(arr1->dados[i] == arr2->dados[j]){
					cont++;
				}
			}
		}
		
		for(int i = 0; i < arr1->length; i++){
		printf("[%d] = %d\n",i, arr1->dados[i]);
		}
		printf("\n\n");
		for(int i = 0; i < arr2->length; i++){
		printf("[%d] = %d\n",i, arr2->dados[i]);
		}
		
		if(cont == arr1->length){
			printf("\n%s", "Arranjos Iguais!");
		}else{
			printf("\n%s", "Arranjos Diferentes!");
		}
		
	}else{
		printf("\n%s", "/ERRO/: Tamanhos diferentes!");
	}
}
/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo03 " );
	
	Array* arr1;
	arr1=(Array*)malloc(sizeof(Array*));
	arr1->length = 5;
	printf   ("%s", "\nInsira length do primeiro arranjo:");
	scanf("%d", &arr1->length);                  getchar();
	arr1->dados = (int*)malloc(arr1->length-1*sizeof(int));
	
	Array* arr2;
	arr2 = (Array*)malloc(sizeof(Array*));
	arr2->length = 5;
	printf   ("%s", "\nInsira length do segundo arranjo:" );
	scanf("%d", &arr2->length);                  getchar();
	arr2->dados = (int*)malloc(arr2->length-1*sizeof(int));
	
	
	arr1 = randomInt(arr1); GravarDados(arr1, "DADOS1.TXT");
	arr2 = randomInt(arr2); GravarDados(arr2, "DADOS2.TXT");
	
	CompararArranjos(arr1, arr2);
	
	printf("\n");
	free(arr1->dados);
	free(arr1);
	free(arr2->dados);
	free(arr2);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )


int SomarArranjos ( Array* arr1, int constante, Array* arr2){

	int soma = 0;	
	if(arr1->length == arr2->length){
		
		//efetuar soma com constante
		for(int i=0; i<arr1->length; i++){
			for(int j=0; j<arr2->length; j++){
				soma = soma + arr1->dados[i] + (arr2->dados[j] * constante);
			}
		}
		
	}else{
		printf("\n%s", "/ERRO/: Tamanhos diferentes!");
	}
	
	return soma;
}

/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo04" );
	
	int soma = 0, constante = 0 ;
	
	Array* arr1;
	arr1 = (Array*)malloc(sizeof(Array*));
	arr1->length = 0;
	printf   ("%s", "\nInsira length do primeiro arranjo:");
	scanf("%d", &arr1->length);                  getchar( );
	arr1->dados = (int*)malloc(arr1->length-1*sizeof(int) );
	
	Array* arr2;
	arr2 = (Array*)malloc(sizeof(Array*));
	arr2->length = 0;
	printf   ("%s", "\nInsira length do segundo arranjo:");
	scanf("%d", &arr2->length);                  getchar();
	arr2->dados = (int*)malloc(arr2->length-1*sizeof(int));
	
	printf   ("%s", "\nInsira a constante:");
	scanf("%d", &constante);      getchar( );
	
	arr1 = readArrayFromFile(arr1, "DADOS1.TXT");
	arr2 = readArrayFromFile(arr2, "DADOS2.TXT");
	
	soma = SomarArranjos(arr1, constante, arr2);
	
	printf   ("\nSoma = %d:", soma);
	
	free(arr1->dados);
	free(arr1);
	free(arr2->dados);
	free(arr2);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

bool ArrayDescrescente(Array* arr1){
	bool resposta = true;
	int ValorAnterior;
	int ValorAtual;
	
	ValorAnterior = arr1->dados[0];
	
	for(int i=0;i<arr1->length;i++){
		
		ValorAtual = arr1->dados[i];
		if(ValorAnterior < ValorAtual){
			resposta = false;
		}
		ValorAnterior = ValorAtual;
	}
	return resposta;
}
/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo05" );
	
	bool resposta;
	Array* arr1;
	arr1 = (Array*)malloc(sizeof(Array*));
	arr1->length = 5;
	printf   ("%s", "\nInsira length do primeiro arranjo:");
	scanf("%d", &arr1->length);                  getchar( );
	arr1->dados = (int*)malloc (arr1->length * sizeof(int));
	
	arr1 = readArrayFromFile(arr1, "DADOS.TXT");
	resposta = ArrayDescrescente (arr1);
	
	if(resposta == 0 ){
		printf("%s","\nO arranjo nao e' decrescte");
	}else{
		printf("%s","\nArranjo decrescente");
	}
	
	free(arr1->dados);
	free(arr1);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

typedef struct Matriz{
	int** dados;	
	int  rows;
	int  columns;
	int ix, iy ;
}Matriz;

Matriz* newMatrix ( int rows, int columns )
{
	Matriz* tmpMatrix = (Matriz*) malloc (sizeof(Matriz*));

	if ( tmpMatrix != NULL )
	{
		tmpMatrix->rows = 0;
		tmpMatrix->columns = 0;
		tmpMatrix->dados = NULL;
		// reservar espaco
		if ( rows>0 && columns>0 )
		{
			tmpMatrix->rows = rows;
			tmpMatrix->columns = columns;
			tmpMatrix->dados = malloc (rows * sizeof(ints));
			if ( tmpMatrix->dados )
			{
				for ( tmpMatrix->ix=0;
					tmpMatrix->ix<tmpMatrix->rows;
					tmpMatrix->ix=tmpMatrix->ix+1 )
				{
					tmpMatrix->dados [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
				} 
			} 
			tmpMatrix->ix = 0;
			tmpMatrix->iy = 0;
		}
	}
	return ( tmpMatrix );
}

void freeMatrix ( Matriz* matrix )
{
	if ( matrix != NULL )
	{
		if ( matrix->dados != NULL )
		{
			for ( matrix->ix=0;
				matrix->ix<matrix->rows;
				matrix->ix=matrix->ix+1 )
			{
				free ( matrix->dados [ matrix->ix ] );
			} 
			free ( matrix->dados );
		}
		free ( matrix );
	} 
}

Matriz* freadintMatrix ( chars fileName )
{
	Matriz* matrix = NULL;
	int rows = 0;
	int columns = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
	fscanf ( arquivo, "%d", &rows );
	fscanf ( arquivo, "%d", &columns );
	if ( rows <= 0 || columns <= 0 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
	}
	else
	{
		matrix = newMatrix ( rows, columns );
		if ( matrix != NULL && matrix->dados == NULL )
		{
		matrix->rows = 0;
			matrix->columns = 0;
			matrix->ix = 0;
			matrix->iy = 0;
			}else{
				if ( matrix != NULL )
				{
					matrix->ix = 0;
					while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
					{
						matrix->iy = 0;
						while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
						{
						fscanf ( arquivo, "%d", &(matrix->dados [ matrix->ix ][ matrix->iy ]) );
						matrix->iy = matrix->iy+1;
					} 
					matrix->ix = matrix->ix+1;
				}
				matrix->ix = 0;
				matrix->iy = 0;
			} 
		} 
	} 
	return ( matrix );
}

void printIntMatrix ( Matriz* matrix )
{
	if ( matrix != NULL && matrix->dados != NULL )
	{
		for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
		{
		for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
			{
				printf ( "%3d\t", matrix->dados [ matrix->ix ][ matrix->iy ] );
			} 
			printf ( "\n" );
		} 
	} 
}

Matriz* matrixTranspose ( Matriz* matrix)
{
	
	Matriz* matrix2 = newMatrix (matrix->columns , matrix->rows);
	if(matrix->rows == matrix2->columns && matrix->columns == matrix2->rows)
	{
		for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix +1) 
		{
			for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1) 
			{
				matrix2->dados[matrix->iy][matrix->ix] = matrix->dados[matrix->ix][matrix->iy];
			}
		}
	}
	return matrix2;
}

/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo06" );
	
	//construir matrizes
	Matriz* matrix = freadintMatrix("DADOS.TXT");
	
	Matriz* matrix2 = newMatrix(matrix->columns, matrix->rows);

	IO_println("matriz1: ");
	printIntMatrix ( matrix );
	matrix2 = matrixTranspose (matrix );	
	IO_println("matriz2: ");
	printIntMatrix ( matrix2 );
	
	
	// reciclar espaco
	freeMatrix ( matrix );
	freeMatrix ( matrix2 );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

bool matrixZero (  Matriz* matrix  )
{
	bool allzero = false;
	
	matrix->ix = 0;
	while(matrix->ix < matrix->rows )
	{
		
		matrix->iy = 0;
		while(matrix->iy < matrix->columns && matrix->dados [matrix->ix][matrix->iy] == 0 )
		{	
			matrix->iy = matrix->iy+ 1;
			
		}
		matrix->ix = matrix->ix+ 1;
	}
//	printf("[%d]" , matrix->ix);
//	printf("[%d]" , matrix->iy);
	allzero = ( matrix->ix == matrix->rows && matrix->iy == matrix->columns);
//	printf("[%d]" , allzero);
	return (allzero);
}

/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo07 " );
	
	// ler dados
	Matriz* matrix = freadintMatrix ( "allzero.txt" );
	
// mostrar dados
	IO_printf ( "\n" );
	
	
	if ( matrix->dados )
	{
		printIntMatrix ( matrix );
		bool resultado =  matrixZero (  matrix  );
		if(resultado)
		{
			IO_println("\nTodos os numeros da matriz sao zero! ");
		}
		else
		{
			IO_println("\nNAO sao todos zeros! ");
		}
	} // fim se
	else
	{
		IO_println("Erro: espaco insuficiente! ");
	}
// reciclar espaco
	freeMatrix ( matrix );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

bool matrixCompare ( Matriz* matrix, Matriz* matrix2 )
{
	bool igual = false;
	
	
	matrix->ix = 0;
	while(matrix->ix < matrix->rows && matrix->dados [matrix->ix][matrix->iy] == matrix2->dados [matrix->ix][matrix->iy]  )
	{
		matrix->iy = 0;
		while(matrix->iy < matrix->columns &&  matrix->dados[matrix->ix][matrix->iy] == matrix2->dados [matrix->ix][matrix->iy] )
		{	
			matrix->iy = matrix->iy+ 1;
		}
		matrix->ix = matrix->ix+ 1;
	}
	
	igual= ( matrix->ix == matrix->rows && matrix->iy == matrix->columns);
	
	
	return (igual);
}

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo08 " );
	
	bool resultado = false;
	// ler dados
	Matriz* matrix = freadintMatrix ( "MATRIX1.TXT" );
	Matriz* matrix2 = freadintMatrix ( "MATRIX2.TXT" );
// mostrar dados
	IO_printf ( "\n" );
	
	
	if ( matrix->dados && matrix2->dados )
	{
		IO_println("Matriz 1: ");
		printIntMatrix ( matrix );
		IO_println("Matriz 2: ");
		printIntMatrix ( matrix2 );
		if(matrix2->rows == matrix->rows && matrix2->columns == matrix->columns)
		{
			resultado =  matrixCompare (  matrix , matrix2 );
			//IO_println("TESTTEEEE");
		}
		if(resultado)
		{
			IO_println("\nAs matrizes sao iguais! ");
		}
		else
		{
			IO_println("\nAs matrizes NAO sao iguais! ");
		}
	} // fim se
	else
	{
		IO_println("Erro: espaco insuficiente! ");
	}
// reciclar espaco
	freeMatrix ( matrix );
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

Matriz* matrixAdd (Matriz* matrix , int valor , Matriz* matrix2 )
{
	Matriz* soma = newMatrix(matrix->rows , matrix->columns);
	
	//ir passando de linha
	for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix +1) 
	{
		//ir passando de coluna
		for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1) 
		{
			//soma
			soma->dados[matrix->ix][matrix->iy] = matrix->dados[matrix->ix][matrix->iy] + (valor * matrix2->dados[matrix->ix][matrix->iy]);
			
		}
	}
	
	return(soma);
} 

/**
 * Metodo09.
 */
void metodo09 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo09 ");

	// ler dados
	Matriz* matrix = freadintMatrix ( "MATRIX1.TXT" );
	Matriz* matrix2 = freadintMatrix ( "MATRIX2.TXT" );
	Matriz* soma = newMatrix(matrix->rows , matrix->columns);
// mostrar dados
	IO_printf ( "\n" );
	
	
	if ( matrix->dados && matrix2->dados )
	{
		IO_println("Matriz 1: ");
		printIntMatrix ( matrix );
		IO_println("Matriz 2: ");
		printIntMatrix ( matrix2 );
		if(matrix2->rows == matrix->rows && matrix2->columns == matrix->columns)
		{
			soma =  matrixAdd (  matrix , 2 , matrix2 );
			//IO_println("TESTTEEEE");
			IO_printf ("\nA soma das matrizes com a segunda escalada por uma constante e: \n");
			printIntMatrix ( soma );
		}
		else
		{
			IO_println("As matrizes possuem tamanhos diferentes! ");
		}
	} // fim se
	else
	{
		IO_println("Erro: espaco insuficiente! ");
	}
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo09 ( )

Matriz* matrixProduct (Matriz* matrix  , Matriz* matrix2 )
{
	Matriz* mult = newMatrix(matrix->rows , matrix2->columns);
	int soma = 0;
	//ir passando de linha
	for (mult->ix = 0; mult->ix < mult->rows; mult->ix = mult->ix +1) 
	{
		//ir passando de coluna
		for (mult->iy = 0; mult->iy < mult->columns; mult->iy = mult->iy + 1) 
		{
			//soma
			soma = 0;
			for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1) 
			{
				soma = soma + matrix->dados[mult->ix][matrix->iy] * matrix2->dados[matrix->iy][mult->iy];
			}
			
			mult->dados[mult->ix][mult->iy] = soma;
		}
		
		
	}
	
	return(mult);
} 

/**
 * Metodo10.
 */
void metodo10 ( void )
{
	// identificar
	printf ( "\n%s"  , "Metodo10 " );
	
	// ler dados
	Matriz* matrix = freadintMatrix ( "MATRIX1.TXT" );
	Matriz* matrix2 = freadintMatrix ( "MATRIX2.TXT" );
	Matriz* soma = newMatrix(matrix->rows , matrix->columns);
// mostrar dados
	IO_printf ( "\n" );
	
	
	if ( matrix->dados && matrix2->dados )
	{
		IO_println("Matriz 1: ");
		printIntMatrix ( matrix );
		IO_println("Matriz 2: ");
		printIntMatrix ( matrix2 );
		if(matrix2->rows == matrix->columns)
		{
			soma =  matrixProduct (matrix  ,  matrix2 );
			//IO_println("TESTTEEEE");
			IO_printf ("\nO produto das matrizes e: \n");
			printIntMatrix ( soma );
		}
		else
		{
			IO_println("A coluna da primeira e a linha da segunda nao sao iguais! ");
		}
	} // fim se
	else
	{
		IO_println("Erro: espaco insuficiente! ");
	}
// reciclar espaco
	freeMatrix ( matrix );
	
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


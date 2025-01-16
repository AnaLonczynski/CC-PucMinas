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

int q_01 (int m, int n, int a[]){
	int x=0;
	if (0<m && m<n-1 && a[m-1]-a[m]<0 && a[m]-a[m+1]>0){
		x=1;
	}
	if(0<m && m<n){
		if(x>=0){
			x = x + q_01(m-1,n,a);
		}else{x = -m;}
	}
	return(x);
}

/**
 * Metodo01.
 */
void metodo01 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 1\n" );
	
	int n = 6;
	int array [] = {2,4,3,9,7,6};
	printf("%d\n",q_01(n-1,n,array));
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo01 ( )

/*RESPOSTA : 2*/

void q_02 (char *p, char *q){
	char *r =calloc (strlen(p)+strlen(q)+1, sizeof(char));
	int k = 0;
	for(int x=0;x<strlen(p);x++){
		for(int y=0;y<strlen(q);y++){
			if(x==strlen(p)/2){
				r[k] = p[x];
				r[k+1] = q[y], k=k+2;
				if(k>6){
					y=strlen(q), x =strlen(p);
				}
			}
		}
	}
	printf("[%s]\n",r);
}
/**
 * Metodo02.
 */
void metodo02 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 2\n" );
	
	char  *p = "queijo", *q = "goiabada";
	q_02(p, q);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo02 ( )

/*RESPOSTA: "[igioiiia]"*/

void q_03 (int a, int b, int c, char m[][3][8]){
	for(int x=0;x<a;x++){
		for(int y=0;y<b;y++){
			if('A'<m[x][0][0]&& m[x][0][0]<'Z'){
				printf("%8s", m[x][2]);
				y=b;
				printf("\n");
			}
		}
	}
}
/**
 * Metodo03.
 */
void metodo03 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 3\n" );
	
	char m[][3][8]={{{"Cinza"},{"Gray"},{"Grau"}},{{"Amarelo"},{"Yellow"},{"Gelb"}},{{"Roxo"},{"Purple"},{"Lila"}}};
	q_03(3,3,8,m);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo03 ( )

/*RESPOSTA:c) Grau Lila*/

void q_04 (char* p){
	//int x=0;
	for(int y=0;y<strlen(p);y++){
		if(y<strlen(p)-1 && (p[y]=='a'||p[y]=='o')){
			for(int z=y;z<strlen(p);z++){
				p[z]=p[z+1];
			}
		}
		printf("[%s]\n", p);
	}
}
/**
 * Metodo04.
 */
void metodo04 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 4\n" );
	
	char p[] = "achocolatado";
	q_04(p);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
} // fim metodo04 ( )

/*RESPOSTA : d) [chcltd]*/

char* q_05(int x, int y, char* p){
	char c = '_';
	if(0<=x && x<strlen(p) && 0<=y && y<strlen(p)){
		c = p[x]; p[x] = p[y]; p[y] = c;
	}
	return (p);
}
/**
 * Metodo05.
 */
void metodo05 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 5\n" );
	
	char* p = "alegria";
	p = q_05 (1,4,q_05(2,3,p));
	printf("[%s]\n", p);
	p = q_05 (2,3,q_05(1,4,p));
	printf("[%s]\n", p);
	
	// encerrar
	printf ( "\n%s\n", "\nApertar ENTER para continuar." );
	getchar( );
	
} // fim metodo05 ( )

/*RESPOSTA: a) "argelia" "alegria"*/

int q_06 (char palavra []){
	int tamanho = strlen(palavra), valor = 0, pa = 0;
	for(int i=0;i<tamanho;i++){
		//somar valor por letra
		if(palavra[i]=='A'||palavra[i]=='J'||palavra[i]=='S'){
			valor=valor+1;
		}else if(palavra[i]=='B'||palavra[i]=='K'||palavra[i]=='T'){
			valor=valor+2;
		}else if(palavra[i]=='C'||palavra[i]=='L'||palavra[i]=='U'){
			valor=valor+3;
		}else if(palavra[i]=='D'||palavra[i]=='M'||palavra[i]=='V'){
			valor=valor+4;
		}else if(palavra[i]=='E'||palavra[i]=='N'||palavra[i]=='W'){
			valor=valor+5;
		}else if(palavra[i]=='F'||palavra[i]=='O'||palavra[i]=='X'){
			valor=valor+6;
		}else if(palavra[i]=='G'||palavra[i]=='P'||palavra[i]=='Y'){
			valor=valor+7;
		}else if(palavra[i]=='I'||palavra[i]=='R'){
			valor=valor+9;
		}else{
			valor = valor+8;
		}
	}
	
	
		int pb=0;
		if(valor!=11||valor!=22){
			pa = valor /10;
			pb = valor%10;
		}
		valor = pa+pb;
	
	
	return valor;
}
/**
 * Metodo06.
 */
void metodo06 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 6\n" );
	
	char palavra[30];
	int resultado;
	
	printf("Palavra = ");
	scanf("%s", palavra); getchar();
	
	resultado = q_06(palavra);
	printf("%d\n", resultado);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo06 ( )

struct Datas{
	int dias[3];
	struct Data{
		int dia, mes, ano;
	}data[3];
};

struct Datas q_07 (int professor[]){
	
	struct Datas* estrutura;
	int dife = 0;
	
	//preencher struct
	for(int i=0;i<3;i++){
		estrutura->dias[i] = professor[i];
	}
	for(int j=0;j<3;j++){
		estrutura->data[j].dia = (*estrutura->dias%365)%30;
		estrutura->data[j].mes = (*estrutura->dias%365)/30;
		estrutura->data[j].ano = (*estrutura->dias%365);
	}
	
	//encontrar oque falta
	dife = *professor%365;
	
	//mostrar quem fara primeiro
	if(dife*(estrutura->dias[0])>dife*(estrutura->dias[1])&&dife*(estrutura->dias[0])>dife*(estrutura->dias[2])){
		printf("%s\n", "O professor 1 fará aniversário primeiro");
	}else if(dife*(estrutura->dias[0])<dife*(estrutura->dias[0])&&dife*(estrutura->dias[1])>dife*(estrutura->dias[2])){
		printf("%s\n", "O professor 2 fará aniversário primeiro");
	}else{
		printf("%s\n", "O professor 3 fará aniversário primeiro");
	}
	return *estrutura;
}
/**
 * Metodo07.
 */
void metodo07 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 7\n " );
	
	int professor []= {9876, 8967, 6789};
	q_07(professor);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo07 ( )

void q_08(FILE *arquivo, FILE *resultado){
	int valor = 0;
	do{
		fscanf(arquivo, "%i", &valor);
		if(valor%2 == 0){
			fprintf(resultado, "%i\n", valor);
		}
		else{
			q_08(arquivo, resultado);
			fprintf(resultado, "%i\n", valor);
		}
	}while(!feof(arquivo));
}

/**
 * Metodo08.
 */
void metodo08 ( void )
{
	// identificar
	printf ( "\n%s"  , "Questao 8\n " );
	
	FILE *arquivo = fopen("data.txt", "rt");
	FILE *resultado = fopen("resultado.txt", "wt");
	q_08(arquivo, resultado);
	fclose(arquivo);
	fclose(resultado);
	
	// encerrar
	printf ( "\n%s\n", "Apertar ENTER para continuar." );
	getchar( );
	
} // fim metodo08 ( )

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
		printf ( "%s\n", "A_02 - v.0.1 - 06/05/2024"       );
		printf ( "%s\n", "Matricula: 0860668 Nome: Ana Clara Lonczynski" );
		
		// mostrar opcoes
		printf ( "%s\n", "  Opcoes:"         );
		printf ( "%s\n", "  0 - parar"      );
		printf ( "%s\n", "  1 - Questao 1   2 - Questao 2" );
		printf ( "%s\n", "  3 - Questao 3   4 - Questao 4" );
		printf ( "%s\n", "  5 - Questao 5   6 - Questao 6" );
		printf ( "%s\n", "  7 - Questao 7   8 - Questao 8" );
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


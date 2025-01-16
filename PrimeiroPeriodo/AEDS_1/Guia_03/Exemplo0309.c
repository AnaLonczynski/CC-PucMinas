/*
Exemplo0309 - v0.9. - 13 / 03 / 2024
Author: Ana Clara Lonczynski
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
  Method_00 - nao faz nada.
 */
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )
/**
  Method_01 - Repeticao com teste no inicio.
 */
void method_01 ( void )
{
// definir dado
	int x = 0;
// identificar
	IO_id ( "Method_02 - v0.9" );
// ler do teclado o valor inicial
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
	while ( x > 0 )
	{
		// mostrar valor atual
		IO_println ( IO_toString_d ( x ) );
		// passar ao proximo valor
		x = x - 1;
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Repeticao com teste no inicio.
 */
void method_02 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
// identificar
	IO_id ( "Method_02 - v0.9" );
// ler do teclado
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
	y = x; // copiar o valor lido (e' melhor)
	while ( y > 0 )
	{
		// mostrar valor atual
		IO_println ( IO_toString_d ( y ) );
		// passar ao proximo valor
		y = y - 1;
		
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Repeticao com teste no inicio.
 */
void method_03 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
// identificar
	IO_id ( "Method_03 - v0.9" );
// ler do teclado
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
	y = 1; // o valor lido devera' ser preservado
	while ( y <= x )
	{
		// mostrar valor atual
		IO_printf ( "%d\n", y );
		// passar ao proximo valor
		y = y + 1;
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Repeticao com teste no inicio e variacao.
 */
void method_04 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
	int z = 0;
// identificar
	IO_id ( "Method_04 - v0.9" );
// ler do teclado
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
	for ( y = 1; y <= x; y = y + 1 )
	{
		// ler valor do teclado
		z = IO_readint ( "Valor = " );
		// mostrar valor atual
		IO_printf ( "%d. %d\n", y, z );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05 - Repeticao com teste no inicio e variacao.
 */
void method_05 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
	int z = 0;
// identificar
	IO_id ( "Method_05 - v0.9" );
// ler do teclado
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
	for ( y = x; y >= 1; y = y - 1 )
	{
		// ler valor do teclado
		z = IO_readint ( "Valor = " );
		// mostrar valor atual
		IO_printf ( "%d. %d\n", y, z );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06 - Repeticao sobre cadeia de caracateres.
 */
void method_06 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
	
	chars palavra = IO_new_chars ( STR_SIZE );
	int tamanho = 0;
// identificar
	IO_id ( "Method_06 - v0.9 ");
// ler do teclado
	palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
	tamanho = strlen ( palavra ) - 1;
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
	for ( y = tamanho; y >= 0; y = y - 1 )
	{
		// mostrar valor atual
		IO_printf ( "%d: [%c]\n", y, palavra [y] );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Repeticao sobre cadeia de caracateres.
 */
void method_07 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
	
	char palavra [STR_SIZE];
	int tamanho = 0;
// identificar
	IO_id ( "Method07 - v0.9" );
// ler do teclado
	IO_printf ( "Entrar com uma palavra: " );
	scanf ( "%s", palavra ); getchar( );
// OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura.
// repetir para cada letra
	tamanho = strlen ( palavra );
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
	for ( y = 0; y < tamanho; y = y + 1 )
	{
		// mostrar valor atual
		IO_printf ( "%d: [%c]\n", y, palavra [y] );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08 - Repeticao com intervalos.
 */
void method_08 ( void )
{
// definir dado
	int inferior = 0;
	int superior = 0;
	int x = 0;
// identificar
	IO_id ( "Method08 - v0.9" );
// ler do teclado
	inferior = IO_readint ( "Limite inferior do intervalo: " );
	superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
	for ( x = inferior; x <= superior; x = x + 1 )
	{
		// mostrar valor atual
		IO_printf ( "%d\n", x );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09 - Repeticao com intervalos.
 */
void method_09 ( void )
{
// definir dado
	double inferior = 0;
	double superior = 0;
	double passo = 0;
	double x = 0;
// identificar
	IO_id ( "Method_09 - v0.9 ");
// ler do teclado
	inferior = IO_readdouble ( "Limite inferior do intervalo : " );
	superior = IO_readdouble ( "Limite superior do intervalo : " );
	passo = IO_readdouble ( "Variacao no intervalo (passo): " );
// inicio teste variacao
	for ( x = superior; x >= inferior; x = x - passo )
	{
		// mostrar valor atual
		IO_printf ( "%lf\n", x );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10 - Repeticao com confirmacao.
 */
void method_10 ( void )
{
// definir dado
	double inferior = 0;
	double superior = 0;
	double passo = 0;
	double x = 0;
// identificar
	IO_id ( "Method_10 - v0.9" );
// ler do teclado
	inferior = IO_readdouble ( "Limite inferior do intervalo : " );
// repetir ate' haver confirmacao de validade
	do
	{
		superior = IO_readdouble ( "Limite superior do intervalo: " );
	}
	while ( inferior >= superior );
// repetir ate' haver confirmacao de validade
	do
	{
		passo = IO_readdouble ( "Variacao no intervalo (passo): " );
	}
	while ( passo <= 0.0 );
// inicio teste variacao
	for ( x = inferior; x <= superior; x = x + passo )
	{
		// mostrar valor atual
		IO_printf ( "%lf\n", x );
	} // end for
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
{
// definir dado
	int x = 0;
// repetir até desejar parar
	do
	{
		// identificar
		IO_id ( "EXEMPLO0309 - Programa - v0.9" );
		// ler do teclado
		IO_println ( "Opcoes" );
		IO_println ( "0  - Parar" );
		IO_println ( "1  - Repeticao com teste no inicio" 			);
		IO_println ( "2  - Repeticao com teste no inicio" 			);
		IO_println ( "3  - Repeticao com teste no inicio" 			);
		IO_println ( "4  - Repeticao com teste no inicio e variacao" );
		IO_println ( "5  - Repeticao com teste no inicio e variacao" );
		IO_println ( "6  - Repeticao sobre cadeia de caracateres   " );
		IO_println ( "7  - Repeticao sobre cadeia de caracateres.  "	);
		IO_println ( "8  - Repeticao com intervalos.  "				);
		IO_println ( "9  - Repeticao com intervalos.  "				);
		IO_println ( "10 - Repeticao com confirmacao."				);
		IO_println ( "" );
		x = IO_readint ( "Entrar com uma opcao: " );
		// testar valor
		switch ( x )
		{
			case 0: method_00 ( ); break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break; 
			case 3: method_03 ( ); break;
			case 4: method_04 ( ); break;
			case 5: method_05 ( ); break;
			case 6: method_06 ( ); break;
			case 7: method_07 ( ); break;
			case 8: method_08 ( ); break;
			case 9: method_09 ( ); break;
			case 10: method_10 ( ); break;
			
		default:
			IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
				IO_concat ( IO_toString_d ( x ), ")" ) ) );
		} // end switch
	}
	while ( x != 0 );
// encerrar
	IO_pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
0.1: erro na l54: variavel X no lugar de y;
o.2: OK;
0.3: OK;
0.4: OK;
0.5: Não consigo resolver problema do espaço entre as cadeias de ch no metodo 6;
0.6: Não consigo resolver problema do espaço entre as cadeias de ch no metodo 6 e 7;
0.7: OK;
0.8: Passo -1 e' infinito; 
0.9: Passos ao contrario (do menor para o maior) nao funcionam
---------------------------------------------- previsao de testes
a.) [ 0.1 : 0.5 ] e passo = 0.1
b.) [ 0.5 : 0.1 ] e passo = -0.1
c.) [ 0.5 : 0.1 ] e passo = 0.1
d.) [ 0.1 : 0.5 ] e passo = -0.1
---------------------------------------------- historico
Versao Data Modificacao
0.1 11/03 esboco
0.2 13/03
0.6 19/03 
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) 
0.2 02. ( OK )
0.3 03. ( OK )
0.4 04. ( OK )
0.5 05. ( OK )
0.6 06. ( OK )
0.7 07. ( OK )
0.8 08. ( OK )
0.9 09. ( OK )
*/


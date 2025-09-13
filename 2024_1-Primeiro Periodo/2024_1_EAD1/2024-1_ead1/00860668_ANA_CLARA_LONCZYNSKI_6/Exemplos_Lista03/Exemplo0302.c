/*
Exemplo0302 - v0.2. - 13 / 03 / 2024
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
	IO_id ( "Method_02 - v0.2" );
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
	IO_id ( "Method_02 - v0.2" );
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
	IO_id ( "Method_03 - v0.2" );
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
		IO_id ( "EXEMPLO0302 - Programa - v0.2" );
		// ler do teclado
		IO_println ( "Opcoes" );
		IO_println ( "0 - Parar" );
		IO_println ( "1 - Repeticao com teste no inicio" );
		IO_println ( "2 - Repeticao com teste no inicio" );
		IO_println ( "3 - Repeticao com teste no inicio" );
		IO_println ( "" );
		x = IO_readint ( "Entrar com uma opcao: " );
		// testar valor
		switch ( x )
		{
			case 0: method_00 ( ); break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break; 
			case 3: method_03 ( ); break;
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
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 3
d.) 5
e.) -5
---------------------------------------------- historico
Versao Data Modificacao
0.1 11/03 esboco
0.2 13/03
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) 
0.2 02. ( OK )
*/ 

/*
Resultados:

EXEMPLO0302 - Programa - v0.2
Autor: Ana Clara Lonczynski

Opcoes
0 - Parar
1 - Repeticao com teste no inicio
2 - Repeticao com teste no inicio
3 - Repeticao com teste no inicio

Entrar com uma opcao: 3
Method_03 - v0.2
Autor: Ana Clara Lonczynski

Entrar com uma quantidade: 0

Apertar ENTER para continuar

EXEMPLO0302 - Programa - v0.2
Autor: Ana Clara Lonczynski

Opcoes
0 - Parar
1 - Repeticao com teste no inicio
2 - Repeticao com teste no inicio
3 - Repeticao com teste no inicio

Entrar com uma opcao: 3
Method_03 - v0.2
Autor: Ana Clara Lonczynski

Entrar com uma quantidade: 1
1

Apertar ENTER para continuar

EXEMPLO0302 - Programa - v0.2
Autor: Ana Clara Lonczynski

Opcoes
0 - Parar
1 - Repeticao com teste no inicio
2 - Repeticao com teste no inicio
3 - Repeticao com teste no inicio

Entrar com uma opcao: 3
Method_03 - v0.2
Autor: Ana Clara Lonczynski

Entrar com uma quantidade: 5
1
2
3
4
5

Apertar ENTER para continuar

EXEMPLO0302 - Programa - v0.2
Autor: Ana Clara Lonczynski

Opcoes
0 - Parar
1 - Repeticao com teste no inicio
2 - Repeticao com teste no inicio
3 - Repeticao com teste no inicio

Entrar com uma opcao: 3
Method_03 - v0.2
Autor: Ana Clara Lonczynski

Entrar com uma quantidade: -5

Apertar ENTER para continuar

*/

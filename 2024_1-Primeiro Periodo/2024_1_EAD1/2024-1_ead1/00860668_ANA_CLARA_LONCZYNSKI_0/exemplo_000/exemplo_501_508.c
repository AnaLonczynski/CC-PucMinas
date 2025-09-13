/*
// ------------------------------------ EXEMPLO501
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P1 ( void )
{
 printf ( "\n" );
 printf ( "\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS" );
 printf ( "\n" );
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA CHAMADA DE PROCEDIMENTO SEM PARAMETROS
 printf ( "EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
 P1 ( ); // chamada ao procedimento
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO

CHAMADO O PROCEDIMENTO P1 SEM PARAMETROS


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO502
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int X = 0; // VARIAVEL EM CONTEXTO GLOBAL
void P1 ( void )
{
printf ( "\n" );
printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
printf ( "\n" );
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
 printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
 for ( X = 1; X <= 5; X = X + 1 )
 P1 ( ); // chamar 5 vezes
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL


CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)


CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)


CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)


CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)


CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO503
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int X = 0; // VARIAVEL EM CONTEXTO GLOBAL
void P1 ( void )
{
 X = X + 1; // AVANCAR O CONTEXTO
 printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
 printf ( "\n" );
 if ( X < 5 )
 P1 ( ); // CHAMAR O PROCEDIMENTO RECURSIVAMENTE
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
 X = X - 1; // RETORNAR AO CONTEXTO ANTERIOR
 getchar ( ); // para esperar
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
 printf ( "EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
 X = 0;
 P1 ( ); // OBSERVAR A RECURSIVIDADE !
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL

CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO504
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P1 ( int X )
{
 printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
 if ( X < 5 )
 P1( X + 1 ); // chamar recursivamente com parametro
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
 getchar ( ); // para esperar
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
 printf ( "EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n" );
 P1 ( 1 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4
RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3
RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO505
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P1 ( int X )
{
 printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
 if ( X > 1 )
 P1 ( X - 1 );
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
 getchar ( ); // para esperar
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR VALOR
 printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
 P1 ( 5 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO506
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P2 (int X); // PROTOTIPO DE PROCEDIMENTO
void P1 (int X)
{
 printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
 if ( X < 5 )
 P2 ( X );
 printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ); // para esperar
} // fim do procedimento P1( )
void P2 (int X)
{
 printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
 X = X+1;
 printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ); // para esperar
 P1 ( X );
} // fim do procedimento P2( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
 printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
 P1 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P1 COM X = 1
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

CHAMADO O PROCEDIMENTO P1 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 2
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3

CHAMADO O PROCEDIMENTO P1 COM X = 3
CHAMADO O PROCEDIMENTO P2 COM X = 3
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 4

CHAMADO O PROCEDIMENTO P1 COM X = 4
CHAMADO O PROCEDIMENTO P2 COM X = 4
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 5

CHAMADO O PROCEDIMENTO P1 COM X = 5
RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 1



PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO507
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P1 ( int* X )
{
 *X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
 printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
 if ( *X < 5 )
 P1 ( X );
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
 *X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
 getchar ( ); // para esperar
} // fim procedimento P1( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
// VARIAVEL LOCAL
 int X;
 printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
 X = 0;
 P1 ( &X ); // OBSERVAR REPETICAO FINITA !
 printf ( "\n" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA

CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO508
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
void P2 ( int X ); // PROTOTIPO DE PROCEDIMENTO
void P1 ( int X )
{
 X = X + 1;
 printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
 if ( X < 4 )
 {
 P1 ( X );
 P2 ( X );
 }
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ) ; // para esperar
} // fim do procedimento P1( )
void P2 ( int X )
{
 printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
 if ( X > 1 )
 P2 ( X - 1 );
 printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
 getchar ( ); // para esperar
} // fim procedimento P2( )
int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
 printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
 P1 ( 1 );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS

CHAMADO O PROCEDIMENTO P1 COM X = 2
CHAMADO O PROCEDIMENTO P1 COM X = 3
CHAMADO O PROCEDIMENTO P1 COM X = 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4
2
CHAMADO O PROCEDIMENTO P2 COM X = 3
CHAMADO O PROCEDIMENTO P2 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 21
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3
RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3
2
CHAMADO O PROCEDIMENTO P2 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2


PRESSIONAR <Enter> PARA TERMINAR.
*/
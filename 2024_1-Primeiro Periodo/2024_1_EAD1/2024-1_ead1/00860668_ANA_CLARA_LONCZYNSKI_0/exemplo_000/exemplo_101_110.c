/*
// ------------------------------------ EXEMPLO101
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
int main ( )
{
 printf ( "EXEMPLO101 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
 return ( 0 );
} // fim do programa
*/
/*
EXEMPLO101 - PRIMEIRO EXEMPLO EM C
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO102
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
 system ( "cls" ); // (Windows) para limpar a tela
// system ( "clear" ); // (Linux ) para limpar a tela
 // (dependente do sistema operacional)
 printf ( "EXEMPLO102 - PRIMEIRO EXEMPLO EM C\n" );
 system ( "pause" ); // (Windows) para esperar
// getchar( ); // para esperar
 // (dependente do sistema operacional)
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO102 - PRIMEIRO EXEMPLO EM C
Pressione qualquer tecla para continuar. . . 
*/

/*
// ------------------------------------ EXEMPLO103
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
 void clrscr ( ) { system ( "cls" ); } // para Windows
// void clrscr ( ) { system ( "clear" ); } // para Linux
int main ( )
{
 clrscr ( ); // funcao para limpar a tela
 printf ( "EXEMPLO103 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n" ); // para mudar de linha
 printf ( "MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO103 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO104
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
 printf ( "EXEMPLO104 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n" ); // para mudar de linha (="\n")
 printf ( "MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\n" ); // para mudar de linha
 printf ( "PRESSIONAR <Enter> PARA TERMINAR. " );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO104 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO105
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
 printf ( "EXEMPLO105 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", 3.1415 ); // valor com parte fracionaria
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR. " );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO105 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.141500
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO106
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
#define PI 3.1415 // definicao de macro (nome para substituir valor)
int main ( )
{
 printf ( "EXEMPLO106 - PRIMEIRO EXEMPLO EM C " );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", PI ); // emprego de macro
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO106 - PRIMEIRO EXEMPLO EM C 
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.141500
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
// ------------------------------------ EXEMPLO107
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
// definicao de constante
 const float PI = 3.14; // com nome e tipo (melhor)
 printf ( "EXEMPLO107 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f" , PI ); // constante real
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO107 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/
/*
// ------------------------------------ EXEMPLO108
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
// definicao de constante
 const float PI = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
 float X = 10.01; // com atribuicao de valor inicial
 printf ( "EXEMPLO108 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", PI ); // constante real
 printf ( "\nREAL : %f", X ); // variavel real
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO108 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.140000
REAL : 10.010000
PRESSIONAR <Enter> PARA TERMINAR.
*/
/*
// ------------------------------------ EXEMPLO109
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
// definicao de constante
 const float PI = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
 float X = 10.01;
// definicao de variavel inteira
 int I = 10;
 printf ( "EXEMPLO109 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nINTEIRO : %i" , I );
 printf ( "\nREAL : %f" , X );
 printf ( "\nREAL : %f" , PI );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO109 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
INTEIRO : 10
REAL : 10.010000
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/
/*
// ------------------------------------ EXEMPLO110
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
int main ( )
{
// definicao de constante
 const double PI = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
 float X = 10.01;
// definicao de variavel inteira
 int I = 10;
// definicao de variavel caractere
 char N = '\n'; // mudar de linha
 printf ( "EXEMPLO110 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\nMATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI" );
 printf ( "%c%s", N, "EXEMPLOS DE VALORES : " );
 printf ( "%c%s%i" , N, "INTEIRO : " , I );
 printf ( "%c%s%f" , N, "REAL : " , X );
 printf ( "%c%s%lf", N, "REAL : " , PI );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 return ( EXIT_SUCCESS );
} // fim do programa
*/
/*
EXEMPLO110 - PRIMEIRO EXEMPLO EM C
MATRICULA: 00860668 ALUNO : ANA CLARA LONCZYNSKI
EXEMPLOS DE VALORES :
INTEIRO : 10
REAL : 10.010000
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/
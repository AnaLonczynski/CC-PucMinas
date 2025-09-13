/*
 Exemplo0209 - v0.9. - 07 / 03 / 2024
 Author: Ana Clara Lonczynski
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0200 exemplo0200.c
 Windows: gcc -o exemplo0200 exemplo0200.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0200
 Windows: exemplo0200
*/


// dependencias
#include "io.h" // bibliotecas e outras definicoes


/**
Method_01.
*/
void method_01 ( void )
{
    // definir dado
 int x = 0; // definir variavel com valor inicia
 // identificar
 IO_id ( "\nMethod_01 - Programa - v0.9" );
 // ler do teclado
x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 if ( x != 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 } // end if
 // encerrar
 IO_pause ( "\nApertar ENTER para continuar.\n" );
} // end method_01 ( )


/*
 Method_02.
*/
void method_02 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "\nMethod_02 - Programa - v0.9" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else // equivalente a "caso diferente do já' testado"
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )


/*
 Method_03.
*/
void method_03 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "\nMethod_03 - Programa - v0.9" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 if ( x > 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )


/*
 Method_04.
*/
void method_04 ( void )
{
// definir dado
 double x = 0.0; // definir variavel com valor inicial
// identificar
 IO_id ( "\nExemplo0209 - Programa - v0.9" );
// ler do teclado
 x = IO_readdouble ( "Entrar com um valor real: " );
// testar valor
 if ( 1.0 <= x && x <= 10.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
 if ( x < 1.0 )
 {
 IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
 }
 else
 {
 IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/*
 Method_05.
*/
void method_05 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "\nMethod_05 - Programa - v0.9" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ('a' <= x) && (x <= 'z') )
 {
 IO_printf ( "%s (%c)\n", "Letra minuscula", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
 if ( ('A' <= x) && (x <= 'Z') )
 {
 IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
 }
 else
 {
 if ( ('0' <= x) && (x <= '9') )
 {
 IO_printf ( "%s (%c)\n", "Algarismo", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
 } // end if
 } // end if
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/*
 Method_06.
*/
void method_06 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "\nMethod_06 - Programa - v0.9" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ( 'a' <= x && x <= 'z' )|| // minuscula OU
      ( 'A' <= x && x <= 'Z' ) ) // maiuscula
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 } // end if
   // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/*
 Method_07.
*/
void method_07 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "\nMethod_07 - Programa - v0.9" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
 if ( ! ( ( 'a' <= x && x <= 'z' ) || // NAO (minuscula OU
          ( 'A' <= x && x <= 'Z' ) ) ) // maiuscula)
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/*
 Method_08.
*/
void method_08 ( void )
{
// definir dado
 char x = '_'; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_08 - Programa - v0.9" );
// ler do teclado
 x = IO_readchar ( "Entrar com um caractere ['0','A','a']: " );
// testar valor
 switch ( x )
 {
 case '0':
 IO_printf ( "%s (%c=%d)\n", "Valor igual do simbolo zero", x, x );
 break;
 case 'A':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra A", x, x );
 break;
 case 'a':
 IO_printf ( "%s (%c=%d)\n", "Valor igual 'a letra a", x, x );
 break;
 default: // se nao alguma das opcoes anteriores
 IO_printf ( "%s (%c=%d)\n", "Valor diferente das opcoes ['0','A','a']", x, x );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/*
 Method_09.
*/
void method_09 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "Method_09 - Programa - v0.9" );
// ler do teclado
 x = IO_readint ( "Entrar com um inteiro [0,1,2,3]: " );
// testar valor
 switch ( x )
 {
 case 0:
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 break;
 case 1:
 IO_printf ( "%s (%d)\n", "Valor igual a um ", x );
 break;
 case 2:
 IO_printf ( "%s (%d)\n", "Valor igual a dois", x );
 break;
 case 3:
 IO_printf ( "%s (%d)\n", "Valor igual a tres", x );
 break;
 default: // se nao for alguma das opcoes anteriores
 IO_printf ( "%s (%d)\n", "Valor diferente das opcoes [0,1,2,3]", x );
 } // end switch
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( void )
{
// definir dado
 int opcao = 0;
// identificar
 printf ( "%s\n", "\nExemplo0209 - Programa = v0.9" );
 printf ( "%s\n", "Autor: Ana Clara Lonczynski" );
 printf ( "\n" ); // mudar de la
// acoes
// repetir
 do
 {
 // para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar"  );
 printf ( "\n%s" , "1 - Method_01" );
 printf ( "\n%s" , "2 - Method_02" );
 printf ( "\n%s" , "3 - Method_03" );
 printf ( "\n%s" , "4 - Method_04" );
 printf ( "\n%s" , "5 - Method_05" );
 printf ( "\n%s" , "6 - Method_06" );
 printf ( "\n%s" , "7 - Method_07" );
 printf ( "\n%s" , "8 - Method_08" );
 printf ( "\n%s" , "9 - Method_09" );
 printf ( "\n" );
 // ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
 // para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 // escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: /* nao fazer nada */ break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 default: // comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // end switch
 }
 while ( opcao != 0 );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
v0.0: Ocorreu problema para a biblioteca funcionar, tive que copiar o io.h de uma outra pasta. Ao reiniciar o programa de texto passou a funcionar.
v0.1: Após arrumar a biblioteca programa rodou sem erros.
v0.2: Necessidade de adicionar no menu a opcao de acessar ao metodo 2.
V0.3: OK.
v0.4: OK.
v0.5: OK.
v0.6: OK.
v0.7: OK.
v0.8: OK.
v0.9: OK.
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 06/03 esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de programa
0.2 02. ( OK )
0.3 03. ( OK )
0.4 04. ( OK )
0.5 05. ( OK )
0.6 06. ( OK )
0.7 07. ( OK )
0.8 08. ( OK )
0.9 09. ( OK )
*/
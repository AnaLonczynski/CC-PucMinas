/*
 Exemplo0001 - v0.0. - 23 / 02 / 2024
 Author: Ana Clara Lonczynski
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0001 exemplo0001.c
 Windows: gcc -o exemplo0001 exemplo0001.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0001
 Windows: exemplo0001
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ()
{
// definir dados / resultados
// identificar
 printf ( "%s\n", "Exemplo0001 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Ana Clara Lonczynski" );
 printf ( "\n" ); // mudar de linha
// acoes
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
V.01: Adicao de uma nova biblioteca
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.1 01. ( OK ) leitura e exibicao de inteiro
*/
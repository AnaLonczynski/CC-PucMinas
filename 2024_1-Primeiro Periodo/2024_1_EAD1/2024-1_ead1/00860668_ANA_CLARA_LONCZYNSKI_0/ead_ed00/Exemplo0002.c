/*
 Exemplo0002 - v0.0. - 23 / 02 / 2024
 Author: Ana Clara Lonczynski
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0002 exemplo0002.c
 Windows: gcc -o exemplo0002 exemplo0002.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0002
 Windows: exemplo0002
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
int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0002 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Ana Clara Lonczynski" );
 printf ( "\n" ); // mudar de linha
// acoes
//ler a opcao do teclado
printf ("\n%s","Opcao=");
scanf ("%d", &opcao);
getchar(); //para limpar a entrada de dados

//para mostrar a opcao lida
printf ("\n%s%d","Opcao =", opcao);
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
V.01: Adicao de uma nova biblioteca
v.02: Adicao de novas variaveis e acoes
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 24/02 esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de um programa
0.2 02. ( OK ) identificacao de um programa
               leitura e exibicao de inteiro
*/
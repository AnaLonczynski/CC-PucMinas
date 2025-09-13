/*
 Exemplo0004 - v0.0. - 23 / 02 / 2024
 Author: Ana Clara Lonczynski
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0004 exemplo0004.c
 Windows: gcc -o exemplo0004 exemplo0004.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0004
 Windows: exemplo0004
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

/**
Metodo 01.
*/
void method_01 (void)
{
    //identificar
    printf ("%s\n","    Metodo 01");

    //encerrar
} //end method_01
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
 printf ( "%s\n", "Exemplo0004 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Ana Clara Lonczynski" );
 printf ( "\n" ); // mudar de linha
// acoes

//para mostrar opcoes
printf ("\n%s\n","Opcoes:");
printf ("\n%s", "0 - Terminar");
printf ("\n%s"  ,"1 - Metodo 01");
printf ("\n");

//ler a opcao do teclado
printf ("\n%s","Opcao = ");
scanf ("%d", &opcao);
getchar(); //para limpar a entrada de dados

//para mostrar a opcao lida
printf ("\n%s%d","Opcao = ", opcao);

//escolher acao dependente da opcao
switch (opcao)
{
    case 0: //nao fazer nada
            break;
    case 1: //executar metodo 1
            method_01();
            break;
    default: //comportamento padrao
    printf ("\nERRO:Opcao invalida.\n");
break;
} //end switch

// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
V.01: Adicao de uma nova biblioteca
v.02: Adicao de novas variaveis e acoes
v.03: Adicao de switch 
v.04: Adicao de novas opcoes ao painel
---------------------------------------------- notas / observacoes / comentarios
v.04: necessidade de excluir o menu de "Aperte ENTER para continuar"do metodo 01 para não aparecer duas vezes
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
0.3 03. ( OK ) identificacao de programa
               leitura e exibicao mediante escolha
0.4 04. ( OK ) identificacao de programa
               leitura e exibicao mediante escolha              
*/
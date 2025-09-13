//1529723 - Ana Clara Lonczynski

/*
ler dois valores reais do teclado e dizer se o segundo é menor, igual ou maior que um terço do primeiro.
*/

#include <stdio.h>

int main ()
{
	int x = 0;
	int y = 0;
	
	printf  ("\n%s\n", "Exemplo0218 - Ana Clara Lonczynski");
	printf  ("%s"    , "\nFavor inserir um valor inteiro: ");
	scanf   ("%d", &x);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um segundo valor inteiro: ");
	scanf   ("%d", &y);
	getchar (        );
	
	x = x/3;
	
	if(y < x)
	{
		printf ("\n%d e menor que um terco do primeiro valor inserido", y);
	}
	
	if(y == x)
	{
		printf ("\n%d e igual a um terco do primeiro valor inserido ",  y);	
	}
	
	if(y > x)
	{
		printf("\n%d e maior que um terco do primeiro valor inserido",  y);
	}
}

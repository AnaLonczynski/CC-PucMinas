//1529723 - Ana Clara Lonczynski

/*
- ler um valor inteiro do teclado e 
- dados os intervalos [10:30] e (25:50), 
- dizer se pertence à interseção ou a apenas a um deles.
*/

#include <stdio.h>

int main ( )
{
	int x = 0;
	
	printf  ("\n%s\n", "Exemplo0215 - Ana Clara Lonczynski");
	printf  ("%s"    , "\nFavor inserir um valor inteiro: ");
	scanf   ("%d", &x);
	getchar (        );
	
	if((10 <= x && x <= 30) && (25 < x && x < 50) )
	{
		printf ("\n O valor %d pertence a intersecao de [10:30] e (25:50)", x);
	}
	else
	{
		if (10 <= x && x <= 30 )
		{
			printf ("\n O valor %d pertence ao intervalo fechado de [10:30] e nao atende ao intervalo de (25:50)", x);
		}
		if(25 < x && x < 50)
		{
			printf ("\n O valor %d pertence ao intervalo aberto de (25:50) e nao atende ao intervalo de [10:30]", x);
		}
		if(9 >= x || x >= 50 )
		{
			printf ("\n O valor %d nao atende a [10:30] nem a (25:50)", x);
		}
	}
	
	return 0;
}

//1529723 - Ana Clara Lonczynski

/*
- ler um valor inteiro do teclado e 
- dizer se pertence ao intervalo fechado entre [15:60].
*/

#include <stdio.h>

int main ( )
{
	
	int x = 0;
	printf  ("\n%s\n", "Exemplo0214 - Ana Clara Lonczynski");
	printf  ("%s",     "\nFavor inserir um valor inteiro: ");
	scanf   ("%d", &x);
	getchar (        );
	
	if(25 <= x && x <= 60)
	{
		printf ("\n O valor %d pertence ao intervalo fechado de [25:60] ", x);
	}
	else
	{
		printf ("\n O valor %d nao atende ao intervalo fechado de [25:60]", x);
	}

	return 0;
}

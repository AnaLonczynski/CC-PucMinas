//1529723 - Ana Clara Lonczynski

//- ler um valor inteiro do teclado e 
//- dizer se pertence ao intervalo aberto entre (35:65)


#include <stdio.h>

int main ( )
{
	int x = 0;
	printf  ("\n%s\n", "Exemplo0213 - Ana Clara Lonczynski");
	printf  ("\n%s"  , "Favor inserir um valor inteiro:  "   );
	scanf   ("%d"    ,  &x );
	getchar (  );

	if(35 < x && x < 65)
	{
		printf (" O valor %d pertence ao intervalo aberto de (35:65) ", x);
	}
	else
	{
		printf (" O valor %d nao pertence nao atende ao intervalo aberto de (35:65)", x);
	}
	
	
	
	return 0;
}


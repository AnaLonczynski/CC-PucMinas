//1529723 - Ana Clara Lonczynski

/*
ler dois valores inteiros do teclado e dizer se o primeiro é par e negativo, e se o segundo é ímpar e positivo.
*/

#include <stdio.h>

int main ( )
{
	int x = 0;
	int y = 0;
	
	printf  ("\n%s\n", "Exemplo0217 - Ana Clara Lonczynski");
	printf  ("%s"    , "\nFavor inserir um valor inteiro: ");
	scanf   ("%d", &x);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um segundo valor inteiro: ");
	scanf   ("%d", &y);
	getchar (        );
	
	if((x % 2 == 0 && x < 0)&&(y % 2 != 0 && x > 0))
	{
		printf(" O primeiro valor %d e negativo e par e o segundo valor %d e impar e positivo", x , y);
	}
	else
	{
		//printf("Os valores impressos nao atendem a condicao de o primeiro ser par e negativo enquanto o segundo e impar e positivo");
		if((x % 2 != 0 && x < 0) || (x % 2 != 0 && x > 0)|| (x % 2 == 0 && x > 0))
		{
			printf("\nO primeiro valor nao e par ou nao e negativo");
		}
		if((y % 2 == 0 && x > 0)||(y % 2 == 0 && x < 0)||(y % 2 != 0 && x < 0))
		{
			printf("\nO segundo valor nao e impar ou nao e positivo");
		}
		if ((x == 0 || y == 0) || (x == 0 && y == 0))
		{
			printf("Favor, inserir um valor diferente de 0");
		}
	}
}


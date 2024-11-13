//1529723 - Ana Clara Lonczynski
/*
ler dois valores inteiros do teclado e 
dizer se o primeiro é ímpar e o segundo é par
*/

#include <stdio.h>

int main ( )
{
	int x = 0;
	int y = 0;
	
	printf  ("\n%s\n", "Exemplo0216 - Ana Clara Lonczynski");
	printf  ("%s"    , "\nFavor inserir um valor inteiro: ");
	scanf   ("%d", &x);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um segundo valor inteiro: ");
	scanf   ("%d", &y);
	getchar (        );
	
		if(x % 2 != 0 && y % 2 ==0)
		{
			printf ("\n O primeiro valor %d e impar e %d e par.", x , y);
		
		}
		else
		{
		if(x % 2 != 0 && y % 2 != 0)
		{
			printf ("\n O primeiro valor %d e impar, mas o segundo valor %d nao e par.", x , y);
			
		}
		
		if(x % 2 == 0 && y % 2 == 0)
		{
			printf ("\n O segundo valor %d e par, mas o primeiro valor %d nao e impar.", y , x);
			
		}
		
		if(x % 2 == 0 && y % 2 !=0)
		{
			printf ("\n O primeiro valor %d e nao impar e o segundo valor %d e nao par.", x , y);
			
		} 
			
		}
	
	return 0;
}

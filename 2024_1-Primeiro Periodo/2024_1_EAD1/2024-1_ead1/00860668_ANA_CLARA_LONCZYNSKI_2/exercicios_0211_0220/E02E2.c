////1529723 - Ana Clara Lonczynski

/*
ler três valores literais (caracteres) do teclado e 
dizer se o primeiro valor lido está fora do intervalo definido pelos outros dois,
se esses forem diferentes entre si.
OBS.: Notar que não há garantias de ser o segundo menor que o terceiro.
*/

#include <stdio.h>

int main ( )
{
	char X;
	char Y;
	char Z;
	
	printf  ("\n%s\n", "Exemplo02E2 - Extra - Ana Clara Lonczynski");
	
	printf  ("%s"    , "\nFavor inserir um caractere para X: ");
	scanf   ("%c", &X);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um caractere para Y: " );
	scanf   ("%c", &Y);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um caractere para Z: ");
	scanf   ("%c", &Z);
	getchar (        );
	
	//dizer se o primeiro valor lido está fora do intervalo definido pelos outros dois
	
	if(Y == Z)
		{
			printf ("Y:%c e igual ao caractere Z:%c", Y, Z);
		}
		else
		{
			if(Y < X && X < Z)
			{
				printf("\n%c esta entre %c e %c", X, Y, Z);
			}
			else	
			{
				if(Z < X && X < Y)
				{
					printf("\n%c esta entre %c e %c", X, Z, Y);
				}
				else
				{
					printf("\n%c nao esta entre %c e %c", X, Y, Z);
				}	
			}
		}
	
	return 0;
}

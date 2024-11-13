////1529723 - Ana Clara Lonczynski

/*ler três valores literais (caracteres) do teclado e 
dizer se o primeiro valor lido está entre os outros dois, ou se é igual a um deles.*/

#include <stdio.h>
/*int main ()
{
	char Ch;
	printf("Digite uma tecla\n");
	Ch = getchar();
	printf ("O código ASCCI da tecla pressionada é %d\n",Ch);
	return (0); 
}*/

int main ( )
{
	char X;
	char Y;
	char Z;
	
	printf  ("\n%s\n", "Exemplo02E1 - Extra - Ana Clara Lonczynski");
	
	printf  ("%s"    , "\nFavor inserir um caractere para X: ");
	scanf   ("%c", &X);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um caractere para Y: " );
	scanf   ("%c", &Y);
	getchar (        );
	
	printf  ("%s"    , "\nFavor inserir um caractere para Z: ");
	scanf   ("%c", &Z);
	getchar (        );
	
	//dizer se o primeiro valor lido está entre os outros dois, ou se é igual a um deles.
	
	if(X == Y || X == Z )
	{
		printf("\n X: %c e igual a outro caractere.", X);
	}
	else
	{
		if(Y == Z)
		{
			printf ("\nY:%c e igual ao caractere Z:%c", Y, Z);
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
	}
	
	return 0;
}

//1529723 - Ana Clara Lonczynski

/*
ler três valores reais do teclado e dizer se o primeiro não está entre os dois últimos,
quando todos forem diferentes entre si.
*/

#include <stdio.h>

int main ()
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
	printf  ("\n%s\n", "Exemplo0220 - Ana Clara Lonczynski");
	
	printf  ("%s"    , "\nFavor inserir um valor real para X: ");
	scanf   ("%lf", &x);
	getchar (         );
	
	printf  ("%s"    , "\nFavor inserir um segundo valor real para Y: " );
	scanf   ("%lf", &y);
	getchar (         );
	
	printf  ("%s"    , "\nFavor inserir um terceiro valor real para Z: ");
	scanf   ("%lf", &z);
	getchar (         );
	
	//quando todos forem diferentes entre si
	
	while((y == z )||(x == y)||(x == z) ) 
	{
		printf	("\nERRO: ha valores inseridos sao iguais\n"        );
		
		printf  ("%s"    , "\nFavor inserir um valor real para X: ");
		scanf   ("%lf", &x);
		getchar (         );
		
		printf  ("%s"    , "\nFavor inserir um segundo valor real para Y: " );
		scanf   ("%lf", &y);
		getchar (         );
		
		printf  ("%s"    , "\nFavor inserir um terceiro valor real para Z: ");
		scanf   ("%lf", &z);
		getchar (         );
	}

	//dizer se o primeiro não está entre os dois últimos
	
	if(x < y && x < z)
	{
		printf("\n O valor %lf de X nao esta dentro do intervalo (%lf:%lf). ", x, y, z );	
	}
	else
	{
	if(x > z && x >  y)
	{
		printf("\n O valor %lf de X nao esta dentro do intervalo (%lf:%lf). ", x, z, y );
	}
	else
	{
		printf("\n O valor %lf de X esta dentro do intervalo (Y:Z) ", x);
	}
	}
	return 0;
}

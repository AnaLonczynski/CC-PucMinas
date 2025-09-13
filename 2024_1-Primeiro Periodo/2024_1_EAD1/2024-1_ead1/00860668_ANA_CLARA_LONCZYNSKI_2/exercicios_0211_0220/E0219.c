//1529723 - Ana Clara Lonczynski
/*
ler três valores reais do teclado e dizer se o primeiro está entre os dois últimos,
quando esses dois forem diferentes entre si.
OBS.: Notar a ordem dos testes.
(y<x<z)

*/

#include <stdio.h>

int main ()
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
	printf  ("\n%s\n", "Exemplo0219 - Ana Clara Lonczynski");
	
	printf  ("%s"    , "\nFavor inserir um valor real para X: ");
	scanf   ("%lf", &x);
	getchar (         );
	
	printf  ("%s"    , "\nFavor inserir um segundo valor real para Y: " );
	scanf   ("%lf", &y);
	getchar (         );
	
	printf  ("%s"    , "\nFavor inserir um terceiro valor real para Z: ");
	scanf   ("%lf", &z);
	getchar (         );
	
	while(y == z) 
	{
		printf	("\nERRO: valores inseridos para Y e Z sao iguais\n"        );
		
		printf  ("%s"    , "\nFavor inserir um segundo valor real para Y: " );
		scanf   ("%lf", &y);
		getchar (         );
		
		printf  ("%s"    , "\nFavor inserir um terceiro valor real para Z: ");
		scanf   ("%lf", &z);
		getchar (         );
	}
	
//dizer se o primeiro está entre os dois últimos
	
	if(y <= x && x <= z)
	{
		printf("\n X esta entre Y e Z: '%lf <= %lf <= %lf'", y , x , z);
	}
	else
	{
		if(z <= x && x <= y)
		{
		printf("\n X esta entre Z e Y: '%lf <= %lf <= %lf'", z , x , y);
		}
		
		if(x < y && x < z)
		{
		printf("\n O valor de X e menor que o intervalo" );	
		}
		
		if(x > z && x >  y)
		{
		printf("\n O valor de X e maior que o intervalo" );
		}
	}
}


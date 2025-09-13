/*
Exercio_0111 - 01/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

int main ()
{
int x = 0, y = 0, z = 0;

printf ("%s" , ("\nExercicio 0111 - Author: Ana Clara Lonczynski\n\n"));
printf ("%s" , "Inserir um valor para o lado de um quadrado: \n");
scanf ("%d" , &x);
getchar ();
while (x <=0)
{
    printf ("%s" , "\nERRO: condicao de existencia de um quadrado ferida. Favor inserir um valor positivo maior que 0.");
    printf ("%s" , "\nInsira um valor para o lado de um quadrado: ");
    scanf ("%d" , &x);   
}
z = (x*3)*(x*3);
printf ("\nUm quadradro com o triplo do seu lado tem a area: %d \n", z);
return 0;
}